//
// Created by Rostyslav on 04.03.2023.
//

#ifndef TO_DO_LIST_TASKLIST_H
#define TO_DO_LIST_TASKLIST_H
#include "vector"
#include "Task.h"
class TaskList {
private:
    vector<Task> taskList;
public:
    void addTask(Task _newTask);
    void deleteTask(string _name);
    void printAllTasks() const;
    void printTask(Task _task) const;
    void findTask(string _name) const;
    void markTask(string _name);
};


#endif //TO_DO_LIST_TASKLIST_H
