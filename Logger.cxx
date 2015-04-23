#include "Logger.hxx"

/**
 * Constructor
 */
Logger::Logger(bool verbose_) : taskList(), verbose(verbose_) {
}


/**
 * Destructor
 * Logger in charge of cleaning up finished tasks
 */
Logger::~Logger() {
std::for_each(taskList.begin(), taskList.end(), [&] (Task* ptr) {delete ptr;});
}


/**
 * Adds a finished task to the list
 */
void Logger::addTask(Task* task) {
    taskList.emplace_back(task);
}

/**
 * Cycles through logged tasks and reads
 * reporting turnaround time and response time
 */
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

            std::cout << "\nTask number " + std::to_string(ptr->getID()) + " finished ";

            if(ptr->getDeadline() < ptr->getTimeFinished()) {
                std::cout << std::to_string(ptr->getTimeFinished() - ptr->getDeadline()) + " ticks after";
            } else if (ptr->getDeadline() == ptr->getTimeFinished()){
                std::cout << "at";
            } else {
                std::cout << std::to_string(ptr->getDeadline() - ptr->getTimeFinished()) + " ticks before";
            }

            std::cout << " its deadline of " + std::to_string(ptr->getDeadline()) + " ." << std::endl;



            int turnaroundTime = ptr->getTimeFinished() - ptr->getSpawnTime();
            int responseTime = ptr->getTimeStarted() - ptr->getSpawnTime();

            std::cout << "Turnaround Time: "  + std::to_string(turnaroundTime) << std::endl;
            std::cout << "Response Time: " + std::to_string(responseTime) <<std::endl;
            std::cout << std::endl;

            sumTurnaroundTime += turnaroundTime;
            sumResponseTime += responseTime;

            count++;

        });

        int averageTurnaroundTime = sumTurnaroundTime/count;
        int averageResponseTime = sumResponseTime/count;

        stats[0] = averageTurnaroundTime;
        stats[1] = averageResponseTime;
        stats[2] = tasksFinished;

        std::cout << "All Tasks:" << std::endl;
        std::cout << "Average Response Time: " + std::to_string(stats[0]) << std::endl;
        std::cout << "Average Turnaround Time: " + std::to_string(stats[1]) << std::endl;


    }else {
        std::cout << "Task list is empty" << std::endl;
    }

}

/**
 * Reports a task is blocking
 */
void Logger::reportBlock(Task* task) {
    if(verbose) {
        std::cout << "Task " + std::to_string(task->getID()) + " blocked" << std::endl;
    }
    std::cout << "Task " + std::to_string(task->getID()) + " blocked" << std::endl;

}

/**
 * Reports a task is unblocking
 */
void Logger::reportUnblock(Task* task) {
    if(verbose) {
        std::cout << "Task " + std::to_string(task->getID()) + " unblocked" << std::endl;
    }
    std::cout << "Task " + std::to_string(task->getID()) + " unblocked" << std::endl;

}

/**
 * Reports a task is finishing
 */
void Logger::reportFinish(Task* task) {
    if(verbose) {
        std::cout << "Task " + std::to_string(task->getID()) + " finished" << std::endl;
    }
    std::cout << "Task " + std::to_string(task->getID()) + " finished" << std::endl;

}
