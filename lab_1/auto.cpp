#include "auto.hpp"

Auto::Auto(){
    mark = "";
    max_speed = 0;
}

Auto::Auto(std::string mark, int max_speed) {
    this -> mark = mark;
    this -> max_speed = max_speed;
}

void Auto::print() {
    std::cout << mark << " with max speed " << max_speed << "\n";
}

int Auto::get() {
    return this -> max_speed;
}