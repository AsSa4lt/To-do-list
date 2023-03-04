//
// Created by Rostyslav on 04.03.2023.
//

#include "Task.h"
#include <iomanip>
#include <ctime>
using namespace std;

Task::Task(string _name, string _description) {
    name = _name;
    description = _description;
    creationTime = chrono::system_clock::now();
    isCompleted = false;
}

void Task::markCompleted() {
    isCompleted = true;
    completionTime = chrono::system_clock::now();
}

bool Task::getCompleted() const {
    return isCompleted;
}

string Task::getName() const {
    return name;
}

string Task::getDescription() const {
    return description;
}

std::chrono::time_point<std::chrono::system_clock> Task::getCreationTime() const {
    return creationTime;
}

std::chrono::time_point<std::chrono::system_clock> Task::getCompletionTime() const {
    return completionTime;
}

std::chrono::duration<double> Task::getDuration() const {
    return completionTime - creationTime;
}

void Task::changeDescription(string _description) {
    description = _description;
    destroy(_description.begin(), _description.end());
}

void Task::changeName(string _name) {
    name = _name;
    destroy(_name.begin(), _name.end());
}

