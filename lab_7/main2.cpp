#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>
#include <mutex>

using namespace std;


double random(double a, double b){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(a, b);
    return dis(gen);
}


void sort_half(const string & name, vector<double>& vec, int start, int end) {
    cout << name << " started\n";
    for (int i = start; i < end; i++) {
        int min_idx = i;
        for (int j = i + 1; j < end; j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[i], vec[min_idx]);
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << name << ": " << vec[i] << endl;
    }
}


void sort_full(const string & name, vector<double> & vec) {
    cout << name << " started " << endl;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << name << ": " << vec[i] << endl;
    }
}

int main() {
    srand(time(nullptr));
    vector<double> vec;

    mutex vec_mutex;

    for (int i = 0; i < 10; i++){
        vec.push_back(random(0.0, 100.0));
        cout << "main: " << vec[i] << endl;
    }
    cout << endl;

    thread th1([&vec, &vec_mutex]{
        vec_mutex.lock();
        sort_half("thread1", vec, 0, vec.size() / 2);
        cout << endl;
        vec_mutex.unlock();
    });

    thread th2([&vec, &vec_mutex]{
        vec_mutex.lock();
        sort_half("thread2", vec, vec.size() / 2 - 1, vec.size() - 1);
        cout << endl;
        vec_mutex.unlock();
    });

    th1.join();
    th2.join();

    cout << "return to main\n";
    sort_full("main", vec);

    return 0;
}