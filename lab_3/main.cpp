#include "Vector_3D.h"

int main() {
    Vector_2D v2(1, 2);
    Vector_3D v3(10,20,30);
    std::cout<< "\n";
    v2.print();
    std::cout<< "\n";
    v3.print();
    std::cout<< "\n";

    Vector_2D* ptr1;
    ptr1 = &v2;
    ptr1->print();
    std::cout << "\n";
    std::cout << ptr1 -> length() << "\n";
    ptr1 = &v3;
    ptr1->print();
    std::cout << ptr1 -> length() << "\n";

    return 0;
}
