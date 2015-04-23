#include "Scheduler.hxx"
#include "Loader.hxx"
#include <list>
#include <iostream>
#include <string>
#include <boost/program_options/option.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>



namespace po = boost::program_options;
po::variables_map vm;

//int Task::taskIdGen = 1;

int main(int argc, char **argv) {

    // Parse program options
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "Produce this help message")
        ("strategy,s", po::value<std::string>(), "Scheduling strategy. Valid values are rr, edf, priority, sjf, and fifo")
        ("cores,c", po::value<int>(), "Number of parallel virtual \"tasks\" to run")
        ("input-file,i", po::value<std::string>(), "Input file with list of tasks")
        ("output-file,o", po::value<std::string>(), "Output file.  Default: standard output")
        ("verbose,v", "Verbose enables output to console")
        ;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 0;
    }

    std::string output;
    if (vm.count ("output-file")) {
        output = vm["output-file"].as<std::string>();
    } else {
        output = "default";
    }

    int cores = 1;
    if (vm.count("cores")) {
        cores=vm["cores"].as <int> ();
    }

    bool verbose = false;

    if(vm.count("verbose")) {
        verbose = true;
    }

    Schedule* schedule = NULL;
    Scheduler scheduler(cores, verbose, output);

    if (!vm.count ("strategy")) {
        schedule = new Schedule(scheduler.getTaskQueue());
    }else{
        std::string strategy=vm["strategy"].as < std::string > ();
        if(strategy=="rr"){
            schedule = new RR_Schedule(scheduler.getTaskQueue());
        }else if(strategy=="edf"){
            schedule = new EDF_Schedule(scheduler.getTaskQueue());
        }else if(strategy=="priority"){
            schedule = new Priority_Schedule(scheduler.getTaskQueue());
        }else if(strategy=="sjf"){
            schedule = new SJF_Schedule(scheduler.getTaskQueue());
        }else if(strategy=="fifo"){
            schedule = new Schedule(scheduler.getTaskQueue());
        }
    }
    if(schedule == NULL) {
        std::cerr<<"Invalid strategy provided. Terminating program...\n";
        return -1;
    }

    if (!vm.count ("input-file")) {
        std::cerr<<"No input file provided. Terminating program...\n";
        return -1;
    }




    std::string inFile=vm["input-file"].as < std::string > ();

    scheduler.setSchedule(schedule);

    Loader loader(scheduler.getTaskQueue(),inFile);
    for(int i = 0;scheduler.getTaskQueue()->size()||scheduler.getBlockedQueue()->size()||i<5;i++) {
        scheduler.updateTasks(1);
        loader.update(i);
    }
    scheduler.logOutput();

    return 0;
}
