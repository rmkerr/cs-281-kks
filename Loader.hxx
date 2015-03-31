#ifndef LOADER_H
#define LOADER_H

#include "Task.hxx"

class Loader
{
    public:
        Loader();
        ~Loader();
        addTask(Task* task);

    private:
        std::queue<Task>* taskQueue;

};

#endif
