#include <algorithm>
#include <iostream>
#include "Schedule.hxx"
/**
 * Constructor for FIFO strategy
 */
Schedule::Schedule(std::list<Task*>* tasks) : taskList(tasks) {};

/**
 * Destructor
 */
Schedule::~Schedule() {}//The scheduler cleans up tasks

/**
 * Reorder does nothing in FIFO
 */
void Schedule::reorder(){}//Does nothing. FIFO


/**
 * Constructor for EDF policy
 */
EDF_Schedule::EDF_Schedule(std::list<Task*>* tasks) : Schedule(tasks) {};

/**
 * Reorders tasks based on which has earliest deadline
 */
void EDF_Schedule::reorder(){
    taskList->sort([](Task* a, Task* b){
        return a->getDeadline() < b->getDeadline();
    });
}


/**
 * Constructor for priority schedule
 */
Priority_Schedule::Priority_Schedule(std::list<Task*>* tasks) : Schedule(tasks) {};

/**
 * Reorders tasks based on priority levels
 */
void Priority_Schedule::reorder(){
    taskList->sort([](Task* a, Task* b){
        return a->getPriority() < b->getPriority();
    });
}

/**
 * Constructor for RR strategy
 */
RR_Schedule::RR_Schedule(std::list<Task*>* tasks) : Schedule(tasks) {};

/**
 * Reorders tasks based on which is least recently run
 */
void RR_Schedule::reorder(){
    taskList->sort([](Task* a, Task* b){
        return a->getTimeLastRun() < b->getTimeLastRun();
    });
}


/**
 * Constructor for SJF schedule
 */
SJF_Schedule::SJF_Schedule(std::list<Task*>* tasks) : Schedule(tasks) {};

/**
 * Reorders tasks based on which has the shortest runtime remaining
 */
void SJF_Schedule::reorder(){
    taskList->sort([](Task* a, Task* b){
        return a->getTimeRemaining() < b->getTimeRemaining();
    });
}
