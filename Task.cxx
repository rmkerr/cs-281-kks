#include <iostream>
#include "Task.hxx"
int Task::taskIdGen = 1;

/**
 * Default Constructor
 */
Task::Task() : deadline_(), timeRemaining_(), priority_(), spawnTime_(),
    timeStarted_(), timeFinished_(), finished_(false), firstRun_(false), blockPeriod_(), lengthBlock_(0), taskID(taskIdGen++) {}

/**
 * Alternative ctor
 */
Task::Task(int length, int timeSpawned, int deadline, int priority, int blockPeriod, int blockLength) :
    deadline_(deadline), timeRemaining_(length), priority_(priority),
    spawnTime_(timeSpawned), timeStarted_(), timeFinished_(), finished_(false), firstRun_(false),
    blockPeriod_(blockPeriod), lengthBlock_(blockLength),blockRemaining_(0), timeLastRun_(0), taskID(taskIdGen++) {}

/**
 * Destructor
 */
Task::~Task() {}

/**
 * Updates task based on current time
 * checks if task is blocked, if not advanced a step
 * @return whether the task is blocked post advance
 */
bool Task::updateTask(int curTime) {

        if(getBlockRemaining() > 0) {
            setBlockRemaining(getBlockRemaining() - 1);
        }else {
            setTimeLastRun(curTime);
            if(!getFirstRun()){
                setFirstRun();
                setTimeStarted(curTime);
            }

            setTimeRemaining(getTimeRemaining() - 1);

            //Checks finished
            if(getTimeRemaining() == 0) {
                setTimeFinished(curTime + 1);
                setFinished(true);
            }

            //Checks if time for block post update to avoid infinitely blocking
            if(getBlockPeriod() != 0) {
                if(!(getTimeRemaining() % getBlockPeriod())){
                    setBlockRemaining(getBlockLength());                 //block length set arbitrarily at 10
                }
            }
        }
//    //Priority update, probably call to strategy


    return getBlockRemaining() > 0;        //will return true until updated post block
}

//Getters

/**
 * Returns ID
 */
int Task::getID() {
    return taskID;
}

/**
 * Returns task deadline
 */
int Task::getDeadline(){
    return deadline_;
}

/**
 * Returns time remaining for task
 */
int Task::getTimeRemaining(){
    return timeRemaining_;
}

/**
 * Returns priority of task
 */
int Task::getPriority(){
    return priority_;
}

/**
 * Returns time task spawned
 */
int Task::getSpawnTime(){
    return spawnTime_;
}

/**
 * Returns time task started
 */
int Task::getTimeStarted(){
    return timeStarted_;
}

/**
 * Returns time task finished
 */
int Task::getTimeFinished(){
    return timeFinished_;
}

/**
 * Returns if task is finished
 */
bool Task::getFinished() {
    return finished_;
}

/**
 * Returns if task has run for first time
 */
bool Task::getFirstRun() {
    return firstRun_;
}

/**
 * Returns block period
 */
int Task::getBlockPeriod() {
    return blockPeriod_;
}

/**
 * Returns block length
 */
int Task::getBlockLength() {
    return lengthBlock_;
}

/**
 * Returns time blocked remaining
 */
int Task::getBlockRemaining() {
    return blockRemaining_;
}

/**
 * Returns Last Run time
 */
int Task::getTimeLastRun() {
    return timeLastRun_;
}


//Setters

/**
 * Sets task ID
 */
void Task::setID(int ID) {
    taskID = ID;
}

/**
 * Sets task deadline
 */
void Task::setDeadline(int deadline) {
    deadline_ = deadline;
}

/**
 * Sets task time remaining
 */
void Task::setTimeRemaining(int time) {
    timeRemaining_ = time;
}

/**
 * Sets task priority
 */
void Task::setPriority(int priority) {
    priority_ = priority;
}

/**
 * Sets task time spawned
 */
void Task::setTimeSpawned(int time) {
    spawnTime_ = time;
}

/**
 * Sets task time started
 */
void Task::setTimeStarted(int time) {
    timeStarted_ = time;
}

/**
 * Sets task time finished
 */
void Task::setTimeFinished(int time) {
    timeFinished_ = time;
}

/**
 * Sets task finished
 */
void Task::setFinished(bool finished) {
    finished_ = finished;
}

/**
 * Sets task first run
 */
void Task::setFirstRun() {
    firstRun_ = true;
}

/**
 * Sets task block period
 */
void Task::setBlockPeriod(int period) {
    blockPeriod_ = period;
}

/**
 * Sets task block length
 */
void Task::setBlockLength(int length) {
    lengthBlock_ = length;
}

/**
 * Sets task block time remaining
 */
void Task::setBlockRemaining(int time) {
    blockRemaining_ = time;
}

/**
 * Sets task time last run
 */
void Task::setTimeLastRun(int time) {
    timeLastRun_ = time;
}
