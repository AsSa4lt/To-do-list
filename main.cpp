#include <iostream>
#include "TaskList.h"
#include "Task.h"
using namespace std;

void printMenu(){
    cout << "1. Add Task"<<endl;
    cout << "2. Delete Task"<<endl;
    cout << "3. Mark Task as Completed"<<endl;
    cout << "4. Find Task"<<endl;
    cout << "5. Print all tasks"<<endl;
    cout << "6. Exit program"<<endl;
}

void manager(TaskList *taskList){
    string name;
    string description;
    cout << "Enter name of task" << endl;
    cin >> name;
    cout << "Describe your task" << endl;
    cin >> description;
    Task newTask(name, description);
    taskList->addTask(newTask);
}



int main() {
    TaskList *taskList = new TaskList;
    while (true){
        printMenu();
        int action;
        bool exit = false;
        //try{
        cout << "Enter command: ";
        cin >> action;
        string name;
            if(action == 1){
                manager(taskList);
            }else if(action == 2){
                cout << "Enter name to delete task" << endl;
                cin >> name;
                taskList->deleteTask(name);
            }else if(action == 3){
                cout << "Enter name to mark task" << endl;
                cin >> name;
                taskList->markTask(name);
            }else if(action == 4){
                cout << "Enter name of task to find" << endl;
                cin >> name;
                taskList->findTask(name);
            }else if(action == 5){
                taskList->printAllTasks();
            }else if(action == 6){
                exit = true;
            }else{
                cout << "No such action";
            }
            if(exit){
                break;
            }
        //}catch(...) {
        //    cout << "You entered not a number";
        //}

    }
    return 0;
}
