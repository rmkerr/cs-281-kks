#include <ifstream>
#include <algorithm>
#include <list>
#include <queue>

Loader::Loader(std::queue<Task*>* taskList, std::string fileName) :
                                    loadedTasks(taskList) {
    ifstream inFile;
    infile.open(fileName);

    //start time, length, deadline, priority
    unsigned long start, length, deadline, priority;

    while(inFile) {
        inFile>>start;
        infile>>length;
        infile>>deadline;
        infile>>priority;
        unloadedTasks.push_back(new Task(length, start,deadline,priority));
    }
    std::sort(unloadedTasks.begin(),unloadedTasks.end(),
        [](auto a,auto b){ return a->getSpawnTime() < b->getSpawnTime();});
}

Loader::~Loader() {
    std::for_each(unloadedTasks.begin(),unloadedTasks.end(),
        [](auto a){delete a;});
}

void Loader::update(int time) {//We should change this interface, I'm just not sure how
    if(unloadedTasks.size()) {
        while(next->getSpawnTime() >= time){
            loadedTasks->push_back(*unloadedTasks.begin());
            unloadedTasks.pop_front();
        }
    }
}
