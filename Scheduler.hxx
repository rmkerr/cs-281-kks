#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.hxx"
#include "Schedule.hxx"
#include "Logger.hxx"

/**
 * Scheduler declaration
 * @author Richard Kerr
 * @author Dillon Koval
 * Manages active tasks, updates as needed
 * Determines which task runs
 */

class Scheduler
{
    public:
        /**
         * Scheduler constructor
         */
        Scheduler(unsigned int cores, bool verbose) : maxSimult(cores), time(0), logger(verbose) {};

        /**
         * Destructor
         */
        ~Scheduler();

        /**
         * Returns task queue
         */
        std::list<Task*>* getTaskQueue();

        /**
         * Returns blocked task queue
         */
        std::list<Task*>* getBlockedQueue();

        /**
         * Set the schedule to be used
         */
        void setSchedule(Schedule* sch);

        /**
         * Increment time passed, unload+log finished tasks
         */
        void updateTasks(int timestep = 1);

        /**
         * Uses the Schedule strategy to order tasks
         */
        void sortQueue();

        /**
         * Print logged data
         */
        void logOutput();
    private:
        void logTask(Task* task);

        unsigned int maxSimult;//# of tasks to update simultaneously
        int time;
        std::list<Task*> runningTasks;
        std::list<Task*> blockedTasks;
        Schedule* schedule;
        Logger logger;
};

#endif // SCHEDULER_H
