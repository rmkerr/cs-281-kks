#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.hxx"
#include "Schedule.hxx"
#include "Logger.hxx"

class Scheduler
{
    public:
        Scheduler(Schedule*,size_t cores) : schedule(Schedule) {};
        ~Scheduler();

        std::queue<Task>* getTaskQueue();

        //Increment time passed, unload+log finished tasks
        void updateTasks(int timestep = 1);

        //Uses the Schedule strategy to order tasks
        void sortQueue();


    private:
        void logTask();

        size_t maxSimultaniousProcesses;//# of tasks to update simulataniously
        std::queue<Task> taskQueue;
        Schedule* schedule;
};

#endif // SCHEDULER_H