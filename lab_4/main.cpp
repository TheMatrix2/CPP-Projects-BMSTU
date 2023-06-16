#include "Deposit.h"
#include <iterator>

int main(){
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::deque<Deposit> depositDeque;
    std::string name, currency;
    double amount, rate;
    while (input >> name >> amount >> currency >> rate) {
        depositDeque.emplace_back(name, amount, currency, rate);
    }
    input.close();

    // Выводим исходный контейнер в output.txt
    std::ofstream output("output.txt");
    if (!output.is_open()) {
        std::cerr << "Failed to open output.txt" << std::endl;
        return 1;
    }
    output << "Исходный контейнер:\n";
    for (const auto& deposit : depositDeque) {
        output << deposit << std::endl;
    }

    // Сортируем элементы контейнера по имени в обратном порядке
    std::sort(depositDeque.begin(), depositDeque.end());

    // Выводим отсортированный контейнер в output.txt
    output << "Контейнер после сортировки по имени (по убыванию):\n";
    for (const auto& deposit : depositDeque) {
        output << deposit << std::endl;
    }

    // Копируем исходный контейнер в список
    std::list<Deposit> depositList;
    std::copy(depositDeque.begin(), depositDeque.end(), std::back_inserter(depositList));

    // Выводим список в output.txt
    output << "Список, скопированный из исходного контейнера:\n";
    for (const auto& deposit : depositList) {
        output << deposit << std::endl;
    }

    output.close();
    return 0;
}
