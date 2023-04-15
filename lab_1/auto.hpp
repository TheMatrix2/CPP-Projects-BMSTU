#include <iostream>
#include <string>

#ifndef LAB_1_AUTO_H
#define LAB_1_AUTO_H


class Auto {
private:
    std::string mark;
    int max_speed;
public:
    Auto();
    Auto(std::string mark, int max_speed);
    void print();
    int get();
};

#endif //LAB_1_AUTO_H
