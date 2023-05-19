#include "TimeClass.h"

InvalidTimeException::InvalidTimeException(const std::string &message, int h, int m, int s) : out_of_range(message) {
    this->_h = h;
    this->_m = m;
    this->_s = s;
}

void InvalidTimeException::print() {
    cout << "Exception: " << what() << endl << "Invalid time value: " << _h << ":" << _m << ":" << _s << "\n";
}


TimeClass::TimeClass() {
    _hours = 0;
    _minutes = 0;
    _seconds = 0;
}

TimeClass::TimeClass(int h, int m, int s) {
    if (h < 0 || h > 23) {
        throw InvalidTimeException("Invalid hours value", h, m, s);
    }
    if (m < 0 || m > 59) {
        throw InvalidTimeException("Invalid minutes value", h, m, s);
    }
    if (s < 0 || s > 59) {
        throw InvalidTimeException("Invalid seconds value", h, m, s);
    }

    _hours = h;
    _minutes = m;
    _seconds = s;
}

TimeClass::TimeClass(TimeClass & other) = default;

TimeClass & TimeClass::operator=(const TimeClass &other) = default;

TimeClass::~TimeClass()=default;

TimeClass TimeClass::operator++() {
    this -> _seconds++;
    if (this -> _seconds == 60) {
        this -> _seconds = 0;
        this -> _minutes++;
        if (this -> _minutes == 60) {
            this -> _minutes = 0;
            this -> _hours++;
            if (this -> _hours == 24) {
                this -> _hours = 0;
            }
        }
    }
    TimeClass temp(*this);
    return temp;
}

void TimeClass::tick() {
    this->operator++();
}

std::ostream & operator<<(std::ostream & out, const TimeClass & time){
    cout << time._hours << " : " << time._minutes << " : " << time._seconds;
    return out;
}


