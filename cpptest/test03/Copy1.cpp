// Copy1.cpp
//#include <iostream.h>
#include "IntArray.h"

// CIntArray は IntArray.h で宣言され、
// IntArray.cpp で実装されているとします

inline void Viss(int num)
{
    cout << "Viss : No." << num << endl;
}


//ここでコピーコンストラクタが起動する。
//仮引数arrayはクラスCIntArrayのメンバであるrotherに渡され、
//rotherは実質的にarrayAtoZの参照として働く。
void Disp(const CIntArray array)
{
    Viss(2);

    int i;

    for(i = 0; i < array.NumOf(); i++)
        cout << array.Get(i) << ' ';
    cout << endl;

    Viss(3);
}

int main()
{
	//アルファベットの数分の要素数をもつ配列を作る
    CIntArray arrayAtoZ('Z' - 'A' + 1);
    int       i;

    for(i = 0; i < arrayAtoZ.NumOf(); i++)
        arrayAtoZ.Set(i, 'A' + i);

    Viss(1);
    Disp(arrayAtoZ);//表示するためにDisp関数に渡す
    Viss(4);

    return 0;
}