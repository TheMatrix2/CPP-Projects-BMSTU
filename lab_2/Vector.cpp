#include "Vector.hpp"

Vector::Vector(){
    cout << "void constructor\n";
    n = 0;
    arr = nullptr;
}

Vector::~Vector(){
    cout << "destructor\n";
    delete[] arr;
    n = 0;
}

Vector::Vector(double *arr, int n) {
    cout << "constructor with n-arr data\n";
    this -> n = n;
    this -> arr = new double[n];
    for (int i = 0; i < n; i++)
        this -> arr[i] = arr[i];
}

Vector::Vector(const Vector & vec){
    cout << "copy constructor\n";
    n = vec.n;
    arr = new double [n];
    for (int i = 0; i < n; i++)
        arr[i] = vec.arr[i];
}

Vector::Vector(Vector && vec) : arr(nullptr), n(0) {
    cout << "move constructor\n";
    arr = vec.arr;
    n = vec.n;
    vec.arr = nullptr;
    vec.n = 0;
}

Vector & Vector::operator=(Vector & vec2){
    cout << "copy assignment\n";
    if (this != &vec2) {
        n = vec2.n;
        if (arr != nullptr) delete [] arr;
        arr = new double[n];
        for (int i = 0; i < n; i++)
            arr[i] = vec2.arr[i];
    }
    return *this;
}

Vector & Vector::operator=(Vector && vec2){
    cout << "move assignment\n";
    if (this != &vec2) {
        if (arr != nullptr) delete[] arr;
        n = vec2.n;
        arr = vec2.arr;
        vec2.arr = nullptr;
        vec2.n = 0;
    }
    return *this;
}

Vector & Vector::operator*(double a){
    double *temp = new double[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i] * a;
    Vector * vec = new Vector(temp, n);
    delete[] temp;
    return * vec;
}

double & Vector::operator[](int index)
{
    return arr[index];
}

Vector Vector::operator++() {
    for (int i = 0; i < this -> n; i++)
        this -> arr[i] += 1.0;
    Vector temp(*this);
    return temp;
}

Vector Vector::operator++(int) {
    Vector temp(*this);
    for (int i = 0; i < this -> n; i++)
        this -> arr[i] = this -> arr[i] + 1.0;
    return temp;
}

Vector Vector::operator--() {
    for (int i = 0; i < this -> n; i++)
        this -> arr[i] -= 1.0;
    Vector temp(*this);
    return temp;
}

Vector Vector::operator--(int) {
    Vector temp(*this);
    for (int i = 0; i < this -> n; i++)
        this -> arr[i] -= 1.0;
    return temp;
}

ostream & operator<<(ostream &out, const Vector &vec){
    cout << "\n";
    for (int i = 0; i < vec.n; i++)
         out << vec.arr[i] << " ";
    cout << "\n";
    return out;
}

void Vector::print() {
    cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    cout << "\n";
}