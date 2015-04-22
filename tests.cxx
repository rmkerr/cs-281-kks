#include "Scheduler.hxx"
#include "Loader.hxx"
#include <list>
#include <iostream>

int main() {
    Scheduler scheduler(1);
    RR_Schedule RR(scheduler.getTaskQueue());
    scheduler.setSchedule(&RR);

    Loader loader(scheduler.getTaskQueue(),"tasks.data");
    for(int i = 0;i < 15;i++) {
        scheduler.updateTasks(1);
        loader.update(i);
        std::cout<<i<<":"<<scheduler.getTaskQueue()->size();
        std::cout<<":"<<scheduler.getBlockedQueue()->size()<<std::endl;
    }


    return 0;
}