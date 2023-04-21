#include "Deposit.h"

Deposit::Deposit(){
    _name = "";
    _amount = 0.0;
    _currency = "";
    _rate = 0.0;
}

Deposit::Deposit(std::string name, double amount, std::string currency, double rate) : _name(name), _amount(amount), _currency(currency), _rate(rate) {}


Deposit::Deposit(const Deposit& other) : _name(other._name), _amount(other._amount), _currency(other._currency), _rate(other._rate){}

Deposit::Deposit(Deposit && other) noexcept: _name(std::move(other._name)),_amount(other._amount),
                                    _currency(std::move(other._currency)), _rate(other._rate) {}

Deposit::~Deposit() =default;

Deposit &Deposit::operator=(const Deposit & other) {
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
    if (_name != other._name)
        return _name < other._name;

    if (_amount != other._amount)
        return _amount < other._amount;

    if (_currency != other._currency)
        return _currency < other._currency;

    return _rate < other._rate;
}

bool Deposit::operator==(const Deposit &dep) const {
    return _name==dep._name && _amount==dep._amount && _currency==dep._currency && _rate==dep._rate;
}

std::string Deposit::get_name() const {
    return _name;
}

double Deposit::get_amount() const {
    return _amount;
}

std::string Deposit::get_currency() const {
    return _currency;
}

double Deposit::get_rate() const {
    return _rate;
}


size_t Hasher::operator()(const Deposit &obj) const {
    int k = 5171;
    return (k * k * k * s_hash(obj.get_name()) + k * k * d_hash(obj.get_amount()) +
    k * s_hash(obj.get_currency()) + d_hash(obj.get_rate()));
}