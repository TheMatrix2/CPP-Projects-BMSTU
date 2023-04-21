#include "Deposit.h"
#include <iterator>

bool rate_greater(Deposit & dep1, Deposit & dep2){
    return dep1.get_rate() > dep2.get_rate();
}

int main(){
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::deque<Deposit> deposits;
    std::string name, currency;
    double amount, rate;
    while (input >> name >> amount >> currency >> rate) {
        deposits.emplace_back(name, amount, currency, rate);
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

    // Сортируем элементы контейнера по имени в обратном порядке
    std::sort(deposits.begin(), deposits.end());

    // Выводим отсортированный контейнер в output.txt
    output << "Контейнер после сортировки по имени (по убыванию):\n";
    for (const auto& deposit : deposits) {
        output << deposit << std::endl;
    }

    // Копируем исходный контейнер в список
    std::list<Deposit> depositList;
    std::copy(deposits.begin(), deposits.end(), std::back_inserter(depositList));

    // Выводим список в output.txt
    output << "Список, скопированный из исходного контейнера:\n";
    for (const auto& deposit : depositList) {
        output << deposit << std::endl;
    }

    output.close();

    std::copy(depositList.begin(), depositList.end(), std::ostream_iterator<Deposit>(std::cout, " "));
    return 0;
}
