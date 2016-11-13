// IntArray.h

#ifndef __INTARRAY_H_INCLUDED__
#define __INTARRAY_H_INCLUDED__

#include <iostream.h>
#include <process.h>
#include <memory.h>

//#define ELEM(array)   (sizeof (array) / sizeof *(array))

class CIntArray
{
    // �����o�ϐ�
private://�O���Ɍ��J���Ȃ�
    //int m_anum[100];  // �z��
	int* m_pnum; //���I�z��
	int m_nNumOf; //�z��̗v�f��
	
    // �R���X�g���N�^�E�f�X�g���N�^
    //�R�s�[�R���X�g���N�^
public:
    CIntArray(const int nNumOf);
    ~CIntArray();
    CIntArray(CIntArray& rother) ;//���̃N���X�̎Q�Ƃ������Ɏ��

    // �����o�ւ̃A�N�Z�X�֐�
public:
    int Get(const int index);
    void Set(const int index, const int value);

    // �C���f�b�N�X�̃`�F�b�N
private:
    void CheckIndex(const int index);

    // ���̑��̏��̎擾
public:
    //bool Success();  // �������̊m�ۂ�����������
    //int NumOf();     // �z��̗v�f��
    //int SizeOf();    // �z��̃T�C�Y
    
    //�w�b�_�̒��ŃC�����C��
    // �������̊m�ۂ�����������
    bool Success()
    {
        return m_pnum != NULL;
    }

    // �z��̗v�f��
    int NumOf() const //�����o�ϐ���ύX���Ȃ��֐��̈Ӗ�
    {
        return m_nNumOf;
    }

    // �z��̃T�C�Y
    int SizeOf()
    {
        return m_nNumOf * sizeof *m_pnum;
    }

};

#endif