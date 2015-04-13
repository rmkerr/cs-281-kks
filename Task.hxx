#ifndef TASK_H
#define TASK_H


class Task
{
    public:
        Task();
        Task(int length, int timeSpawned, int deadline, int priority = 0);
        ~Task();

        /**
         *  decrements time remaining, checks finished, could use schedule strategy to update priority?
         *  @return finished, post update
         */
        bool updateTask(int time);

        //Accessors
        int getDeadline();
        int getTimeRemaining();
        int getPriority();
        int getSpawnTime();
        int getStartTime();
        int getTimeFinished();
        bool getFinished();
        bool getFirstRun();

        void setDeadline(int);
        void setTimeRemaining(int);
        void setPriority(int);
        void setSpawnTime(int);
        void setTimeStarted(int);
        void setTimeFinished(int);
        void setFinished(bool);
        void setFirstRun();

    private:
        int deadline_;
        int timeRemaining_;
        int priority_;
        int spawnTime_;
        int timeStarted_;
        int timeFinished_;
        bool finished_;
        bool firstRun_;
};

#endif // TASK_H
