#include "student.h"
#include <iostream>
using namespace std;

void Student::input() {
    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;
}

void Student::display() const {
    cout << id << "\t" << name << "\t" << age << endl;
}
