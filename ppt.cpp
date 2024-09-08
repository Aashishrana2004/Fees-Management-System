#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store student information
struct Student {
    int id;
    string name;
    double totalFees;
    double paidFees;
    double remainingFees;
};

// Class to manage the student fees
class FeesManagementSystem {
private:
    vector<Student> students;
    int studentCount;

public:
    FeesManagementSystem() {
        studentCount = 0;
    }

    // Function to add a new student
    void addStudent() {
        Student newStudent;
        cout << "\nEnter Student ID: ";
        cin >> newStudent.id;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, newStudent.name);
        cout << "Enter Total Fees: ";
        cin >> newStudent.totalFees;

        newStudent.paidFees = 0;
        newStudent.remainingFees = newStudent.totalFees;

        students.push_back(newStudent);
        studentCount++;
        cout << "Student added successfully!\n";
    }

    // Function to pay fees
    void payFees() {
        int id;
        double amount;
        cout << "\nEnter Student ID to pay fees: ";
        cin >> id;

        bool found = false;
        for (auto &student : students) {
            if (student.id == id) {
                cout << "Enter the amount to pay: ";
                cin >> amount;

                if (amount <= student.remainingFees) {
                    student.paidFees += amount;
                    student.remainingFees -= amount;
                    cout << "Fees paid successfully!\n";
                    cout << "Remaining Fees: " << student.remainingFees << "\n";
                } else {
                    cout << "Error: Amount exceeds the remaining fees.\n";
                }

                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Error: Student ID not found.\n";
        }
    }

    // Function to display fee status of a specific student
    void displayFeeStatus() {
        int id;
        cout << "\nEnter Student ID to display fee status: ";
        cin >> id;

        bool found = false;
        for (const auto &student : students) {
            if (student.id == id) {
                cout << "\n--- Fee Status ---\n";
                cout << "Student ID: " << student.id << "\n";
                cout << "Name: " << student.name << "\n";
                cout << "Total Fees: " << student.totalFees << "\n";
                cout << "Paid Fees: " << student.paidFees << "\n";
                cout << "Remaining Fees: " << student.remainingFees << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Error: Student ID not found.\n";
        }
    }

    // Function to display a summary of all students and their fees
    void displayAllStudents() {
        if (students.empty()) {
            cout << "\nNo students found.\n";
            return;
        }

        cout << "\n--- All Students Summary ---\n";
        for (const auto &student : students) {
            cout << "Student ID: " << student.id << "\n";
            cout << "Name: " << student.name << "\n";
            cout << "Total Fees: " << student.totalFees << "\n";
            cout << "Paid Fees: " << student.paidFees << "\n";
            cout << "Remaining Fees: " << student.remainingFees << "\n";
            cout << "-----------------------------\n";
        }
    }

    // Function to display the main menu and handle user choices
    void menu() {
        int choice;
        do {
            cout << "\n--- Fees Management System ---\n";
            cout << "1. Add Student\n";
            cout << "2. Pay Fees\n";
            cout << "3. Display Fee Status\n";
            cout << "4. Display All Students\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    payFees();
                    break;
                case 3:
                    displayFeeStatus();
                    break;
                case 4:
                    displayAllStudents();
                    break;
                case 5:
                    cout << "Exiting the program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    FeesManagementSystem system;
    system.menu();
    return 0;
}
