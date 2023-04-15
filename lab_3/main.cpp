#include "Vector_3D.h"
#include <random>


int main() {
    Vector_2D v2(1, 2);
    Vector_3D v3(10,20,30);
    std::cout<<std::endl;
    v2.print();
    std::cout<<std::endl;
    v3.print();

    Vector_2D* vectorptr;
    vectorptr = &v2;
    vectorptr->print();
    vectorptr = &v3;
    vectorptr->print();

    /*Vector_2D * ptr;
    ptr = &v2;
    ptr -> print();
    ptr = &v3;
    ptr -> print();
    std::cout<<" Len: " << ptr->length() << std::endl;
    std::cout<<"Len: " << v3.length() << std::endl;

    v2 = v3;
    std::cout << "\n";
    v2.print();*/

    return 0;
}
