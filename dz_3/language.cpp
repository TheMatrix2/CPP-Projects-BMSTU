#include "language.h"

void Language::compile() {}


Python::Python(string & code) : code(code) {}

void Python::compile() {
    ofstream file("temp.py");
    file << code;
    file.close();
    string command = "python3 temp.py";

    int result = system(command.c_str());
    if (result != 0) {
        cout << "Error: command failed with exit code " << result << endl;
        return;
    }

    cout << "\nProgram executed successfully" << endl;
}

Python::~Python() = default;


C::C(string & code) : code(code) {}

C::~C() = default;

void C::compile() {
    ofstream file("temp.cpp");
    file << code;
    file.close();
    string command = "g++ temp.cpp -o temp.out && ./temp.out";

    int result = system(command.c_str());
    if (result != 0) {
        cout << "Error: command failed with exit code " << result << endl;
        return;
    }

    cout << "\nProgram executed successfully" << endl;
}


Kotlin::Kotlin(string & code) : code(code) {}

Kotlin::~Kotlin() = default;

void Kotlin::compile() {
    ofstream file("temp.kt");
    file << code;
    file.close();
    string command = "kotlin temp.kt -include-runtime -d temp.jar && java -jar temp.jar";

    int result = system(command.c_str());
    if (result != 0) {
        cout << "Error: command failed with exit code " << result << endl;
        return;
    }

    cout << "\nProgram executed successfully" << endl;
}

void Language::add_line(string line){
    if (line.find("/n", 0) != 0) {
        cout << "\n'" << line << "' is not a line\n";
        return;
    }
    code += "\n" + line;
}
