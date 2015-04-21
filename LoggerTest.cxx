#include "Task.hxx"
#include "Logger.hxx"

int main(int argc, char **argv) {

Logger log;
Task* t1 = new Task(4, 0, 4);
Task* t2 = new Task(5, 0, 9);
t1->updateTask(0);
t1->updateTask(1);
t1->updateTask(2);
t1->updateTask(3);


t2->updateTask(4);
t2->updateTask(5);
t2->updateTask(6);
t2->updateTask(7);
t2->updateTask(8);
t2->updateTask(9);

log.addTask(t1);
log.addTask(t2);

log.readTasks();




return 0;

}
