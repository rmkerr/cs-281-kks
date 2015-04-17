#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <queue>

/**
 * Abstract base class to allow definition of multiple policies
 * OR it could not be abstract and just function as FIFO
 */

class Schedule
{
    public:
        Schedule(std::queue<Task*>);
        virtual ~Schedule();

        virtual void reorder();

    private:
        std::queue<Task*> taskList;
};

#endif
