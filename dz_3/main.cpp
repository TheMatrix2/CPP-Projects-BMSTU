#include "func.h"

int main(int argc, char* argv[]) {

    map<string, int> commands = init();
    while (true){
        cout << "\n>> ";
        char s[50];
        cin.getline(s, 50);
        string input = s;
        vector<string> command = split(input, " ");
        switch (commands[command[0]]) {
            case 0:{
                cout << "\nError: invalid name of command or flag: ";
                cout << "\nPrint --help to check available commands\n";
                continue;
            }
            case 1: {
                cout << "\n~~~~~~~~~~~~ tri-compiler ~~~~~~~~~~~\n";
                cout << "~~~~~~~ developed by TheMatrix ~~~~~~~\n";
                cout << "example of command: --<command> -<flag> <argument>\n";
                cout << "--run      -t / -py / -c / -kt     <filename>\n";
                cout << "       to execute text file or file with language extension\n";
                cout << "--read     <filename>\n";
                cout << "       to read file content";
                continue;
            }
            case 2:{
                cout << "See you!\n";
                return false;
            }
            case 3:{
                if (command.size() < 3){
                    cout << "Invalid number of arguments";
                    cout << "\nPrint --help to check available commands\n";
                    continue;
               }
                else {
                    if (command[1] == "-t") {
                        run_txt(command[2]);
                        continue;
                    }
                    if (command[1] == "-py" || command[1] == "-c" || command[1] == "-kt")
                        run(command[1], command[2]);
                }
                continue;
            }
            case 4:{
                string l = "cat " + command[1];
                system(l.c_str());
                continue;
            }
//            case 5:{
//                if (command.size() < 2){
//                    path = "~";
//                    string l = "cd";
//                    system(l.c_str());
//                }
//                string l = "cd " + command[1];
//                int result = system(l.c_str());
//                if (result == 0) {
//                    if (command[1] == "..") {
//                        if (path == "~")
//                            continue;
//                        int i = path.size() - 1;
//                        while (path[i] != '/') {
//                            path.pop_back();
//                            i -= 1;
//                        }
//                        path.pop_back();
//                    }
//                    else
//                        path += command[1] + "/";
//                }
//                else
//                    cout << "\nInvalid directory";
//            }
        }

    }
    return 0;
}
