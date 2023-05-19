#include "Deposit.cpp"
#include <vector>
#include <random>


double random_d(double a, double b){
    return a + rand() / (b - a + 1.0);
}

int random_i(int a, int b){
    return a + rand() % (b - a + 1);
}


int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<Deposit> deposits;
    std::vector<std::string> currencies = {"rub", "eur", "usd", "gbp", "cny"};
    std::vector<long double> rates = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 10; i++){
        std::string name;
        for (int j = 0; j < random_i(5, 10); j++)
            name += alphabet[random_i(0, alphabet.size() - 1)];
        Deposit temp = {name, random_d(100000, 1000000), currencies[random_i(0, 4)], rates[random_i(0, 9)]};
        deposits.push_back(temp);
    }

    std::ofstream input("input.txt");
    if (!input.is_open()) {
        std::cout << "Failed to open output.txt\n";
        return 1;
    }

    for (const auto & deposit : deposits)
        input << deposit << std::endl;

}