#ifndef _DRAW_H__
#define _DRAW_H__

#include <DxLib.h>
#include <iostream.h>
#include "object.h"

class DrawWindow
{
	public:
	DrawWindow();//�f�t�H���g�R���X�g���N�^
	DrawWindow(const int WinX, const int WinY, const int Bsize);
	DrawWindow(DrawWindow& Copy);//�R�s�[�R���X�g���N�^
	~DrawWindow();//�f�X�g���N�^
	
	private:
	BlockObject* object;//�|�C���^�Ƃ��ăC���X�^���X�쐬
	
	private:
	int BlockSize; //�u���b�N�T�C�Y
	int Crevice; //���ԃT�C�Y
	int* table; //���I�z��|�C���^
	
	public:
	int yNum; //�z��y�����v�f��
	int xNum; //�z��x�����v�f��
	int Num;
	
	public:
	//�z����R�s�[���ĕ\��
	bool SetTable(int* t_array, BlockObject* arr_obj);
	
	private:
	//�\��
	void DrawBlock();
};
#endif //_DRAW_H__