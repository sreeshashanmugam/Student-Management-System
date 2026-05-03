#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

// Function to add student
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Age: ";
    cin >> s.age;

    file << s.id << " " << s.name << " " << s.age << endl;
    file.close();

    cout << "Student added successfully!\n";
}

// Display students
void displayStudents() {
    Student s;
    ifstream file("students.txt");

    cout << "\nID\tName\tAge\n";
    while (file >> s.id >> s.name >> s.age) {
        cout << s.id << "\t" << s.name << "\t" << s.age << endl;
    }

    file.close();
}

// Delete student
void deleteStudent() {
    int id, found = 0;
    Student s;

    cout << "Enter ID to delete: ";
    cin >> id;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    while (file >> s.id >> s.name >> s.age) {
        if (s.id != id) {
            temp << s.id << " " << s.name << " " << s.age << endl;
        } else {
            found = 1;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student deleted!\n";
    else
        cout << "Student not found!\n";
}

// Update student
void updateStudent() {
    int id, found = 0;
    Student s;

    cout << "Enter ID to update: ";
    cin >> id;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    while (file >> s.id >> s.name >> s.age) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin >> s.name;
            cout << "Enter new age: ";
            cin >> s.age;
            found = 1;
        }
        temp << s.id << " " << s.name << " " << s.age << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student updated!\n";
    else
        cout << "Student not found!\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: deleteStudent(); break;
            case 4: updateStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
