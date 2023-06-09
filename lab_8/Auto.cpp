#include "Auto.hpp"

Auto::Auto(){
    brand = "";
    max_speed = 0;
}

Auto::Auto(std::string brand, int max_speed) {
    this -> brand = brand;
    this -> max_speed = max_speed;
}

void Auto::print() {
    std::cout << brand << " with max speed " << max_speed << "\n";
}

int Auto::getMaxSpeed() {
    return max_speed;
}

std::string Auto::getBrand() {
    return brand;
}