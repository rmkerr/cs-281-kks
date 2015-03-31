#ifndef SCHEDULE_H
#define SCHEDULE_H

/**
 * Abstract base class to allow definition of multiple policies
 * OR it could not be abstract and just function as FIFO
 */

class Schedule
{
    public:
        Schedule();
        virtual ~Schedule();
    private:

}


#endif
