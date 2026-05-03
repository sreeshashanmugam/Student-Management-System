#include "fileHandler.h"
#include "student.h"
#include <iostream>
#include <fstream>
using namespace std;

// Add student
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    s.input();

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
        s.display();
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
