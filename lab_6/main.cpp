#include "TimeClass.h"

int main(){
    try{
        TimeClass t1(8, 70, 60);
        cout << t1 << "\n";
        TimeClass t2(10, 59, 40);
        cout << t2 << "\n";
    }

    catch (InvalidTimeException& e) {
        cout << e.what() << "\n";
        e.print();
        return 0;
    }

//    for (int i = 0; i < 60; i++){
//        std::cout << t1;
//        t1.tick();
//        this_thread::sleep_for(chrono::seconds(1));
//        system("cls");
//    }
    return 0;
}
