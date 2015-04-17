#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <list>
#include "Task.hxx"
/**
 * Abstract base class to allow definition of multiple policies
 * OR it could not be abstract and just function as FIFO
 */

class Schedule
{
    public:
        Schedule(std::list<Task*>);
        virtual ~Schedule();

        virtual void reorder();

    private:
        std::list<Task*> taskList;
};

#endif
