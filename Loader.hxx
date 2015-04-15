#ifndef LOADER_H
#define LOADER_H

#include "Task.hxx"

class Loader
{
    public:
        Loader(std::queue<Task*>*, std::string fileName);
        ~Loader();

        void update();

    private:
        std::queue<Task*>* loadedTasks;
        std::list<Task*>   unloadedTasks;

};

#endif
