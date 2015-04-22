#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.hxx"
#include "Schedule.hxx"
#include "Logger.hxx"

class Scheduler
{
    public:
        Scheduler(unsigned int cores, bool verbose, std::string file) : maxSimult(cores), time(0), logger(file, verbose) {};

        ~Scheduler();

        std::list<Task*>* getTaskQueue();
        std::list<Task*>* getBlockedQueue();

        //Set the schedule to be used
        void setSchedule(Schedule* sch);

        //Increment time passed, unload+log finished tasks
        void updateTasks(int timestep = 1);

        //Uses the Schedule strategy to order tasks
        void sortQueue();

        //Print logged data
        void logOutput();
    private:
        void logTask(Task* task);

        unsigned int maxSimult;//# of tasks to update simultaneously
        unsigned long time;
        std::list<Task*> runningTasks;
        std::list<Task*> blockedTasks;
        Schedule* schedule;
        Logger logger;
};

#endif // SCHEDULER_H
