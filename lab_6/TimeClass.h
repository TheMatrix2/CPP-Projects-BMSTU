#ifndef LAB_6_TIMECLASS_H
#define LAB_6_TIMECLASS_H

#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>

using namespace std;

class TimeClass {
    int _hours;
    int _minutes;
    int _seconds;

public:
    TimeClass();
    TimeClass(int h, int m, int s);
    TimeClass(TimeClass & other);
    TimeClass & operator=(const TimeClass & other);
    ~TimeClass();
    TimeClass operator++();
    void tick();
    friend std::ostream & operator<<(std::ostream & out, const TimeClass & time);
};


class InvalidTimeException: public out_of_range {
    int _h;
    int _m;
    int _s;
public:
    InvalidTimeException(const string& message, int h, int m, int s);
    void print();
};


#endif //LAB_6_TIMECLASS_H
