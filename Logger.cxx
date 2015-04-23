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
        taskList.sort([](Task* a, Task* b) {
            return a->getID() < b->getID();
        });
        std::for_each(taskList.begin(), taskList.end(), [&](Task* ptr) {
            //moving through list, send info about individual to console
            //track average average throughput, response time, and finish before deadline info to array

            std::cout << "\nTask number " << ptr->getID();
            if ( ptr->getTimeRemaining() != 0 ) {
                std::cout << " stopped with " << ptr->getTimeRemaining() << " ticks remaining at";
            } else if(ptr->getDeadline() < ptr->getTimeFinished()) {
                std::cout << " finished " << ptr->getTimeFinished() - ptr->getDeadline() << " ticks after";
            } else if (ptr->getDeadline() == ptr->getTimeFinished()){
                std::cout << " finished at";
            } else {
                std::cout << " finished " << ptr->getDeadline() - ptr->getTimeFinished() << " ticks before";
            }

            std::cout << " its deadline of " << ptr->getDeadline() << "." << std::endl;



            int turnaroundTime = ptr->getTimeFinished() - ptr->getSpawnTime();
            int responseTime = ptr->getTimeStarted() - ptr->getSpawnTime();

            if ( ptr->getTimeRemaining() == 0 ) {
                std::cout << "\tTurnaround Time: " << turnaroundTime << std::endl;
                sumTurnaroundTime += turnaroundTime;
            } else {
                std::cout << "\tTurnaround Time: Failed to meet deadline."<<std::endl;
            }
            std::cout << "\tResponse Time: " << responseTime << std::endl;
            sumResponseTime += responseTime;

            count++;

        });

        int averageTurnaroundTime = sumTurnaroundTime/count;
        int averageResponseTime = sumResponseTime/count;

        stats[0] = averageTurnaroundTime;
        stats[1] = averageResponseTime;
        stats[2] = tasksFinished;

        std::cout << "All Tasks:" << std::endl;
        std::cout << "\tAverage Response Time: " + std::to_string(stats[0]) << std::endl;
        std::cout << "\tAverage Turnaround Time: " + std::to_string(stats[1]) << std::endl;


    }else {
        std::cout << "Task list is empty" << std::endl;
    }

}

/**
 * Reports a task is blocking
 */
void Logger::reportBlock(Task* task) {
    if(verbose){
        std::cout << "\tTask " + std::to_string(task->getID()) + " blocked" << std::endl;
    }
}

/**
 * Reports a task is unblocking
 */
void Logger::reportUnblock(Task* task) {
    if(verbose){
        std::cout << "\tTask " + std::to_string(task->getID()) + " unblocked" << std::endl;
    }
}

/**
 * Reports a task is finishing
 */
void Logger::reportFinish(Task* task) {
    if(verbose){
        std::cout << "\tTask " + std::to_string(task->getID()) + " finished" << std::endl;
    }
}

/**
* If in verbose mode, writes out which tasks have run
*/
void Logger::reportRun(Task* task) {
    if(verbose){
        std::cout << "\tRunning task " << task->getID() << std::endl;
    }
}

/**
* If in verbose mode, writes out the current time
*/
void Logger::reportStep(int time) {
    if(verbose){
        std::cout<<"Step #"<<time<<std::endl;
    }
}