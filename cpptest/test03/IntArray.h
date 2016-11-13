// IntArray.h

#ifndef __INTARRAY_H_INCLUDED__
#define __INTARRAY_H_INCLUDED__

#include <iostream.h>
#include <process.h>
#include <memory.h>

//#define ELEM(array)   (sizeof (array) / sizeof *(array))

class CIntArray
{
    // メンバ変数
private://外部に公開しない
    //int m_anum[100];  // 配列
	int* m_pnum; //動的配列
	int m_nNumOf; //配列の要素数
	
    // コンストラクタ・デストラクタ
    //コピーコンストラクタ
public:
    CIntArray(const int nNumOf);
    ~CIntArray();
    CIntArray(CIntArray& rother) ;//このクラスの参照を引数に取る

    // メンバへのアクセス関数
public:
    int Get(const int index);
    void Set(const int index, const int value);

    // インデックスのチェック
private:
    void CheckIndex(const int index);

    // その他の情報の取得
public:
    //bool Success();  // メモリの確保が成功したか
    //int NumOf();     // 配列の要素数
    //int SizeOf();    // 配列のサイズ
    
    //ヘッダの中でインライン
    // メモリの確保が成功したか
    bool Success()
    {
        return m_pnum != NULL;
    }

    // 配列の要素数
    int NumOf() const //メンバ変数を変更しない関数の意味
    {
        return m_nNumOf;
    }

    // 配列のサイズ
    int SizeOf()
    {
        return m_nNumOf * sizeof *m_pnum;
    }

};

#endif