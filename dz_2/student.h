#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <codecvt>
#include <locale>
#include <io.h>
#include <fcntl.h>

using namespace std;


class Student
{
    string name;
    vector<string> marks;
//    vector<vector<string>> marks;
public:
    Student();
    Student(string name, vector<string> marks);
    string get_name();
    vector<string> get_marks();
    void set_marks(vector<string> vec);
};

#endif // STUDENT_H
