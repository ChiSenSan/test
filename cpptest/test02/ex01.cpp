
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
    cout << "���O : "   << szName    << endl
         << "�@���� : " << nJapanese << " �_, "
            "���w : "   << nMath     << " �_, "
            "�p�� : "   << nEnglish  << " �_" << endl;
}

int SStudent::Ave()
{
	int sum = 0;
	
	sum = nJapanese + nMath + nEnglish;
	
	return sum/4;
}

int main()
{
	//�N���X"SStudent"�̃C���X�^���X���쐬
    SStudent students[] = {
        { "�Ԉ�F",   73, 98, 86, },
        { "�}����", 64, 45, 40, },
        { "�g�c��",   76, 78, 69, },
    };
    int      i;

    for(i = 0; i < ELEM(students); i++){
        students[i].Disp();
        cout <<"���� : " << students[i].Ave() << endl;
    }

    return 0;
}