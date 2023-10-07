#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void AddTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view the list of tasks
void ViewTasks(const vector<Task>& tasks) {
    cout << "Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void MarkTaskCompleted(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void RemoveTask(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear the newline character from the buffer
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                AddTask(tasks, description);
                break;
            }
            case 2: {
                ViewTasks(tasks);
                break;
            }
            case 3: {
                cout << "Enter the index of the task to mark as completed: ";
                int index;
                cin >> index;
                MarkTaskCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                cout << "Enter the index of the task to remove: ";
                int index;
                cin >> index;
                RemoveTask(tasks, index - 1);
                break;
            }
            case 5: {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}