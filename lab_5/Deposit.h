#ifndef LAB_5_DEPOSIT_H
#define LAB_5_DEPOSIT_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>

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
    Deposit & operator=(Deposit const & dep2);
    Deposit & operator=(Deposit && dep2) noexcept;
    friend std::ostream & operator<<(std::ostream &out, const Deposit &dep);
    bool operator<(const Deposit & other) const;
    bool operator==(const Deposit & dep) const;
    std::string get_name() const;
    double get_amount() const;
    std::string get_currency() const;
    double get_rate() const;
};


class Hasher {
public:
    std::hash <std::string> s_hash;
    std::hash <double> d_hash;
    size_t operator()(const Deposit & obj) const;
};

#endif //LAB_5_DEPOSIT_H
