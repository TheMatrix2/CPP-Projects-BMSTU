#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main() {
    std::string s;
    std::ifstream file("list.txt");
    std::string file_contents;
    while (std::getline(file, s)) {
        std::vector<std::string> vec;
        std::string tmp;
        file_contents += s;
        file_contents.push_back(' ');
        for (int j = 0; j < vec.size(); j++)
            std::cout << vec[j] << " ";
        std::cout << "\n";
    }
    file.close();
    return 1;
}