#include <iostream>
#include <string>
using namespace std;

int main() {
    string tasks[50];
    bool completed[50];   
    int taskCount = 0;
    int choice;

    do {
        cout << "\n========== TO-DO LIST MENU ==========\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Clear All Tasks\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (taskCount == 0)
                    cout << "\nNo tasks available.\n";
                else {
                    cout << "\nYour Tasks:\n";
                    for (int i = 0; i < taskCount; i++) {
                        cout << i + 1 << ". " << tasks[i];
                        if (completed[i])
                            cout << " [✔️ Completed]";
                        cout << endl;
                    }
                }
                break;

            case 2:
                if (taskCount < 50) {
                    cin.ignore();
                    cout << "Enter new task: ";
                    getline(cin, tasks[taskCount]);
                    completed[taskCount] = false;
                    taskCount++;
                    cout << "✅ Task added successfully!\n";
                } else {
                    cout << "⚠️ Task list is full!\n";
                }
                break;

            case 3:
                if (taskCount == 0) {
                    cout << "⚠️ No tasks to delete.\n";
                } else {
                    int num;
                    cout << "Enter task number to delete: ";
                    cin >> num;
                    if (num >= 1 && num <= taskCount) {
                        for (int i = num - 1; i < taskCount - 1; i++) {
                            tasks[i] = tasks[i + 1];
                            completed[i] = completed[i + 1];
                        }
                        taskCount--;
                        cout << "🗑️ Task deleted successfully!\n";
                    } else {
                        cout << "⚠️ Invalid task number!\n";
                    }
                }
                break;

            case 4:
                if (taskCount == 0) {
                    cout << "⚠️ No tasks to mark as completed.\n";
                } else {
                    int num;
                    cout << "Enter task number to mark as completed: ";
                    cin >> num;
                    if (num >= 1 && num <= taskCount) {
                        completed[num - 1] = true;
                        cout << "✔️ Task marked as completed!\n";
                    } else {
                        cout << "⚠️ Invalid task number!\n";
                    }
                }
                break;

            case 5:
                if (taskCount == 0) {
                    cout << "⚠️ Task list is already empty.\n";
                } else {
                    taskCount = 0;
                    cout << " All tasks cleared!\n";
                }
                break;

            case 6:
                cout << " Exiting program... Goodbye!\n";
                break;

            default:
                cout << "⚠️ Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}