#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <list>
#include "Task.hxx"
/**
 * Base class to allow definition of multiple policies
 * functions as FIFO
 * @author Richard Kerr
 * @author Dillon Koval
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

/**
 * Definition for Earliest Deadline First policy
 */
class EDF_Schedule : public Schedule {

    public:
        EDF_Schedule(std::list<Task*>*);

        virtual void reorder();
};

/**
 * Definition for Priority policy
 */
class Priority_Schedule : public Schedule {

    public:
        Priority_Schedule(std::list<Task*>*);

        virtual void reorder();
};


/**
 * Definition for Round Robin scheduling policy
 */
class RR_Schedule : public Schedule {

    public:
        RR_Schedule(std::list<Task*>*);

        virtual void reorder();
};

/**
 * Definition for Shortest Job First policy
 */
class SJF_Schedule : public Schedule {

    public:
        SJF_Schedule(std::list<Task*>*);

        virtual void reorder();
};

#endif
