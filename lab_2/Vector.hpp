#ifndef LAB_2_VECTOR_HPP
#define LAB_2_VECTOR_HPP
#include <iostream>
using namespace std;

class Vector {
public:
    int n;
    double * arr;
    Vector();
    ~Vector();
    Vector(double *arr, int n);
    Vector(const Vector & vec);
    Vector(Vector && vec);
    Vector & operator=(Vector & vec2);
    Vector & operator=(Vector && vec);
    Vector & operator*(double a);
    Vector operator++(); //prefix
    Vector operator++(int); //postfix
    Vector operator--(); //prefix
    Vector operator--(int); //postfix
    friend ostream & operator<<(ostream &out, const Vector &vec);
    double & operator[](int index);
    void print();
};

#endif //LAB_2_VECTOR_HPP
