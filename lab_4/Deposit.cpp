#include "Deposit.h"

Deposit::Deposit(){
    _name = "";
    _amount = 0.0;
    _currency = "";
    _rate = 0.0;
}

Deposit::Deposit(std::string name, double amount, std::string currency, double rate){
    this -> _name = std::move(name);
    this -> _amount = amount;
    this -> _currency = std::move(currency);
    this -> _rate = rate;
}

Deposit::Deposit(const Deposit& other)=default;

Deposit::Deposit(Deposit && other) noexcept: _name(std::move(other._name)),_amount(other._amount),
                                    _currency(std::move(other._currency)), _rate(other._rate) {}

Deposit::~Deposit() = default;

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
    if (_name != other._name)
        return _name < other._name;

    if (_amount != other._amount)
        return _amount < other._amount;

    if (_currency != other._currency)
        return _currency < other._currency;

    return _rate < other._rate;
}

double Deposit::get_rate() const {
    return _rate;
}
