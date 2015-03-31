#ifndef LOGGER_H
#define LOGGER_H

#include "Task.hxx"

class Logger
{
    public:
        Logger();
        ~Logger();
        readTask(Task* task);

    private:
        std::queue<Task>* taskQueue;

};

#endif
