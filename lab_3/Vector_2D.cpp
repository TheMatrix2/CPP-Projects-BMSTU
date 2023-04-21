//
// Created by ermol on 04.03.2023.
//

#include "Vector_2D.h"

Vector_2D::Vector_2D() {
    x = 0;
    y = 0;
}

Vector_2D::Vector_2D(double x, double y) {
    this -> x = x;
    this -> y = y;
    std::cout << "constructor";
}

Vector_2D::Vector_2D(const Vector_2D &v) {
    x = v.x;
    y = v.y;
}

Vector_2D::Vector_2D(Vector_2D && v) noexcept {
    x = v.x;
    y = v.y;
    v.x = 0;
    v.y = 0;
}

Vector_2D & Vector_2D::operator=(const Vector_2D & v2){
    std::cout << "copy assignment\n";
    if (this != &v2){
        x = v2.x;
        y = v2.y;
    }
    return *this;
}

Vector_2D & Vector_2D::operator=(Vector_2D && v2){
    std::cout << "move assignment\n";
    if (this != &v2) {
        x = v2.x;
        y = v2.y;
        v2.x = 0;
        v2.y = 0;
    }
    return *this;
}

void Vector_2D::print() {
    std::cout << "x = " << x << ", y = " << y;
}

double Vector_2D::length() {
    return sqrt(pow(x, 2) + pow(y, 2));
}