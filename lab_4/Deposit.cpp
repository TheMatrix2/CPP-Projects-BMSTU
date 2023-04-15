#include "Deposit.h"

Deposit::Deposit(){
    _name = "";
    _amount = 0.0;
    _currency = "";
    _rate = 0.0;
}

Deposit::Deposit(std::string name, double amount, std::string currency, double rate){
    this -> _name = name;
    this -> _amount = amount;
    this -> _currency = currency;
    this -> _rate = rate;
}

Deposit::Deposit(const Deposit& other)=default; //: _name(other._name), _amount(other._amount), _currency(other._currency), _rate(other._rate){}

Deposit::Deposit(Deposit && other) noexcept: _name(std::move(other._name)),_amount(std::move(other._amount)),
                                    _currency(std::move(other._currency)), _rate(std::move(other._rate)) {}

Deposit::~Deposit() {}

Deposit &Deposit::operator=(Deposit const & other) noexcept {
    if (&other != this){
        _name = other._name;
        _amount = other._amount;
        _currency = other._currency;
        _rate = other._rate;
    }
    return *this;
}

Deposit &Deposit::operator=(Deposit && other) noexcept {
    if (&other != this) {
        _name = std::move(other._name);
        _amount = other._amount;
        _currency = std::move(other._currency);
        _rate = other._rate;
    }
    return *this;
}

std::ostream & operator<<(std::ostream &out, const Deposit &deposit) {
    out << deposit._name << " " << deposit._amount << " " << deposit._currency << " " << deposit._rate << "%";
    return out;
}

bool Deposit::operator<(const Deposit &other) {
    return _name < other._name;
}

double Deposit::get_rate() const {
    return _rate;
}

std::string Deposit::get_name() const {
    return _name;
}
