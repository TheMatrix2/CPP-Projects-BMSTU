//
// Created by ermol on 04.03.2023.
//
#include <iostream>
#include <cmath>

#ifndef LAB_3_VECTOR_2D_H
#define LAB_3_VECTOR_2D_H


class Vector_2D {
protected:
    double x;
    double y;
public:
    Vector_2D();
    Vector_2D(double x, double y);
    Vector_2D(const Vector_2D & vec);
    Vector_2D(Vector_2D && vec) noexcept;
    Vector_2D & operator=(const Vector_2D & vec2);
    Vector_2D & operator=(Vector_2D && vec);
    virtual void print();
    double length();
};


#endif //LAB_3_VECTOR_2D_H
