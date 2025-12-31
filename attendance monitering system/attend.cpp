#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main() {
    queue<int> attendanceQueue;   // Queue for attendance
    stack<int> undoStack;          // Stack for undo
    map<int, string> studentMap;   // Hash Map for student records

    // Adding students
    studentMap[101] = "Arun";
    studentMap[102] = "Bala";
    studentMap[103] = "Charan";

    cout << "Students Added Successfully\n\n";

    // Mark attendance
    attendanceQueue.push(101);
    attendanceQueue.push(102);
    attendanceQueue.push(103);

    cout << "Attendance Marked:\n";
    while (!attendanceQueue.empty()) {
        int id = attendanceQueue.front();
        attendanceQueue.pop();
        cout << "Present: " << studentMap[id] << endl;
        undoStack.push(id);   // save for undo
    }

    // Undo last attendance
    cout << "\nUndo Last Attendance:\n";
    if (!undoStack.empty()) {
        int undoId = undoStack.top();
        undoStack.pop();
        cout << "Attendance Removed for: " << studentMap[undoId] << endl;
    }

    return 0;
}