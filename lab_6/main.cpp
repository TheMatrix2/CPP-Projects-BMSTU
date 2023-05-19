#include "TimeClass.h"

int main(){
    try{
        // correct
        TimeClass t2(10, 59, 40);
        cout << t2 << "\n";
        // error
        TimeClass t1(8, 70, 60);
        cout << t1 << "\n";
    }

    catch (InvalidTimeException& e) {
        e.print();
    }

    this_thread::sleep_for(chrono::seconds(10));

    TimeClass t(0, 0, 0);
    for (int i = 0; i < 60; i++){
        system("cls");
        std::cout << t;
        t.tick();
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
