#ifndef LOGGER_H
#define LOGGER_H

#include "Task.hxx"
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
class Logger
{
    public:
        Logger(std::string fileName = "output.txt");
        ~Logger();
        void addTask(Task* task);
        void readTasks();

    private:
        std::list<Task*> taskList;
        std::string fileName_;


};

#endif
