#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <random>

using namespace std;

double random(double a, double b){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(a, b);
    return dis(gen);
}

void sort_vec(const string & name, vector<double>& vec, int start, int end, promise<void>&& prom) {
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
        cout << name << ": " << vec[i] << "\n";
    }
    cout << name << " finished";
    prom.set_value();
}

void sort_full(const string & name, vector<double> & vec) {
    cout << name << " started\n";
    for (int i = 0; i < vec.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[i], vec[min_idx]);
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << name << ": " << vec[i] << "\n";
    }
    cout << name << " finished\n";
}

int main(){

    vector<double> vec;

    for (int i = 0; i < 10; i++){
        vec.push_back(random(0.0, 100.0));
        cout << "main: " << vec[i] << endl;
    }
//    cout << "\n";

    promise<void> first_half, second_half;
    future<void> firstHalf = first_half.get_future();
    future<void> secondHalf = second_half.get_future();

    thread th1(sort_vec, "thread 1", ref(vec), 0, 4, std::move(first_half));
    thread th2(sort_vec, "thread 2", ref(vec), 0, 4, std::move(second_half));

    th1.join();
    th2.join();
    firstHalf.wait();
    secondHalf.wait();

    thread th3(sort_full, "thread 3", ref(vec));
    th3.join();

    cout << "All threads have finished their work\n";

    return 0;
}