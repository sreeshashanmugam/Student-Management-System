#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    void input();
    void display() const;
};

#endif
