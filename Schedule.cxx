#include <algorithm>
#include "Schedule.cxx"

Schedule::Schedule(std::list<Task*> tasks) : taskList(tasks) {};

Schedule::~Schedule() {}//The scheduler cleans up tasks

Schedule::reorder(){}//Does nothing. FIFO