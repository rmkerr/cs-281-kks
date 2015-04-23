#ifndef LOGGER_H
#define LOGGER_H

#include "Task.hxx"
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
/**
 * Logger class declaration
 * @author Richard Kerr
 * @author Dillon Koval
 */
class Logger
{
    public:
        /**
         * Constructor
         * @param output file, verbose boolean
         * Opens output file if applicable
         */
        Logger(std::string, bool);

        /**
         * Destructor
         */
        ~Logger();

        /**
         * Adds a finished task to the tasklist
         */
        void addTask(Task* task);

        /**
         * Writes pertinent information about task to output file
         */
        void readTasks();

        /**
         * Reports a task blocking
         */
        void reportBlock(Task* task);

        /**
         * Reports a task unblocking
         */
        void reportUnblock(Task* task);

        /**
         * Reports a task finishing
         */
        void reportFinish(Task* task);

    private:
        std::list<Task*> taskList;

        std::ofstream output;
        std::string fileName_;
        bool verbose;

};

#endif
