#ifndef LOGGER_H
#define LOGGER_H

#include "Task.hxx"

class Logger
{
    public:
        Logger();
        ~Logger();
        void addTask(Task* task);
        int[] readTasks();

    private:
        std::queue<Task>* taskList;

};

#endif
