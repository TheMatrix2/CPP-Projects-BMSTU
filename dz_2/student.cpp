#include "student.h"

Student::Student(){
    name = nullptr;
    marks = {};
}

Student::Student(string name, vector<string> marks){
    this -> name = name;
    this -> marks = marks;
}

string Student::get_name(){
    return name;
}

vector<string> Student::get_marks(){
    return marks;
}

void Student::set_marks(vector<string> vec){
    this -> marks = vec;
}
