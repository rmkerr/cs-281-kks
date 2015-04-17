#include "Scheduler"
#include <algorithm>

~Scheduler() {
    std::for_each(taskQueue.begin().taskQueue.end(),[](Task*x){delete x;});
}

std::queue<Task>* getTaskQueue();

//Increment time passed, unload+log finished tasks
void updateTasks(int timestep = 1);

//Uses the Schedule strategy to order tasks
void sortQueue();


private:
void logTask();

size_t maxSimultaniousProcesses;//# of tasks to update simulataniously
std::queue<Task> taskQueue;
Schedule* schedule; 