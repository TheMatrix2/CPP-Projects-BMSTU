#include "func.h"

int main(int argc, char* argv[]) {

    map<string, int> commands = init();
    while (true){
        cout << "\n>> ";
        char s[100];
        cin.getline(s, 100);
        string input = s;
        vector<string> command = split(input, " ");
        if (!commands.contains(command[0])){
            cout << "\nError: invalid name of command or flag: ";
            cout << "\nPrint --help to check available commands\n";
            continue;
        }
        else{
            switch (commands[command[0]]) {
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
                case 2: {
                    cout << "See you!\n";
                    return false;
                }
                case 3: {
                    if (command.size() != 3) {
                        cout << "Invalid number of arguments";
                        cout << "\nPrint --help to check available commands\n";
                        continue;
                    } else {
                        if (command[1] != "-t" && command[1] != "-py" && command[1] != "-c" && command[1] != "-kt") {
                            cout << "Unknown argument: " << command[1] << endl;
                            cout << "\nPrint --help to check available commands\n";
                        }
                        if (command[1] == "-t") {
                            run_txt(command[2]);
                            continue;
                        }
                        if (command[1] == "-py" || command[1] == "-c" || command[1] == "-kt")
                            run(command[1], command[2]);
                    }
                    continue;
                }
                case 4: {
                    string l = "cat " + command[1];
                    system(l.c_str());
                    continue;
                }
                case 5: {
                    string line;
                    for (int i = 2; i < command.size(); i++)
                        line += command[i] + " ";
                    add_line(command[1], line);
                    continue;
                }
            }
        }

    }
    return 0;
}
