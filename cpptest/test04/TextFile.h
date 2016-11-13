// TextFile.h
#ifndef __TEXTFILE_H__INCLUDED__
#define __TEXTFILE_H__INCLUDED__

#include <stdio.h>
#include <string.h>
#include "File.h"

const int TF_OVERFLOW = EOF -1;//�I�[�o�[�t���[

//CFile�N���X���p�����Ă���
//�A�N�Z�X�w��q�͌p�������N���X���ǂ�������
class CTextFile : public CFile
{
	// �R���X�g���N�^
public:
    CTextFile();                         // �f�t�H���g�R���X�g���N�^
    CTextFile(const char* pszPath, const char* pszFlags);
                                         // �\�z�Ɠ����Ƀt�@�C�����J��
    CTextFile(const CTextFile& rother);  // �R�s�[�R���X�g���N�^

	//ModifyFlags�̓N���XCFile�ɑ��݂���
	//�h����A���ł��ꂼ�ꓯ�����O�A�����̊֐���錾���邱�Ƃ�
	//�I�[�o�[���C�h�Ƃ����B

private:
	//virtual���g���Ɖ��z�֐��ɂȂ�
	//���z�֐��͔h����A���̊֐��ŌĂ΂ꂽ�I�[�o�[���C�h�֐����A
	//�Ăяo���N���X�ɍ��킹�ĐU�蕪����
    virtual bool ModifyFlags(const char* pszSource, char* pszDest, int nSize);
                   // �t���O�̒���
                   
public:
    int WriteString(const char* pszString);  // ���������������
    int ReadLine(char* buffer, unsigned int nSize);   // �P�s�ǂݏo���֐�
};


// ���������������
inline int CTextFile::WriteString(const char* pszString)
{
    return Write(pszString, strlen(pszString));
}
#endif