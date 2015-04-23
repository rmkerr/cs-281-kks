#ifndef LOADER_H
#define LOADER_H

#include "Task.hxx"

#include <list>
#include <string>
/**
 * Loader class declaration
 * @author Richard Kerr
 * @author Dillon Koval
 *
 */
class Loader
{
    public:

        /**
         * Constructor takes pointer to task list and a file
         *  containing information about tasks
         * Constructs list of unloaded tasks according to input
         */
        Loader(std::list<Task*>*, std::string fileName);

        /**
         * Destructor
         */
        ~Loader();

        /**
         * Checks for tasks to be loaded and moves them from unloaded
         * to loaded lists
         */
        void update(int time);

    private:
        std::list<Task*>* loadedTasks;
        std::list<Task*>   unloadedTasks;

};

#endif
