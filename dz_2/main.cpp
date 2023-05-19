#include "student.h"

vector<string> split(const std::string& s, char separator)
{
    vector<string> output;
    string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(separator, pos)) != std::string::npos)
    {
        std::string substring( s.substr(prev_pos, pos-prev_pos) );
        output.push_back(substring);
        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word

    return output;
}

int main(){
    ifstream file("database.csv");
    string line;
    vector<Student> students;
    string temp_name;
    string temp;
    vector<vector<string>> temp_marks = {{""}, {}, {}, {}, {}, {}, {}};
    int s = 1;
    int k = 0;
    while (getline(file, line)){
        if (line == "\000") {
            k += 1;
            continue;
        }
        if (s % 7 == 1){
            vector<string> vec = split(line, ';');
            temp_name = vec[0];
            for (int i = 1; i < vec.size(); i++) {
                temp_marks[k].push_back(vec[i]);
            }
            k += 1;
        }

        else if (s % 7 != 0 && s % 7 != 1){
            vector<string> vec = split(line, ';');
            for (int i = 0; i < vec.size(); i++)
                temp_marks[k].push_back(vec[i]);
            k += 1;
        }

        else if (s % 7 == 0){
            vector<string> vec = split(line, ';');
            for (int i = 0; i < vec.size(); i++)
                temp_marks[k].push_back(vec[i]);

            Student student = {temp_name, temp_marks};
            students.push_back(student);
            temp_name = "";

            for (int i = 0; i < temp_marks.size(); i++)
                temp_marks[i] = {};
            temp_marks[0] = {""};
            k = 0;
        }

        s += 1;
    }
    file.close();

    return 0;
}
