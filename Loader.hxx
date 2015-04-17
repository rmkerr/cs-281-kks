#ifndef LOADER_H
#define LOADER_H

#include "Task.hxx"

#include <list>
#include <string>

class Loader
{
    public:
        Loader(std::list<Task*>*, std::string fileName);
        ~Loader();

        void update(int time);

    private:
        std::list<Task*>* loadedTasks;
        std::list<Task*>   unloadedTasks;

};

#endif
