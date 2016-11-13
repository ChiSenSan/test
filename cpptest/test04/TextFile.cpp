// TextFile.cpp
#include <iostream.h>
#include <stdio.h>
#include "MainDefs.h"
#include "TextFile.h"

// デフォルトコンストラクタ
CTextFile::CTextFile()
{
}

// 構築と同時にファイルを開く
CTextFile::CTextFile(const char* pszPath,  //これは誤り
                     const char* pszFlags) //: CFile(pszPath, pszFlags)
{
	Open(pszPath, pszFlags);//こうする
}

// コピーコンストラクタ
CTextFile::CTextFile(const CTextFile& rother) : CFile(rother)
{
}

// フラグの調整
bool CTextFile::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
	cout << "CTextFile::ModifyFlags" << endl;
    bool bBinary;  // 'b' の指定があるかどうか

    bBinary = (strchr(pszSource, 'b') != NULL);

    // フラグが多すぎるときは false を返す
    if((int)strlen(pszSource) - bBinary > nSize - 1)
        return false;

    // 強制的にテキストモードで開きます
    // 'b' 以外の文字だけコピーします
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
// １行読み出す関数
// 改行コードは切り捨てられます
// 戻り値は文字列の長さになります
// バッファに入りきらないとき（オーバーフロー）は TF_OVERFLOW を返します
int CTextFile::ReadLine(char* buffer, size_t nSize)
{
    if(IsValid() == false)
        return EOF;
    //m_pfileはprivateのメンバなので公開されていない
    //継承元で指定子を"protected"にする必要がある
    if(fgets(buffer, nSize, m_pfile) == NULL)
        return EOF;

    size_t nLength = strlen(buffer);

    // 最後に改行のない場合は、オーバーフローか、改行のない最後の行です
    // 改行のない最後の行がたまたまバッファの長さ－１の長さの時もオーバーフローと判定します
    if(buffer[nLength - 1] != '\n')
        return (nLength == nSize - 1) ? TF_OVERFLOW : nLength;

    nLength -= 1;
    buffer[nLength] = 0;
    return nLength;
}