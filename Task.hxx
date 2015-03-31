#ifndef TASK_H
#define TASK_H


class Task
{
    public:
        Task();
        Task(int length, int priority = 0, int timeSpawned, int time);
        virtual ~Task();
        int getDeadline();
        int getTimeRemaining();
        int getPriority();
        int getSpawnTime();
        int getTimeFinished();
        bool getFinished();

        void setDeadline(int);
        void setTimeRemaining(int);
        void setPriority(int);
        void setTimeFinished(int);
        void setFinished(bool)

    private:
        int deadline_;
        int timeRemaining_;
        int priority_;
        int spawnTime_;
        int timeFinished_;
        bool finished_;
};

#endif // TASK_H
