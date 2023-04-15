#include "Vector.hpp"
#include <random>

double random(double a, double b){
    return a + rand() / (b - a + 1.0);
}

int main(int argc, char* argv[]){
    srand(static_cast<unsigned int>(time(NULL)));
    int k = stoi(argv[1]);
    double a = atof(argv[2]);
    auto *m = new double[k];
    for (int i = 0; i < k; i++){
        m[i] = random(0, 100.0);
    }
    Vector vec1(m, k);
    Vector vec2 = vec1 * a;
    Vector vec3;
    cout << vec2;
    vec3 = ++vec2;
    cout << vec3;
    vec3 = vec2++;
    cout << vec3;
    return 1;
}