#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.hxx"
#include "Schedule.hxx"
#include "Logger.hxx"

class Scheduler
{
    public:
        Scheduler();
        ~Scheduler();
        std::queue<Task> getTaskQueue();
        void updateTasks(int timestep = 1);
        void sortQueue();


    private:
        void logTask();

        std::queue<Task> taskQueue;
        Schedule* schedule;
};

#endif // SCHEDULER_H
