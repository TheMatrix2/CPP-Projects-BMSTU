#include "language.h"

void Language::compile() {}


Python::Python(string filename) : filename(filename) {}

void Python::compile() {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }

    string language;
    getline(file, language);

    if (language != "Python" || language != "python"){
        cout << "Invalid language";
        return;
    }

    string code;
    string line;
    while (getline(file, line)) {
        code += line + "\n";
    }
    file.close();

    string tempFilename = "temp.py";
    ofstream file1(tempFilename);
    file1 << code;
    file1.close();
    string command = "python3 " + tempFilename;

    int result = system(command.c_str());
    if (result != 0) {
        cout << "Error: command failed with exit code " << result << endl;
        return;
    }

    cout << "\nProgram executed successfully" << endl;
}

Python::~Python() = default;


C::C(std::string filename) : filename(filename) {}

C::~C() = default;

void C::compile() {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }

    string language;
    getline(file, language);

    if (language != "C++" || language != "c++"){
        cout << "Invalid language";
        return;
    }

    string code;
    string line;
    while (getline(file, line)) {
        code += line + "\n";
    }
    file.close();

    string tempFilename = "temp.cpp";
    ofstream file1(tempFilename);
    file1 << code;
    file1.close();
    string command = "g++ " + tempFilename + " -o temp.out && ./temp.out";

    int result = system(command.c_str());
    if (result != 0) {
        cout << "Error: command failed with exit code " << result << endl;
        return;
    }

    cout << "\nProgram executed successfully" << endl;
}
