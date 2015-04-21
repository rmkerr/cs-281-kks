#include <iostream>
#include "Task.hxx"

Task::Task() : deadline_(), timeRemaining_(), priority_(), spawnTime_(),
    timeStarted_(), timeFinished_(), finished_(false), firstRun_(false), blockPeriod_(), lengthBlock_(0) {}

Task::Task(int length, int timeSpawned, int deadline, int priority, int blockPeriod, int blockLength) :
    deadline_(deadline), timeRemaining_(length), priority_(priority),
    spawnTime_(timeSpawned), timeStarted_(), timeFinished_(), finished_(false), firstRun_(false),
    blockPeriod_(blockPeriod), lengthBlock_(blockLength),blockRemaining_(0) {}

Task::~Task() {}

bool Task::updateTask(int curTime) {

        if(getBlockRemaining() > 0) {
            setBlockRemaining(getBlockRemaining() - 1);
        }else {

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

int Task::getDeadline(){
    return deadline_;
}

int Task::getTimeRemaining(){
    return timeRemaining_;
}

int Task::getPriority(){
    return priority_;
}

int Task::getSpawnTime(){
    return spawnTime_;
}

int Task::getTimeStarted(){
    return timeStarted_;
}

int Task::getTimeFinished(){
    return timeFinished_;
}

bool Task::getFinished() {
    return finished_;
}

bool Task::getFirstRun() {
    return firstRun_;
}

int Task::getBlockPeriod() {
    return blockPeriod_;
}

int Task::getBlockLength() {
    return lengthBlock_;
}

int Task::getBlockRemaining() {
    return blockRemaining_;
}

//Setters

void Task::setDeadline(int deadline) {
    deadline_ = deadline;
}

void Task::setTimeRemaining(int time) {
    timeRemaining_ = time;
}

void Task::setPriority(int priority) {
    priority_ = priority;
}

void Task::setTimeSpawned(int time) {
    spawnTime_ = time;
}

void Task::setTimeStarted(int time) {
    timeStarted_ = time;
}

void Task::setTimeFinished(int time) {
    timeFinished_ = time;
}

void Task::setFinished(bool finished) {
    finished_ = finished;
}

void Task::setFirstRun() {
    firstRun_ = true;
}

void Task::setBlockPeriod(int period) {
    blockPeriod_ = period;
}

void Task::setBlockLength(int length) {
    lengthBlock_ = length;
}

void Task::setBlockRemaining(int length) {
    blockRemaining_ = length;
}
