// Cstruct1.cpp
#include <iostream.h>

class CInt
{
public:
    int m_num;
	//�R���X�g���N�^�͌^�s�v
	CInt();
	//�I�[�o�[���[�h���܂�
    CInt(int n);//�����t���R���X�g���N�^
    void Disp();
    //�f�X�g���N�^
    ~CInt();
};

// �R���X�g���N�^
CInt::CInt()
{
	m_num = 0;
}
//�I�[�o�[���[�h
CInt::CInt(int n)
{
    m_num = n;
}

//�f�X�g���N�^
CInt::~CInt()
{
	cout << "�f�X�g���N�^���N�����Ă��܂�" << endl;
	cout << "�����om_num : " << m_num << endl;
}
// �����o�ϐ��̕\��
void CInt::Disp()
{
    cout << m_num << endl;
}

int main()
{
    CInt a, b(100), c(20), d;

    a.Disp();
    b.Disp();
    c.Disp();
    d.Disp();

    return 0;
}