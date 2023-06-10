#ifndef LAB_8_MYUNIQUE_H
#define LAB_8_MYUNIQUE_H

using namespace std;

template<class T>

class MyUnique
{
    T * p;
public:
    MyUnique() : p(nullptr) {}

    MyUnique(T *p) : p(p) {}

    ~MyUnique() {delete p;}

    T * get() const {return p;}

    T & operator*() {
        return *p;
    }

    T * operator->() {
        return p;
    }

    MyUnique(const MyUnique&) = delete;

    MyUnique & operator=(const MyUnique&) = delete;

    MyUnique(MyUnique && other) noexcept{
        p = other.p;
        other.p = nullptr;
    }

    MyUnique & operator=(MyUnique && other) noexcept{
        if (this != &other) {
            delete p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }
};

#endif //LAB_8_MYUNIQUE_H
