#include "Scheduler"
#include <algorithm>

Scheduler::~Scheduler() {
    std::for_each(taskQueue.begin().taskQueue.end(),[](Task*x){delete x;});
}

std::queue<Task>* Scheduler::getTaskQueue(){
    return &taskQueue;
}

//Set the schedule to be used
void Scheduler::setSchedule(Schedule* sch) {
    schedule = sch;
}

//Increment time passed, unload+log finished tasks
void Scheduler::updateTasks(int timestep = 1) {

}

//Uses the Schedule strategy to order tasks
void sortQueue();


private:
void logTask();

size_t maxSimultaniousProcesses;//# of tasks to update simulataniously
std::queue<Task> taskQueue;
Schedule* schedule;