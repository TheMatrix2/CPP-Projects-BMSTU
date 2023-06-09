#include <iostream>
#include <string>

#ifndef LAB_8_AUTO_H
#define LAB_8_AUTO_H


class Auto {
private:
    std::string brand;
    int max_speed;
public:
    Auto();
    Auto(std::string brand, int max_speed);
    void print();
    int getMaxSpeed();
    std::string getBrand();
};

#endif //LAB_8_AUTO_H
