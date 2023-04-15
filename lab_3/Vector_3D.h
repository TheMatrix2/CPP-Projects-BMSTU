//
// Created by ermol on 04.03.2023.
//


#ifndef LAB_3_VECTOR_3D_H
#define LAB_3_VECTOR_3D_H
#include "Vector_2D.h"

class Vector_3D : public Vector_2D{
protected:
    double z;
public:
    Vector_3D();
    Vector_3D(double x, double y, double z);
    Vector_3D(Vector_2D & xy, double z);
    void print() override;
    double length();
};


#endif //LAB_3_VECTOR_3D_H
