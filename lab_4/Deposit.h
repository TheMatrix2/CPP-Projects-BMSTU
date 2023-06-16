#ifndef LAB_4_DEPOSIT_H
#define LAB_4_DEPOSIT_H

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <list>
#include <algorithm>

class Deposit {
    std::string _name;
    double _amount;
    std::string _currency;
    double _rate;
public:
    Deposit();
    Deposit(std::string name, double amount, std::string currency, double rate);
    Deposit(const Deposit & other);
    Deposit(Deposit && other) noexcept;
    ~Deposit();
    Deposit & operator=(Deposit const & dep2) noexcept;
    Deposit & operator=(Deposit && dep2) noexcept;
    friend std::ostream & operator<<(std::ostream &out, const Deposit &vec);
    bool operator<(const Deposit & other);
    double get_rate() const;
};

#endif //LAB_4_DEPOSIT_H
