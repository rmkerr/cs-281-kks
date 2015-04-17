#include "Scheduler.hxx"
#include "Loader.hxx"
#include <list>
#include <iostream>

int main() {
    Scheduler scheduler(4);
    Schedule fifo(scheduler.getTaskQueue());
    scheduler.setSchedule(&fifo);

    Loader loader(scheduler.getTaskQueue(),"tasks.data");
    for(int i = 0;i < 15;i++) {
        scheduler.updateTasks(1);
        loader.update(i);
        std::cout<<i<<":"<<scheduler.getTaskQueue()->size()<<std::endl;
    }


    return 0;
}