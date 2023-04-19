#include "Deposit.h"

int main(int argc, char * argv[]){
    std::string input_file = argv[1];
    std::string output_file = argv[2];

    //чтение из входного файла
    std::ifstream input(input_file);
    if (!input.is_open()){
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    //в set
    std::set<Deposit> set_deposits;
    std::string name, currency;
    double amount, rate;
    while(input >> name >> amount >> currency >> rate) {
        set_deposits.insert(Deposit(name, amount, currency, rate));
    }

    //в unordered_set
    std::unordered_set<Deposit, Hasher> un_set_deposits;

}

