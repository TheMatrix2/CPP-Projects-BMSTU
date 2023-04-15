#include "auto.hpp"
#include <fstream>
#include <vector>

std::vector<Auto> reading_file_to_vector(const std::string filename){
    std::vector<Auto> vec;
    std::string s;
    std::ifstream file(filename);
    std::string file_contents;
    while (std::getline(file, s)){
        file_contents += s;
        file_contents.push_back(' ');
    }
    int i = 0;
    while (i < file_contents.size() - 1) {
        std::string temp_s1, temp_s2;
        while (file_contents[i] != ' ') {
            temp_s1 += file_contents[i];
            i += 1;
        }
        i += 1;
        while (file_contents[i] != ' ') {
            temp_s2 += file_contents[i];
            i += 1;
        }
        Auto temp(temp_s1, std::stoi(temp_s2));
        vec.push_back(temp);
        i += 1;
    }
    file.close();
    return vec;
}

void reading_file_to_array(const std::string filename, Auto * arr){
    std::string s;
    std::ifstream file(filename);
    std::string file_contents;
    while (std::getline(file, s)){
        file_contents += s + ' ';
    }
    int i = 0;
    int k = 0;
    while (i < file_contents.size()) {
        std::string temp_s1, temp_s2;
        while (file_contents[i] != ' ') {
            temp_s1 += file_contents[i];
            i += 1;
        }
        i += 1;
        while (file_contents[i] != ' ') {
            temp_s2 += file_contents[i];
            i += 1;
        }
        Auto temp(temp_s1, std::stoi(temp_s2));
        arr[k] = temp;
        i += 1;
        k += 1;
    }
    file.close();
}

int main(int argc, char *argv[]){
    std::vector<Auto> auto_vec = reading_file_to_vector("list.txt");
    int speed = std::stoi(argv[1]);
    for (int i = 0; i < auto_vec.size(); i++)
        if (auto_vec[i].get() <= speed)
            auto_vec[i].print();

    std::cout << "\n";

    Auto * arr = new Auto [15];
    reading_file_to_array("list.txt", arr);
    for (int i = 0; i < 10; i++)
        if (arr[i].get() <= speed)
            arr[i].print();
    return 0;
}