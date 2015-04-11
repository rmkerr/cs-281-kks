#ifndef LOADER_H
#define LOADER_H

#include "Task.hxx"

class Loader
{
    public:

        Loader(std::queue<Task*>*);
        ~Loader();
        void addTask(Task* task);


    private:
        std::list<Task*> taskQueue;

};

#endif
