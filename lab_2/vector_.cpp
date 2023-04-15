#include <iostream>
using namespace std;
#include <string>
#include"Vector.hpp"

Vector::Vector() { arr = nullptr; n = 0; }

Vector::Vector(double *arr, int n) {
    cout << "constructor with n-arr data\n";
    this->n = n;
    this->arr = new double[n];
    for (int i = 0; i < n; i++)
        this->arr[i] = arr[i];
}

//конструктор копирования
Vector::Vector(const Vector & vec)
 {
    n = vec.n;
    arr = new double[n];
    for (int i = 0; i < n; i++)
    arr[i] = vec.arr[i];
    cout<<"copy"<<endl;
 }

 // Конструктор перемещения 
Vector::Vector(Vector&& vec)
 {
    arr = vec.arr;
    n = vec.n;
    vec.arr = nullptr;
    vec.n = 0;
    cout<<"move"<<endl;
 }

 Vector & Vector::operator=(const Vector & vec2) // функция копирования
 {
 if (this != &vec2) {
    n = vec2.n;
    if (arr != nullptr) delete[] arr;
    p = new double[n]; 
    for (int i = 0; i < n; i++) p[i] = v2.p[i];
 }
 cout<<"copy"<<endl;
 return *this; 
 }
 
 
 
 Vector & Vector::operator =(Vector&& v2) //функция перемещения 
 {
 if (this!=&v2) 
 {
    n = v2.n;
    if (p != nullptr) delete[] p; 
    p = v2.p; 
    v2.p=nullptr;
    v2.n=0; 
 }
 cout<<"move"<<endl;
return *this;
 }
void Vector::pop(const int index){
    for (int i = index+1; i < n; i++) p[i - 1] = p[i];
    double* temp = new double [n - 1];
    for (int i = 0; i < n-1; i++) temp[i] = p[i];
    if (p != nullptr) delete [] p;
    p = nullptr;
    p = temp;
    //cout<<"new arr: ";
    n--;
};

Vector operator +(const Vector& v1, const Vector& v2)
{
 Vector V(v1.n+v2.n); 
 for (int i = 0; i < v1.n; i++) V.p[i] = v1.p[i];
 for (int i = 0; i < v2.n; i++) V.p[i+v1.n] = v2.p[i]; 
 return V;
}


Vector Vector::operator ^( Vector& v2)
{
    for (int i=0;i<this->n;i++)
    {
        for (int j=0;j<v2.n;j++)
        {
            if (this->p[i]==v2.p[j])
            {
              this->pop(i);
              v2.pop(j);
              for (int i=0; i<this->n;++i){cout<<this->p[i]<<" ";}
               cout<<endl;
               for (int i=0; i<v2.n;++i){cout<<v2.p[i]<<" ";}
               cout<<endl;
               i--;
            
            }
        }
    } 
   Vector v(*this+v2);
    
   return v;
}
 
Vector::~Vector() // Деструктор
 {
 cout<<"~Vector()" <<endl;
 if (p!=nullptr) delete[] p; 
 }
//prev
Vector Vector:: operator ++ (){
   for (int i=0;i<this->n;i++) ++this->p[i];
   Vector temp(*this);
   return temp;
} 
//post
Vector Vector:: operator ++ (int a){
   Vector temp(*this);
   for (int i=0;i<this->n;i++) this->p[i]++;
   return temp;
}