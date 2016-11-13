// Cstruct1.cpp
#include <iostream.h>

class CInt
{
public:
    int m_num;
	//コンストラクタは型不要
	CInt();
	//オーバーロードします
    CInt(int n);//引数付きコンストラクタ
    void Disp();
    //デストラクタ
    ~CInt();
};

// コンストラクタ
CInt::CInt()
{
	m_num = 0;
}
//オーバーロード
CInt::CInt(int n)
{
    m_num = n;
}

//デストラクタ
CInt::~CInt()
{
	cout << "デストラクタを起動しています" << endl;
	cout << "メンバm_num : " << m_num << endl;
}
// メンバ変数の表示
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