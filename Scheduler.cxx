#include "Scheduler.hxx"
#include <algorithm>

/**
 * Destructor. Deletes any tasks left on active queue
 */
Scheduler::~Scheduler() {
    std::for_each(runningTasks.begin(),runningTasks.end(),[](Task*x){delete x;});
}

/**
 * Returns task queue
 */
std::list<Task*>* Scheduler::getTaskQueue(){
    return &runningTasks;
}

/**
 * Returns blocked task queue
 */
std::list<Task*>* Scheduler::getBlockedQueue(){
    return &blockedTasks;
}

/**
 * Set the schedule to be used
 */
void Scheduler::setSchedule(Schedule* sch) {
    schedule = sch;
}

/**
 * Increment time passed, unload+log finished tasks
 */
void Scheduler::updateTasks(int timestep) {
    for(int j = 0; j < timestep;++j) {

        //Decrement timers on blocked tasks
        std::for_each(blockedTasks.begin(),blockedTasks.end(),[&](Task* a){
            a->updateTask(time);
        });

        //Reorder running tasks
        sortQueue();

        //Run the first maxSimult tasks
        std::list<Task*>::const_iterator task = runningTasks.begin();
        for(uint i = 0; i < maxSimult && i < runningTasks.size();++i){
            if( (*task)->updateTask(time) && !(*task)->getFinished()) { //Returns true if blocked
                blockedTasks.push_back(*task);
                logger.reportBlock(*task);
            }
            task++;
        }

        //Unblock tasks finished with "IO"
        blockedTasks.remove_if([&](Task* a){
            if(a->getBlockRemaining() <= 0){
                runningTasks.push_back(a);
                logger.reportUnblock(a);
                return true;
            }
            return false;
        });

        //Log and remove finished Tasks
        runningTasks.remove_if([&](Task* a){
            //adds Task to Logger queue if finished, then is removed from runningTasks.
            if(a->getFinished()){
                logTask(a);
                logger.reportFinish(a);
            }

            return a->getFinished() || a->getBlockRemaining();
        });
        ++time;
    }
}

/**
 * Uses the Schedule strategy to order tasks
 */
void Scheduler::sortQueue() {
    schedule->reorder();
}

/**
 * Sends a task to the Logger
 */
void Scheduler::logTask(Task* task) {
    logger.addTask(task);
}

/**
 * Calls the logger to read all finished tasks
 */
void Scheduler::logOutput(){
    logger.readTasks();
}
