#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <future>

using namespace std;


double random(double a, double b){
    return a + rand() / (b - a + 1);
}


void sort_half(string name, vector<double>& vec, int start, int end) {
    cout << name << " started" << endl;
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j < end; j++) {
            if (vec[i] > vec[j]) {
                swap(vec[i], vec[j]);
            }
        }
    }
    for (int i = start; i < end; i++) {
        cout << name << ": " << vec[i] << endl;
    }
}


void sort_array(const string & name, vector<double>& vec) {
    cout << name << " started" << endl;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        cout << name << ": " << vec[i] << endl;
    }
}

int main() {
//    vector<double> arr(10);
//    srand(time(nullptr));
//    for (int i = 0; i < arr.size(); i++) {
//        arr[i] = rand() % 100;
//        cout << "Main: " << arr[i] << endl;
//    }
//
//    thread t1(sort_half, "Thread1", ref(arr), 0, arr.size() / 2);
//    thread t2(sort_half, "Thread2", ref(arr), arr.size() / 2, arr.size());
//    t1.join();
//    t2.join();
//
//    thread t3(sort_array, "Thread3", ref(arr));
//    t3.join();
//
//    cout << "Main: Done" << endl;

    srand(time(nullptr));
    vector<double> vec;


    return 0;
}