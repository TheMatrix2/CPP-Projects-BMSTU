#include "Auto.hpp"
#include "MyUnique.h"
#include "MyShared.h"

template<typename T, typename...Args>
T* Make_MyShared(Args&& ... args) {
    return new T(forward<Args>(args)...);
}

template<typename T, typename...Args>
T* Make_MyUnique(Args&& ... args) {
    return new T(forward<Args>(args)...);
}

int main(){
// Vol. 1 - MyUnique
    cout << "Vol. 1\n";
    MyUnique<Auto> mu1 = MyUnique<Auto>(Make_MyUnique<Auto>("BMW", 250));
    cout << mu1 -> getMaxSpeed() << endl;

    MyUnique<Auto> mu2;
    mu2 = move(mu1);

    cout << mu2 -> getMaxSpeed() << endl;


// Vol. 2 - MyShared
    cout << "\nVol. 2\n";
    MyShared<Auto> ms1 = MyShared<Auto>(Make_MyShared<Auto>("Ford", 200));
    cout << ms1 -> getMaxSpeed() << endl;
    {
        MyShared<Auto> ms2(ms1);
        cout << ms2->getBrand() << endl;
        cout << ms1.getCount() << endl;
    }
    cout << ms1.getCount() << endl;
    MyShared<Auto> ms3;
    ms3 = ms1;
    cout << ms3 -> getMaxSpeed() << endl;
    return 0;
}