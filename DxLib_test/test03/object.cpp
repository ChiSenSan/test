//object.cpp

#include "object.h"

//コンストラクタ
BlockObject::BlockObject()
{
	ax = ay = 0;
	bx = by = 0;
	state = 0;
}
//コピーコンストラクタ
BlockObject::BlockObject(BlockObject& Copy)
{
	ax = ay = 0;
	bx = by = 0;
	state = 0;
}
//デストラクタ
//BlockObject::~BlockObject{
//}

//情報のセット
void BlockObject::SetObject(const int ny, const int nx, const int  my, 
											const int mx, const int flag)
{
	state = flag;
	
	ay = ny;
	ax = nx;
	by = my;
	bx = mx;
}

void BlockObject::DrawObject()
{
	if(state == 1){
		DrawBox(ax, ay, bx, by, GetColor(0,0,255), TRUE);
	}
	else if(state == 2){
		DrawBox(ax, ay, bx, by, GetColor(255,0,0), TRUE);
	}
	else if(state == 10){
		DrawBox(ax, ay, bx, by, GetColor(255,255,255), TRUE);
	}
	else{
		//DrawBox(ax, ay, bx, by, GetColor(255,255,255), TRUE);
		//stateが0のときは何もしない
	}
}

unsigned short BlockObject::HitObject(const int ny, const int nx, 
											const int  my, const int mx)
{
	unsigned short flags = 0;
	int sizeY = by - ay;
	int sizeX = bx - ax;
	
	if(((nx-bx)*(ax-mx)) > 0){
		//上
		if(ay == my){
			flags = flags | 1; //第1ビットを立てる
		}
		//下
		else if(by == ny){
			flags = flags | 2; //第2ビットを立てる
		}
		else{
		}
	}
	if(((ny-by)*(ay-my)) > 0){
		//左
		if(ax == mx){
			flags = flags | 4; //第3ビットを立てる
		}
		//右
		if(bx == nx){
			flags = flags | 8; //第4ビットを立てる
		}
		else{
		}
	}
	
	if(!state){
		flags = 16;
	}
	
	return flags;
}