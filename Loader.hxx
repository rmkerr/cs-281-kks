#ifndef LOADER_H
#define LOADER_H

#include "Task.hxx"

#include <list>
#include <queue>
#include <string>

class Loader
{
    public:
        Loader(std::queue<Task*>*, std::string fileName);
        ~Loader();

        void update(int time);

    private:
        std::queue<Task*>* loadedTasks;
        std::list<Task*>   unloadedTasks;

};

#endif
