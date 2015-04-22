#include "Logger.hxx"


//Constructs an empty list of task pointers
Logger::Logger(std::string file) : taskList(), fileName_(file) {
    if(fileName_.compare("default") == 0) {
        verbose = true;
        output.open("default_output.txt");
    } else {
        output.open(fileName_);
        verbose = false;
    }


}


Logger::~Logger() {
std::for_each(taskList.begin(), taskList.end(), [&] (Task* ptr) {delete ptr;});
}


//Places new task pointer
void Logger::addTask(Task* task) {
    taskList.emplace_back(task);
}

void Logger::readTasks() {
    int stats[3]; //For average turnaround time[0] and response time[1] and if all finished before deadline [2]
    int count = 0;
    int sumTurnaroundTime = 0;
    int sumResponseTime = 0;
    int tasksFinished = 1; //will be set to 0 if one is not finished, depending on implementation may not be necessary


    if(taskList.size() > 0){
        std::for_each(taskList.begin(), taskList.end(), [&](Task* ptr) {
            //moving through list, send info about individual to console
            //track average average throughput, response time, and finish before deadline info to array


            output << "Task number " + std::to_string(ptr->getID()) + " finished ";

            if(ptr->getDeadline() < ptr->getTimeFinished()) {
                output << std::to_string(ptr->getTimeFinished() - ptr->getDeadline()) + " ticks after";
            } else if (ptr->getDeadline() == ptr->getTimeFinished()){
                output << "at";
            } else {
                output << std::to_string(ptr->getDeadline() - ptr->getTimeFinished()) + " ticks before";
            }

            output << " its deadline of " + std::to_string(ptr->getDeadline()) + " ." << std::endl;







            int turnaroundTime = ptr->getTimeFinished() - ptr->getSpawnTime();
            int responseTime = ptr->getTimeStarted() - ptr->getSpawnTime();

            output << "Turnaround Time: "  + std::to_string(turnaroundTime) << std::endl;
            output << "Response Time: " + std::to_string(responseTime) <<std::endl;
            output << std::endl;

            if(verbose){
                //Give number and the tick at which it finished
                std::cout << "Task number " + std::to_string(ptr->getID()) + " finished at "
                    + std::to_string(ptr->getTimeFinished()) << std::endl;

                std::cout << "The task took "  + std::to_string(turnaroundTime) + "ticks" << std::endl;

                //this section could have more info if we want, i.e. priority depending on our implementation of strategy

                std::cout << "" << std::endl;
            }





            sumTurnaroundTime += turnaroundTime;
            sumResponseTime += responseTime;

            count++;

        });

        int averageTurnaroundTime = sumTurnaroundTime/count;
        int averageResponseTime = sumResponseTime/count;

        stats[0] = averageTurnaroundTime;
        stats[1] = averageResponseTime;
        stats[2] = tasksFinished;

        if(verbose) {
            std::cout << "Average turnaround time: " + std::to_string(stats[0]) << std::endl;
            std::cout << "Average response time: " + std::to_string(stats[1]) << std::endl;
        }

        output << "All Tasks:" << std::endl;
        output << "Average Response Time: " + std::to_string(stats[0]) << std::endl;
        output << "Average Turnaround Time: " + std::to_string(stats[1]) << std::endl;


    }else {
        std::cout << "Task list is empty" << std::endl;
    }

}

void Logger::reportBlock(Task* task) {
    if(verbose) {
        std::cout << "Task " + std::to_string(task->getID()) + " blocked" << std::endl;
    }
    output << "Task " + std::to_string(task->getID()) + " blocked" << std::endl;

}

void Logger::reportUnblock(Task* task) {
    if(verbose) {
        std::cout << "Task " + std::to_string(task->getID()) + " unblocked" << std::endl;
    }
    output << "Task " + std::to_string(task->getID()) + " unblocked" << std::endl;

}

void Logger::reportFinish(Task* task) {
    if(verbose) {
        std::cout << "Task " + std::to_string(task->getID()) + " finished" << std::endl;
    }
    output << "Task " + std::to_string(task->getID()) + " finished" << std::endl;

}
