
// Class1.cpp
#include <iostream.h>

#define ELEM(array)  (sizeof (array) / sizeof *(array))

class SStudent
{
	public:
    char szName[16];
    int  nJapanese;
    int  nMath;
    int  nEnglish;
    
    void Disp();
    int Ave();
};

void SStudent::Disp()
{
    cout << "名前 : "   << szName    << endl
         << "　国語 : " << nJapanese << " 点, "
            "数学 : "   << nMath     << " 点, "
            "英語 : "   << nEnglish  << " 点" << endl;
}

int SStudent::Ave()
{
	int sum = 0;
	
	sum = nJapanese + nMath + nEnglish;
	
	return sum/4;
}

int main()
{
	//クラス"SStudent"のインスタンスを作成
    SStudent students[] = {
        { "赤井孝",   73, 98, 86, },
        { "笠井大介", 64, 45, 40, },
        { "吉田叶",   76, 78, 69, },
    };
    int      i;

    for(i = 0; i < ELEM(students); i++){
        students[i].Disp();
        cout <<"平均 : " << students[i].Ave() << endl;
    }

    return 0;
}