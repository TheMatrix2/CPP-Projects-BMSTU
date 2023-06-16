#include "TimeClass.h"

int main(){
    try{
        // correct
        TimeClass t2(10, 59, 40);
        cout << t2 << "\n";
        // error
        TimeClass t1(8, 70, 50);
        cout << t1 << "\n";
    }

    catch (InvalidTimeException& e) {
        e.print();
    }

    cout << "\ncontinue\n";
    TimeClass t(23, 59, 59);
    cout << t << "\n";
    t.tick();
    cout << t;

    return 0;
}
