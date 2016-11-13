//IntArray.cpp

#include "IntArray.h"

// �R���X�g���N�^
CIntArray::CIntArray(const int nNumOf)
{
    m_pnum = new int[nNumOf];
    if(m_pnum == NULL)
       m_nNumOf = 0;
    else
    {
        m_nNumOf = nNumOf;
        memset(m_pnum, 0, nNumOf * sizeof *m_pnum);
    }

    cout << "�R���X�g���N�^���Ă΂�܂����B"
         << "�v�f���� " << m_nNumOf << " �ł��B" << endl;
}

//�R�s�[�R���X�g���N�^
CIntArray::CIntArray(CIntArray& rother) 
{
    if(rother.Success() == false)
    {
        m_pnum   = NULL;
        m_nNumOf = 0;
    }
    else
    {
        m_pnum = new int[rother.NumOf()];
        if(m_pnum == NULL)
        {
            m_nNumOf = 0;
            return;
        }

        // memcpy �̓������̓��e���o�C�g�P�ʂŃR�s�[����֐��ł�
        memcpy(m_pnum, rother.m_pnum, rother.SizeOf());
        m_nNumOf = rother.m_nNumOf;
    }

    cout << "�R�s�[�R���X�g���N�^���Ă΂�܂����B" << endl;
}

// �f�X�g���N�^
CIntArray::~CIntArray()
{
    if(m_pnum != NULL)
        delete [] m_pnum;

    cout << "�f�X�g���N�^���Ă΂�܂����B"
         << "�v�f���� " << m_nNumOf << " �ł����B" << endl;
}


// �����o�ւ̃A�N�Z�X�֐�
int CIntArray::Get(const int index)
{
    CheckIndex(index);
    return m_pnum[index];
}

void CIntArray::Set(const int index, const int value)
{
    CheckIndex(index);
    m_pnum[index] = value;
}

// �C���f�b�N�X�̃`�F�b�N
//�C���f�b�N�X�̒l���z��̗v�f���𒴂��Ȃ����Ď�
void CIntArray::CheckIndex(const int index)
{
    if((unsigned int)index < (unsigned int)m_nNumOf)
        return;

    cout << "�C���f�b�N�X���s���ł��I" << endl
         << "�l : " << index << endl;
    exit(1);
}

//cpp�t�@�C�����ŃC�����C�����g�p
#if 0
// �������̊m�ۂ�����������
inline bool CIntArray::Success()
{
    return m_pnum != NULL;
}

// �z��̗v�f��
inline int CIntArray::NumOf()
{
    return m_nNumOf;
}

// �z��̃T�C�Y
inline int CIntArray::SizeOf()
{
    return m_nNumOf * sizeof *m_pnum;
}
#endif