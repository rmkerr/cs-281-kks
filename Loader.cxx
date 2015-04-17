#include <fstream>
#include <algorithm>
#include <iostream>

#include "Loader.hxx"

Loader::Loader(std::list<Task*>* taskList, std::string fileName) :
                                    loadedTasks(taskList) {
    std::ifstream inFile;
    inFile.open(fileName);

    //start time, length, deadline, priority
    unsigned long start, length, deadline, priority;

    while(inFile>>start) {
        inFile>>length;
        inFile>>deadline;
        inFile>>priority;
        unloadedTasks.push_back(new Task(length, start,deadline,priority));
    }
    unloadedTasks.sort(
        [](Task* a,Task* b){ return a->getSpawnTime() < b->getSpawnTime();});
}

Loader::~Loader() {
    std::for_each(unloadedTasks.begin(),unloadedTasks.end(),
        [](Task* a){delete a;});
}

void Loader::update(int time) {//We should change this interface, I'm just not sure how
    std::cout<<unloadedTasks.size()<<std::endl;
    if(unloadedTasks.size()) {
        while((*unloadedTasks.begin())->getSpawnTime() <= time){
            (*unloadedTasks.begin())->setTimeStarted(time);
            loadedTasks->push_back(*unloadedTasks.begin());
            unloadedTasks.pop_front();
        }
    }
}
