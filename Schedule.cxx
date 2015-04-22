#include <algorithm>
#include "Schedule.hxx"

Schedule::Schedule(std::list<Task*>* tasks) : taskList(tasks) {};

Schedule::~Schedule() {}//The scheduler cleans up tasks

void Schedule::reorder(){}//Does nothing. FIFO


EDF_Schedule::EDF_Schedule(std::list<Task*>* tasks) : Schedule(tasks) {};

void EDF_Schedule::reorder(){
    taskList->sort([](Task* a, Task* b){
        return a->getDeadline() < b->getDeadline();
    });
}


Priority_Schedule::Priority_Schedule(std::list<Task*>* tasks) : Schedule(tasks) {};

void Priority_Schedule::reorder(){
    taskList->sort([](Task* a, Task* b){
        return a->getPriority() < b->getPriority();
    });
}

RR_Schedule::RR_Schedule(std::list<Task*>* tasks) : Schedule(tasks) {};

void RR_Schedule::reorder(){
    taskList->sort([](Task* a, Task* b){
        return a->getTimeLastRun() < b->getTimeLastRun();
    });
}