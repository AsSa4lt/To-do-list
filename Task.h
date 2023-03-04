//
// Created by Rostyslav on 04.03.2023.
//

#ifndef TO_DO_LIST_TASK_H
#define TO_DO_LIST_TASK_H
#include "string"
#include <chrono>
using namespace std;
class Task {
private:
    string name;
    string description;
    bool  isCompleted;
    chrono::time_point<chrono::system_clock> creationTime;
    chrono::time_point<chrono::system_clock> completionTime;
public:
    Task(string _name, string _description);
    void markCompleted();
    [[nodiscard]] bool getCompleted() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] string getDescription() const;
    [[nodiscard]] chrono::time_point<chrono::system_clock> getCreationTime() const;
    [[nodiscard]] chrono::time_point<chrono::system_clock> getCompletionTime() const;
    [[nodiscard]] chrono::duration<double> getDuration() const;
    void changeDescription(string _description);
    void changeName(string _name);
};


#endif //TO_DO_LIST_TASK_H
