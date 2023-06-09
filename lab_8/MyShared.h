#ifndef LAB_8_MYSHARED_H
#define LAB_8_MYSHARED_H

using namespace std;

template<class T>

class MyShared
{
    T * p;
    int * count;
public:
    MyShared() : p(nullptr), count(nullptr) {}

    explicit MyShared(T *p) : p(p), count(new int(1)) {}

    ~MyShared() {
        if (--(*count) == 0){
            delete p;
            delete count;
            p = nullptr;
            count = nullptr;
        }
    }

    T * get() const {return p;}

    T & operator*() {
        return *p;
    }

    T * operator->() {
        return p;
    }

    MyShared(const MyShared& other) : p(other.p), count(other.count) {
        ++(*count);
    }

    MyShared & operator=(const MyShared& other) noexcept{
        if (this != &other){
            p = other.p;
            count = other.count;
            ++(*count);
        }
        return *this;
    }

    MyShared(MyShared && other) noexcept{
        p = other.p;
        count = other.count;
        other.p = nullptr;
        other.count = nullptr;
    }

    MyShared & operator=(MyShared && other) noexcept{
        if (this != &other) {
            if (--(*count) == 0){
                delete p;
                delete count;
            }
            p = other.p;
            count = other.count;
            other.p = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    int getCount() const {
        return (count != nullptr) ? *count : 0;
    }
};

#endif //LAB_8_MYSHARED_H
