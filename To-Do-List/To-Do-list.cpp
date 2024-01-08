#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};


void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
    std::cout << std::endl;
}

void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added!\n\n";
}

void markTaskCompleted(std::vector<Task>& tasks, int index) {
    if (index > 0 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed!\n\n";
    } else {
        std::cout << "Invalid task number!\n\n";
    }
}

void removeTask(std::vector<Task>& tasks, int index) {
    if (index > 0 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed!\n\n";
    } else {
        std::cout << "Invalid task number!\n\n";
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "To-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear input buffer
                std::string description;
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3: {
                int index;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> index;
                markTaskCompleted(tasks, index);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter task number to remove: ";
                std::cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n\n";
        }
    }
}
