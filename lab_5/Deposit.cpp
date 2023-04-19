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

bool Deposit::operator<(const Deposit &other) const{
    return _name < other._name;
}

bool Deposit::operator==(const Deposit &dep) {
    return _name==dep._name && _amount==dep._amount && _currency==dep._currency && _rate==dep._rate;
}

std::string Deposit::name() const {
    return _name;
}

double Deposit::amount() const {
    return _amount;
}

std::string Deposit::currency() const {
    return _currency;
}

double Deposit::rate() const {
    return _rate;
}


size_t Hasher::operator()(const Deposit &obj) const {
    int k = 5171;
    return (k * k * k * s_hash(obj.name()) + k * k * d_hash(obj.amount()) +
    k * s_hash(obj.currency()) + d_hash(obj.rate()));
}