// File.h
#ifndef __FILE_H__INCLUDED__
#define __FILE_H__INCLUDED__

#include <stdio.h>

class CFile
{
    // �����o�ϐ�
protected://�p����Ō���邪���J�͂���Ă��Ȃ�
    FILE* m_pfile;  // �t�@�C��
private:
    bool  m_bCopy;  // �R�s�[�R���X�g���N�^�ō��ꂽ���ǂ���

    // �R���X�g���N�^�E�f�X�g���N�^
// �\�z�Ɠ����Ƀt�@�C�����J��
public:
	CFile();
    CFile(const char* pszPath, const char* pszFlags);
    CFile(const CFile& rother);  // �R�s�[�R���X�g���N�^
    ~CFile();                    // �f�X�g���N�^

    // �t�@�C���̊J��
public:
    bool Open(const char* pszFile, const char* pszFlags);
                   // �t�@�C�����J��
    void Close();  // �t�@�C�������

private:
    virtual bool ModifyFlags(const char* pszSource, char* pszDest, int nSize);
                   // �t���O�̒���

    // �t�@�C���̑���
public:
    size_t Read(void* pData, size_t nSize);         // �t�@�C������ǂݏo��
    size_t Write(const void* pData, size_t nSize);  // �t�@�C���ɏ�������

    // �]��
public:
    bool IsValid() const;  // m_pfile �̒l���L�����ǂ���
    bool Eof();  // �t�@�C���̏I�[�ɒB�������ǂ���
};

// m_pfile �̒l���L�����ǂ���
inline bool CFile::IsValid() const
{
    return (m_pfile != NULL);
}

#endif