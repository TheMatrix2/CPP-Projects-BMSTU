#include <iostream>
#include <exception>
#include <string>
#include <vector>
using namespace std;

class GeomProgress_Except :public invalid_argument {
private:
    double first_element;
    double step;
    double* p;
    int n;
public:
    GeomProgress_Except(string name_of_except, double f_e, double s, double* parr, int num) :invalid_argument(name_of_except) {
        first_element = f_e;
        step = s;
        p= new double [num];
        for (int i=0; i<4; i++) p[i] = parr[i];
        n = num;
    }
    void print() {
        double *p1 = p;
        cout << "Exception: " << what() <<endl << "Data: " <<endl << first_element <<endl << step <<endl << n <<endl;
        for (int i = 0; i < n; i++) {cout << *p1 << "; "; p1++; }
        cout <<endl;
    }
    ~GeomProgress_Except()
    {
        //cout<<endl;
        //cout<<"~GeomProgress_Except()" <<endl;
        //if (p!=nullptr) delete[] p;
    }
};

class Array_GeomProgress
{
private:
    double first_element;
    double step;
    int n;
    double *p;
public:
    Array_GeomProgress() {
        first_element = step = n = 0;p=nullptr;
    }
    Array_GeomProgress(double f_e, double s, int num, double *parr) {
        first_element = f_e;
        step = s;
        n = num;
        p= new double [num];
        for (int i=0; i<4; i++) p[i] = parr[i];
        for (int i = 0; i < (n-1); i++) {
            double *p1 = parr; double *p2 = ++parr;
            if (*p2 != (*p1 * step)) {
                throw GeomProgress_Except("Invalid data set", first_element, step, p, n);
            }
        }
    }
    ~Array_GeomProgress()
    {
        cout<<endl;
        cout<<"~Array_GeomProgress()" <<endl;
        if (p!=nullptr) delete[] p;
    }

    void print()
    {
        std::cout<< "test" << endl;
        for(int i=0; i<n; ++i) std::cout<<p[i]<<" ";
        std::cout<<std::endl;
    }
};

int main()
{
    cout << "First exapmle:" << endl;
    double p[]={ 1, 1.5, 2.25, 1 };
    try {

        Array_GeomProgress Arr = Array_GeomProgress(1., 1.5, 4, p);
        cout << "All correct";
        Arr.print();

    }
    catch (GeomProgress_Except ex) {
        ex.print();
    }
    cout << "Second exapmle:" << endl;
    try {
        double p1[] = { 1, 1.5, 2.25 };
        Array_GeomProgress Arr = Array_GeomProgress(1., 1.5, 3, p1);
        cout << "All correct";
        //          Array_GeomProgress test;
        //  if (p[0] > 0)
        //  {
        //      Array_GeomProgress arr1 = Array_GeomProgress(Arr);
        //      test = arr1;
        //      arr1.print();
        //  }
        //  test.print();
    }
    catch (GeomProgress_Except ex) {
        ex.print();
    }
    return 0;
}