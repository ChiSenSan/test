//draw.cpp
#include "draw.h"

//デフォルトコンストラクタ
DrawWindow::DrawWindow(){
	table = NULL;
}

//引数付きコンストラクタ
DrawWindow::DrawWindow(const int WinX, const int WinY, const int Bsize)
{
	BlockSize = Bsize;
	Crevice = 1;
	yNum = WinY / Bsize;
	xNum = WinX / Bsize;
	Num = xNum * yNum;
	table = new int[Num];
}

//コピーコンストラクタ
DrawWindow::DrawWindow(DrawWindow& Copy){
}

//デストラクタ
DrawWindow::~DrawWindow(){
	delete [] table;
	delete [] object;
}

bool DrawWindow::SetTable(int* t_array, BlockObject* arr_obj)
{
	
	//配列が定義されているか
	if(table == NULL){
		return false;
	}
	
	//サイズは一致しているか
	if(sizeof(table) != sizeof(t_array)){
		return false;
	}
	
	int i;
	for(i=0; i<Num; i++){
		table[i] = t_array[i];
	}
	
	object = arr_obj;
	
	DrawBlock();
	return true;
}

void DrawWindow::DrawBlock()
{
	int i,j;
	
	for(i=0; i<yNum; i++){
		for(j=0; j<xNum; j++){
			int num = (i*xNum)+j;
			int ay = (BlockSize * i) + Crevice;
			int ax = (BlockSize * j) + Crevice;
			int by = ay + BlockSize - (Crevice * 2);
			int bx = ax + BlockSize - (Crevice * 2);
			
			object[num].SetObject(ay,ax,by,bx,table[num]);
			object[num].DrawObject();
			
		}
	}
	//ScreenFlip();
}
	