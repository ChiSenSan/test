#ifndef _DRAW_H__
#define _DRAW_H__

#include <DxLib.h>
#include <iostream.h>
#include "object.h"

class DrawWindow
{
	public:
	DrawWindow();//デフォルトコンストラクタ
	DrawWindow(const int WinX, const int WinY, const int Bsize);
	DrawWindow(DrawWindow& Copy);//コピーコンストラクタ
	~DrawWindow();//デストラクタ
	
	private:
	BlockObject* object;//ポインタとしてインスタンス作成
	
	private:
	int BlockSize; //ブロックサイズ
	int Crevice; //隙間サイズ
	int* table; //動的配列ポインタ
	
	public:
	int yNum; //配列y方向要素数
	int xNum; //配列x方向要素数
	int Num;
	
	public:
	//配列をコピーして表示
	bool SetTable(int* t_array, BlockObject* arr_obj);
	
	private:
	//表示
	void DrawBlock();
};
#endif //_DRAW_H__