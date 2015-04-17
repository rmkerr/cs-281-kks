#include "Scheduler.hxx"
#include <algorithm>

Scheduler::~Scheduler() {
    std::for_each(taskQueue.begin(),taskQueue.end(),[](Task*x){delete x;});
}

std::list<Task*>* Scheduler::getTaskQueue(){
    return &taskQueue;
}

//Set the schedule to be used
void Scheduler::setSchedule(Schedule* sch) {
    schedule = sch;
}

//Increment time passed, unload+log finished tasks
void Scheduler::updateTasks(int timestep) {
    for(int j = 0; j < timestep;++j) {
        sortQueue();
        std::list<Task*>::const_iterator task = taskQueue.begin();
        for(uint i = 0; i < maxSimult && i < taskQueue.size();++i){
            (*task)->updateTask(time);
            task++;
        }
        taskQueue.remove_if([](Task* a){return a->getFinished();});
    }
}

//Uses the Schedule strategy to order tasks
void Scheduler::sortQueue() {
    schedule->reorder();
}

void Scheduler::logTask() {};
