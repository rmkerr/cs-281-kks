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
        Schedule(std::list<Task*>*);
        virtual ~Schedule();

        virtual void reorder();

    protected:
        std::list<Task*>* taskList;
};


class EDF_Schedule : public Schedule {

    public:
        EDF_Schedule(std::list<Task*>*);

        virtual void reorder();
};

class Priority_Schedule : public Schedule {

    public:
        Priority_Schedule(std::list<Task*>*);

        virtual void reorder();
};

class RR_Schedule : public Schedule {

    public:
        RR_Schedule(std::list<Task*>*);

        virtual void reorder();
};

#endif
