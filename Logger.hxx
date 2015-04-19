#ifndef LOGGER_H
#define LOGGER_H

#include "Task.hxx"
#include <list>

class Logger
{
    public:
        Logger();
        ~Logger();
        void addTask(Task* task);
        void readTasks();

    private:
        std::list<Task*> taskList;

};

#endif
