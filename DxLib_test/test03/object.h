//object.h
#ifndef _OBJECT_H__
#define _OBJECT_H__

#include <iostream.h>
#include <DxLib.h>

class BlockObject
{
	//コンストラクタ・デストラクタ
	public:
	BlockObject();
	BlockObject(BlockObject& Copy);
	//~BlockObject();
	
	private:
	int ax,ay; //左上座標
	int bx,by; //右下座標
	short state; //状態
	
	public:
	//オブジェクト１つの設定
	void SetObject(const int ny, const int nx, const int  my, 
											const int mx, const int flag);
	void DrawObject();
	//あたり判定を返す
	unsigned short HitObject(const int ny, const int nx, 
											const int  my, const int mx);
	
};

#endif