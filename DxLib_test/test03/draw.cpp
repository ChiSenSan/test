//draw.cpp
#include "draw.h"

//�f�t�H���g�R���X�g���N�^
DrawWindow::DrawWindow(){
	table = NULL;
}

//�����t���R���X�g���N�^
DrawWindow::DrawWindow(const int WinX, const int WinY, const int Bsize)
{
	BlockSize = Bsize;
	Crevice = 1;
	yNum = WinY / Bsize;
	xNum = WinX / Bsize;
	Num = xNum * yNum;
	table = new int[Num];
}

//�R�s�[�R���X�g���N�^
DrawWindow::DrawWindow(DrawWindow& Copy){
}

//�f�X�g���N�^
DrawWindow::~DrawWindow(){
	delete [] table;
	delete [] object;
}

bool DrawWindow::SetTable(int* t_array, BlockObject* arr_obj)
{
	
	//�z�񂪒�`����Ă��邩
	if(table == NULL){
		return false;
	}
	
	//�T�C�Y�͈�v���Ă��邩
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
	