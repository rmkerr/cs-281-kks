#include <algorithm>
#include "Schedule.hxx"

Schedule::Schedule(std::list<Task*>* tasks) : taskList(tasks) {};

Schedule::~Schedule() {}//The scheduler cleans up tasks

void Schedule::reorder(){}//Does nothing. FIFO