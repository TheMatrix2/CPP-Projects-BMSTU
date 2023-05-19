#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        return 1;
    }

    string language;
    getline(file, language);

    string code;
    string line;
    while (getline(file, line)) {
        code += line + "\n";
    }

    file.close();

    string tempFilename = "temp";
    ofstream tempFile(tempFilename);
    tempFile << code;
    tempFile.close();

    string command;
    if (language == "C++") {
        string filename1 = "temp.cpp";
        ofstream file1(filename1);
        file1 << code;
        file1.close();
        command = "g++ " + filename1 + " -o temp.out && ./temp.out";
    } else if (language == "Python") {
        command = "python " + tempFilename;
    } else if (language == "Kotlin") {
        command = "kotlin " + tempFilename + " -include-runtime -d temp.jar && java -jar temp.jar";
    } else {
        cout << "Error: unsupported language " << language << endl;
        return 1;
    }

    int result = system(command.c_str());
    if (result != 0) {
        cout << "Error: command failed with exit code " << result << endl;
        return 1;
    }

    cout << "Program executed successfully" << endl;

    return 0;
}
