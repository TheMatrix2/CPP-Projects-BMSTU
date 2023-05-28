#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <random>
#include <algorithm>

using namespace std;

condition_variable cv;
mutex m;
bool thread1_finished = false;
bool thread2_finished = false;

double random(double a, double b){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(a, b);
    return dis(gen);
}


void sort_vec(const string & name, vector<double>& vec, int start, int end) {
    cout << name << " started " << endl;
    for (int i = start; i < end; i++) {
        int min_idx = i;
        for (int j = i + 1; j < end; j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[i], vec[min_idx]);
        this_thread::sleep_for(chrono::milliseconds(5));
        cout << name << ": " << vec[i] << endl;
    }

    unique_lock<mutex> lk(m);

    if (name == "thread1") {
        thread1_finished = true;
        cout << "\nThread 1 finished sorting first half of array\n";
    } else if (name == "thread2") {
        thread2_finished = true;
        cout << "\nThread 2 finished sorting second half of array\n";
    } else {
        cout << "\nmain() finished sorting entire array\n";
    }
    lk.unlock();
    cv.notify_one();
}

void sort_full(const string & name, vector<double> & vec) {
    cout << name << " started " << endl;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << name << ": " << vec[i] << endl;
    }
}

int main(){
    srand(time(nullptr));
    vector<double> vec;

    for (int i = 0; i < 10; i++){
        vec.push_back(random(0.0, 100.0));
        cout << "main: " << vec[i] << endl;
    }
    cout << endl;

    thread th1([&vec]{
        sort_vec("thread1", vec, 0, vec.size()/2);
    });
    thread th2([&vec]{
        sort_vec("thread2", vec,  vec.size()/2, vec.size() - 1);
    });

    th1.detach();
    th2.detach();
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [] { return thread1_finished && thread2_finished; });
    }

//    th1.join();
//    th2.join();

    cout << "\nreturn to main()\n" << endl;
//    for (int i = 0; i < vec.size(); i++) {
//        int min_idx = i;
//        for (int j = i + 1; j < vec.size(); j++) {
//            if (vec[j] < vec[min_idx]) {
//                min_idx = j;
//            }
//        }
//        swap(vec[i], vec[min_idx]);
//        cout << "main: " << vec[i] << endl;
//    }
    sort_full("main", vec);

    return 0;
}