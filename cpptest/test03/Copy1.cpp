// Copy1.cpp
//#include <iostream.h>
#include "IntArray.h"

// CIntArray �� IntArray.h �Ő錾����A
// IntArray.cpp �Ŏ�������Ă���Ƃ��܂�

inline void Viss(int num)
{
    cout << "Viss : No." << num << endl;
}


//�����ŃR�s�[�R���X�g���N�^���N������B
//������array�̓N���XCIntArray�̃����o�ł���rother�ɓn����A
//rother�͎����I��arrayAtoZ�̎Q�ƂƂ��ē����B
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
	//�A���t�@�x�b�g�̐����̗v�f�������z������
    CIntArray arrayAtoZ('Z' - 'A' + 1);
    int       i;

    for(i = 0; i < arrayAtoZ.NumOf(); i++)
        arrayAtoZ.Set(i, 'A' + i);

    Viss(1);
    Disp(arrayAtoZ);//�\�����邽�߂�Disp�֐��ɓn��
    Viss(4);

    return 0;
}