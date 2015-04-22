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
        Logger(std::string, bool);
        ~Logger();
        void addTask(Task* task);
        void readTasks();
        void reportBlock(Task* task);
        void reportUnblock(Task* task);
        void reportFinish(Task* task);

    private:
        std::list<Task*> taskList;

        std::ofstream output;
        std::string fileName_;
        bool verbose;

};

#endif
