#include "Scheduler"
#include <algorithm>

Scheduler::~Scheduler() {
    std::for_each(taskQueue.begin().taskQueue.end(),[](Task*x){delete x;});
}

std::list<Task>* Scheduler::getTaskQueue(){
    return &taskQueue;
}

//Set the schedule to be used
void Scheduler::setSchedule(Schedule* sch) {
    schedule = sch;
}

//Increment time passed, unload+log finished tasks
void Scheduler::updateTasks(int timestep = 1) {
    for(int j = 0; j < timestep;++j) {
        sortQueue();
        auto task = taskQueue.begin();
        for(int i = 0; i < maxSimult && i < taskQueue.size();++i){
            (*task)->updateTask(time);
            task++;
        }
        taskQueue.remove_if([](Task* a){return a.getFinished();});
    }
}

//Uses the Schedule strategy to order tasks
void sortQueue() {
    schedule->reorder();
}

void logTask();
