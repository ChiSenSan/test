// Dstruct1.cpp
//#include <iostream.h>
#include "IntArray.h"

inline void Viss(const int num)
{
    cout << "Viss : No." << num << endl;
}

CIntArray a(10);

int main()
{
    CIntArray b(20);
    Viss(1);

    CIntArray c(30);
    Viss(2);

    {
        CIntArray d(40);
        Viss(3);
    }
    Viss(4);

    return 0;
}