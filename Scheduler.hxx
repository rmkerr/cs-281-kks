#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.hxx"
#include "Schedule.hxx"
#include "Logger.hxx"

class Scheduler
{
    public:
        Scheduler(size_t cores) : maxSimultaniousProcesses(cores) {};

        ~Scheduler();

        std::queue<Task>* getTaskQueue();

        //Set the schedule to be used
        void setSchedule(Schedule* sch) {

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