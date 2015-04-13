
#include "Task.hxx"

Task::Task() : deadline_(), timeRemaining_(), priority_(), spawnTime_(),
    timeStarted_(), timeFinished_(), finished(false), firstRun(false) {}

Task::Task(int length, int timeSpawned, int deadline, int priority) :
    deadline_(deadline), timeRemaining_(length), priority_(priority),
    spawnTime_(timeSpawned), timeStarted_(), timeFinished_(), finished(false), firstRun(false) {}

Task::~Task() {}

bool Task::updateTask(int time, int curTime) {
    if(!getFirstRun()){
        setFirstRun();
        setTimeStarted(curTime);
    }

    setTimeRemaining(getTimeRemaining() - time);
    if(getTimeRemaining() <= 0) {
        setFinished(true);
    }

    //Priority update, probably call to strategy

    return getFinished();
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
