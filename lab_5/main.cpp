#include "Deposit.h"

int main(){
    std::string input_file = "input.txt";
    std::string output_file = "output.txt";

    //открытие входного файла
    std::ifstream input(input_file);
    if (!input.is_open()){
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    //чтение из входного файла
    std::set<Deposit> set_deposits;
    std::string name, currency;
    double amount, rate;
    std::unordered_set<Deposit, Hasher> un_set_deposits;
    while(input >> name >> amount >> currency >> rate) {
        set_deposits.insert(Deposit(name, amount, currency, rate));
        un_set_deposits.insert({name, amount, currency, rate});
    }

    input.close();

    // вывод контейнеров в output.txt
    std::ofstream output(output_file);
    if (!output.is_open()) {
        std::cerr << "Failed to open output.txt" << std::endl;
        return 1;
    }
    output << "В set:\n";
    int k = 1;
    for (const auto& deposit : set_deposits) {
        output << k << " " << deposit << std::endl;
        k += 1;
    }

    output << "\n";
    k = 1;

    output << "В unordered_set:\n";
    for (const auto& deposit : un_set_deposits) {
        output << k << " " << deposit << std::endl;
        k += 1;
    }

    output.close();
}

