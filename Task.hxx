#ifndef TASK_H
#define TASK_H


class Task
{
    public:
        Task();
        Task(int length, int timeSpawned, int deadline, int priority = 0, int blockPeriod = 0, int blockLength = 0);
        ~Task();

        /**
         *  decrements time remaining, checks finished, could use schedule strategy to update priority?
         *  @return finished, post update
         */
        bool updateTask(int curTime);

        //Accessors
        int getDeadline();
        int getTimeRemaining();
        int getPriority();
        int getSpawnTime();
        int getTimeStarted();
        int getTimeFinished();
        bool getFinished();
        bool getFirstRun();
        int getBlockPeriod();
        int getBlockLength();


        void setDeadline(int);
        void setTimeRemaining(int);
        void setPriority(int);
        void setTimeSpawned(int);
        void setTimeStarted(int);
        void setTimeFinished(int);
        void setFinished(bool);
        void setFirstRun();
        void setBlockPeriod(int);
        void setBlockLength(int);

    private:
        int deadline_;
        int timeRemaining_;
        int priority_;
        int spawnTime_;
        int timeStarted_;
        int timeFinished_;
        bool finished_;
        bool firstRun_;
        int blockPeriod_;
        int lengthBlock_;

};

#endif // TASK_H
