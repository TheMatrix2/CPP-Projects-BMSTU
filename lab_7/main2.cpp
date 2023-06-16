#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>

using namespace std;

mutex vec_mutex;

double random(double a, double b){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(a, b);
    return dis(gen);
}


void sort_vec(const string & name, vector<double>& vec, int start, int end) {
    cout << name << " started\n";
    for (int i = start; i < end; i++) {
        int min_idx = i;
        for (int j = i + 1; j < end; j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        vec_mutex.lock();
        swap(vec[i], vec[min_idx]);
        vec_mutex.unlock();
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << name << ": " << vec[i] << "\n";
    }
    cout << name << " finished\n";
}

int main() {
    srand(time(nullptr));
    vector<double> vec;

    for (int i = 0; i < 10; i++){
        vec.push_back(random(0.0, 100.0));
        cout << "main: " << vec[i] << endl;
    }
    cout << "\n";

    thread th1(sort_vec, "thread 1", ref(vec), 0, 4);
    thread th2(sort_vec, "thread 2", ref(vec), 4, 9);
    th1.join();
    th2.join();

    cout << "\n";

    thread th3(sort_vec, "thread 3", ref(vec), 0, 9);
    th3.join();

    cout << "All threads have finished their work\n";

    return 0;
}