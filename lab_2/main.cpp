#include "Vector.hpp"
#include <random>

double random(double a, double b){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(a, b);
    return dis(gen);
}

int main(int argc, char* argv[]){
//    srand(static_cast<unsigned int>(time(NULL)));
    int k = stoi(argv[1]);
    double a = atof(argv[2]);
    auto *m = new double[k];
    for (int i = 0; i < k; i++){
        m[i] = random(0, 100.0);
    }
    Vector vec1(m, k);
    cout << vec1;
    Vector vec2 = vec1 * a;
    cout << vec2;
    Vector vec3;
    vec3 = ++vec2;
    cout << vec3;
    vec3 = vec2++;
    cout << vec3;
    return 0;
}