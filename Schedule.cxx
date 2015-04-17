#include <algorithm>
#include "Schedule.cxx"

Schedule::Schedule(std::queue<Task*> tasks) : taskList(tasks) {};

Schedule::~Schedule() {
    std::for_each(taskList.begin().taskList.end(),[Task* x](delete x;));
}

Schedule::reorder(){}//Does nothing. FIFO