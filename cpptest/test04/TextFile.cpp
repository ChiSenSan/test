// TextFile.cpp
#include <iostream.h>
#include <stdio.h>
#include "MainDefs.h"
#include "TextFile.h"

// �f�t�H���g�R���X�g���N�^
CTextFile::CTextFile()
{
}

// �\�z�Ɠ����Ƀt�@�C�����J��
CTextFile::CTextFile(const char* pszPath,  //����͌��
                     const char* pszFlags) //: CFile(pszPath, pszFlags)
{
	Open(pszPath, pszFlags);//��������
}

// �R�s�[�R���X�g���N�^
CTextFile::CTextFile(const CTextFile& rother) : CFile(rother)
{
}

// �t���O�̒���
bool CTextFile::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
	cout << "CTextFile::ModifyFlags" << endl;
    bool bBinary;  // 'b' �̎w�肪���邩�ǂ���

    bBinary = (strchr(pszSource, 'b') != NULL);

    // �t���O����������Ƃ��� false ��Ԃ�
    if((int)strlen(pszSource) - bBinary > nSize - 1)
        return false;

    // �����I�Ƀe�L�X�g���[�h�ŊJ���܂�
    // 'b' �ȊO�̕��������R�s�[���܂�
    for(; *pszSource; pszSource++)
    {
    	//printf("%c\n",*pszSource);
        if(*pszSource != 'b')
        {
            *pszDest = *pszSource;
            pszDest++;
        }
    }
    *pszDest = '\0';
    return true;
}
// �P�s�ǂݏo���֐�
// ���s�R�[�h�͐؂�̂Ă��܂�
// �߂�l�͕�����̒����ɂȂ�܂�
// �o�b�t�@�ɓ��肫��Ȃ��Ƃ��i�I�[�o�[�t���[�j�� TF_OVERFLOW ��Ԃ��܂�
int CTextFile::ReadLine(char* buffer, size_t nSize)
{
    if(IsValid() == false)
        return EOF;
    //m_pfile��private�̃����o�Ȃ̂Ō��J����Ă��Ȃ�
    //�p�����Ŏw��q��"protected"�ɂ���K�v������
    if(fgets(buffer, nSize, m_pfile) == NULL)
        return EOF;

    size_t nLength = strlen(buffer);

    // �Ō�ɉ��s�̂Ȃ��ꍇ�́A�I�[�o�[�t���[���A���s�̂Ȃ��Ō�̍s�ł�
    // ���s�̂Ȃ��Ō�̍s�����܂��܃o�b�t�@�̒����|�P�̒����̎����I�[�o�[�t���[�Ɣ��肵�܂�
    if(buffer[nLength - 1] != '\n')
        return (nLength == nSize - 1) ? TF_OVERFLOW : nLength;

    nLength -= 1;
    buffer[nLength] = 0;
    return nLength;
}