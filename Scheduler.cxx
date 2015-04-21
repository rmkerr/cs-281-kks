#include "Scheduler.hxx"
#include <algorithm>

Scheduler::~Scheduler() {
    std::for_each(runningTasks.begin(),runningTasks.end(),[](Task*x){delete x;});
}

std::list<Task*>* Scheduler::getTaskQueue(){
    return &runningTasks;
}

//Set the schedule to be used
void Scheduler::setSchedule(Schedule* sch) {
    schedule = sch;
}

//Increment time passed, unload+log finished tasks
void Scheduler::updateTasks(int timestep) {
    for(int j = 0; j < timestep;++j) {
        
        blockedTasks.remove_if([&](Task* a){
            if(a->getBlockLength() == 0){
                runningTasks.push_back(a);
            }
            return a->getBlockLength() == 0;
        });

        //Reorder running tasks
        sortQueue();    

        //Run the first maxSimult tasks
        std::list<Task*>::const_iterator task = runningTasks.begin();
        for(uint i = 0; i < maxSimult && i < runningTasks.size();++i){
            if( (*task)->updateTask(time) ) { //Returns true if blocked
                blockedTasks.push_back(*task);
            }
            task++;
        }

        //Log and remove finished Tasks
        runningTasks.remove_if([&](Task* a){
            //adds Task to Logger queue if finished, then is removed from runningTasks.
            if(a->getFinished()){
                logTask(a);
            }

            return a->getFinished();
        });
    }
}

//Uses the Schedule strategy to order tasks
void Scheduler::sortQueue() {
    schedule->reorder();
}

void Scheduler::logTask(Task* task) {
    logger.addTask(task);
}
