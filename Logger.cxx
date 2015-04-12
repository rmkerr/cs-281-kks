#include "Logger.hxx"
#include <iostream>
#include <string>
#include <algorithm>

//Constructs an empty list of task pointers
Logger::Logger() : taskList() {}


Logger::~Logger() {}


//Places new task pointer
void Logger::addTask(Task* task) {
    taskList.emplace_back(task);
}

int[] Logger::readTasks() {
    int toReturn [3]; //For average turnaround time[0] and response time[1] and if all finished before deadline [2]
    int count = 0;
    int sumTurnaroundTime = 0;
    int sumResponseTime = 0;
    int tasksFinished = 1; //will be set to 0 if one is not finished, depending on implementation may not be necessary


    if(taskList.emp > 0){
        std::for_each(taskList.begin(), taskList.end(), [&](Task* ptr) {
            //moving through list, send info about individual to console
            //track average average throughput, response time, and finish before deadline info to array

            if(!ptr->getFinsihed()) {
                tasksFinished = 0;
            }

            int turnaroundTime = ptr->getTimeFinished() - ptr->getSpawnTime();
            int responseTime = ptr->getTimeStarted() - ptr->getSpawnTime();
            //Give number and the tick at which it finished
            std::cout << "Task number " + std::to_string(count) + " finished at "
                + std::to_string(ptr->getTimeFinished()) << std::endl;

            std::cout << "The task took "  + std::to_string(turnaroundTime) + "ticks" << std::endl;

            //this section could have more info if we want, i.e. priority depending on our implementation of strategy

            std::cout << "" << std::endl;


            sumTurnaroundTime += turnaroundTime;
            sumResponseTime += responseTime;

            count++;

        });

        int averageTurnaroundTime = sumTurnaroundTime/count;
        int averageResponseTime = sumResponseTime/count;

        toReturn[0] = averageTurnaroundTime;
        toReturn[1] = averageResponseTime;
        toReturn[2] = tasksFinished;

    }else {
        std::cout << "Task list is empty" << std::endl;
    }


}
