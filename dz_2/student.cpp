#include "student.h"

Student::Student(){
    name = nullptr;
}

Student::Student(string name, vector<vector<string>> marks){
    this -> name = name;
    this -> marks = marks;
}

string Student::get_name(){
    return name;
}

vector<vector<string>> Student::get_marks(){
    return marks;
}
