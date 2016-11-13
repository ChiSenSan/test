// TextFile.h
#ifndef __TEXTFILE_H__INCLUDED__
#define __TEXTFILE_H__INCLUDED__

#include <stdio.h>
#include <string.h>
#include "File.h"

const int TF_OVERFLOW = EOF -1;//オーバーフロー

//CFileクラスを継承している
//アクセス指定子は継承したクラスをどう扱うか
class CTextFile : public CFile
{
	// コンストラクタ
public:
    CTextFile();                         // デフォルトコンストラクタ
    CTextFile(const char* pszPath, const char* pszFlags);
                                         // 構築と同時にファイルを開く
    CTextFile(const CTextFile& rother);  // コピーコンストラクタ

	//ModifyFlagsはクラスCFileに存在する
	//派生先、元でそれぞれ同じ名前、引数の関数を宣言することを
	//オーバーライドという。

private:
	//virtualを使うと仮想関数になる
	//仮想関数は派生先、元の関数で呼ばれたオーバーライド関数を、
	//呼び出しクラスに合わせて振り分ける
    virtual bool ModifyFlags(const char* pszSource, char* pszDest, int nSize);
                   // フラグの調整
                   
public:
    int WriteString(const char* pszString);  // 文字列を書き込む
    int ReadLine(char* buffer, unsigned int nSize);   // １行読み出す関数
};


// 文字列を書き込む
inline int CTextFile::WriteString(const char* pszString)
{
    return Write(pszString, strlen(pszString));
}
#endif