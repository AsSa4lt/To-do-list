//
// Created by Rostyslav on 04.03.2023.
//

#include "TaskList.h"
#include "iostream"
#include <iomanip>
#include <ctime>
#include "chrono"
using namespace std;

void TaskList::addTask(Task _newTask) {
    taskList.push_back(_newTask);
}

void TaskList::deleteTask(string _name) {
    bool isDeleted = false;
    for(int i = 0; i < taskList.size(); i ++){
        if(taskList[i].getName() == _name){
            cout << "Task " << taskList[i].getName() << " deleted" << endl;
            taskList.erase(taskList.begin() + i);
            isDeleted = true;
        }
    }
    if(isDeleted == false){
        cout << "No task has been found";
    }
}




void TaskList::printTask(Task _task) const {
    cout << "Name: "<< _task.getName() << "\t|\tDescription: " << _task.getDescription();
    if(_task.getCompleted()){
        cout << "\t|\tDone: " << "Yes";
    }else{
        cout << "\t|\tDone: " << "No";
    }
    auto tp = _task.getCreationTime();
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&tt);
    std::cout << "\t|\tCreated: " << std::put_time(&tm, "%d/%m/%Y %H:%M");
    if(_task.getCompleted() == true){
        auto tp = _task.getCompletionTime();
        std::time_t tt = std::chrono::system_clock::to_time_t(tp);
        std::tm tm = *std::localtime(&tt);
        std::cout << "\t|\tCompleted: " << std::put_time(&tm, "%d/%m/%Y %H:%M") << '\n';
    }else{
        cout << endl;
    }
}

void TaskList::printAllTasks() const {
    for(int i = 0; i < taskList.size(); i ++){
        printTask(taskList[i]);
    }
}

void TaskList::findTask(string _name) const {
    bool isFound = false;
    for(int i = 0; i < taskList.size(); i ++){
        if(taskList[i].getName() == _name){
            printTask(taskList[i]);
            isFound = true;
        }
    }
    if(isFound == false){
        cout << "No task has been found" << endl;
    }
}

void TaskList::markTask(string _name) {
    bool isFound = false;
    for(int i = 0; i < taskList.size(); i ++){
        if(taskList[i].getName() == _name){
            taskList[i].markCompleted();
            cout << "Task marked as completed" << endl;
            isFound = true;
        }
    }
    if(isFound == false){
        cout << "No task has been found" << endl;
    }
}

