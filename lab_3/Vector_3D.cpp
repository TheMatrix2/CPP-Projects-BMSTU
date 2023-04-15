#include "Vector_3D.h"

Vector_3D::Vector_3D() : Vector_2D() {
    x = 0;
    y = 0;
    z = 0;
}

Vector_3D::Vector_3D(double x, double y, double z) : Vector_2D(x, y){
//    this -> x = x;
//    this -> y = y;
    this -> z = z;
}

Vector_3D::Vector_3D(Vector_2D & xy, double z) : Vector_2D(xy){
    this -> z = z;
}

void Vector_3D::print() {
    Vector_2D::print();
    std::cout << ", z = " << z << "\n";
}

double Vector_3D::length() {
    return sqrt(pow(Vector_2D::length(), 2) + pow(z, 2));
}