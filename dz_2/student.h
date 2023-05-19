#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Student
{
    string name;
    vector<vector<string>> marks;
public:
    Student();
    Student(string name, vector<vector<string>> marks);
    string get_name();
    vector<vector<string>> get_marks();
};

#endif // STUDENT_H
