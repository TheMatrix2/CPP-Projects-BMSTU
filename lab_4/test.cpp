#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <list>
#include <algorithm>

class BankDeposit {
    std::string name_;
    double amount_;
    std::string currency_;
    double interestRate_;
public:
    BankDeposit(const std::string& name = "", double amount = 0.0, const std::string& currency = "", double interestRate = 0.0)
            : name_(name), amount_(amount), currency_(currency), interestRate_(interestRate) {}

    BankDeposit(const BankDeposit& other)
            : name_(other.name_), amount_(other.amount_), currency_(other.currency_),
              interestRate_(other.interestRate_) {}

    BankDeposit(BankDeposit&& other) noexcept
            : name_(std::move(other.name_)), amount_(std::move(other.amount_)),
              currency_(std::move(other.currency_)), interestRate_(std::move(other.interestRate_)) {}

    BankDeposit& operator=(const BankDeposit& other) {
        if (&other != this) {
            name_ = other.name_;
            amount_ = other.amount_;
            currency_ = other.currency_;
            interestRate_ = other.interestRate_;
        }
        return *this;
    }

    BankDeposit& operator=(BankDeposit&& other) noexcept {
        if (&other != this) {
            name_ = std::move(other.name_);
            amount_ = std::move(other.amount_);
            currency_ = std::move(other.currency_);
            interestRate_ = std::move(other.interestRate_);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const BankDeposit& deposit) {
        os << deposit.name_ << " " << deposit.amount_ << " " << deposit.currency_ << " " << deposit.interestRate_;
        return os;
    }

    bool operator<(const BankDeposit& other) const {
        return interestRate_ < other.interestRate_;
    }

    bool operator>(const BankDeposit& other) const {
        return name_ > other.name_;
    }
};

class CompareByName {
public:
    bool operator()(const BankDeposit& lhs, const BankDeposit& rhs) const {
        return lhs > rhs;
    }
};

int main() {
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::deque<BankDeposit> deposits;
    std::string name, currency;
    double amount, interestRate;
    while (input >> name >> amount >> currency >> interestRate) {
        deposits.emplace_back(name, amount, currency, interestRate);
    }
    input.close();

    // Выводим исходный контейнер в output.txt
    std::ofstream output("output.txt");
    if (!output.is_open()) {
        std::cerr << "Failed to open output.txt" << std::endl;
        return 1;
    }
    output << "Исходный контейнер:\n";
    for (const auto& deposit : deposits) {
        output << deposit << std::endl;
    }

    // Сортируем элементы контейнера по убыванию процентной ставки
    std::sort(deposits.begin(), deposits.end(), std::greater<>());

    // Выводим отсортированный контейнер в output.txt
    output << "Контейнер после сортировки по процентной ставке (по убыванию):\n";
    for (const auto& deposit : deposits) {
        output << deposit << std::endl;
    }

    // Сортируем элементы контейнера по имени в обратном порядке
    std::sort(deposits.begin(), deposits.end(), CompareByName{});

    // Выводим отсортированный контейнер в output.txt
    output << "Контейнер после сортировки по имени (по убыванию):\n";
    for (const auto& deposit : deposits) {
        output << deposit << std::endl;
    }

    // Копируем исходный контейнер в список
    std::list<BankDeposit> depositList;
    std::copy(deposits.begin(), deposits.end(), std::back_inserter(depositList));

    // Выводим список в output.txt
    output << "Список, скопированный из исходного контейнера:\n";
    for (const auto& deposit : depositList) {
        output << deposit << std::endl;
    }

    output.close();
    return 0;
}
