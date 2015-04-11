#include "Logger.hxx"
#include <iostream>

//Constructs an empty list of task pointers
Logger::~Logger() : taskList() {}

//Places new task pointer
void Logger::addTask(Task* task) {
    taskList.emplace_back(task);
}

int[] Logger::readTasks() {
    int toReturn [3]; //For average throughput[0] and response time[1] and if all finished before deadline [2]

    std::for_each(taskList.begin(), taskList.end(), [taskList](Task* ptr) {
        //moving through list, send info about individual to console
        //track average average throughput, response time, and finish before deadline info to array
    });
}
