//object.h
#ifndef _OBJECT_H__
#define _OBJECT_H__

#include <iostream.h>
#include <DxLib.h>

class BlockObject
{
	//�R���X�g���N�^�E�f�X�g���N�^
	public:
	BlockObject();
	BlockObject(BlockObject& Copy);
	//~BlockObject();
	
	private:
	int ax,ay; //������W
	int bx,by; //�E�����W
	short state; //���
	
	public:
	//�I�u�W�F�N�g�P�̐ݒ�
	void SetObject(const int ny, const int nx, const int  my, 
											const int mx, const int flag);
	void DrawObject();
	//�����蔻���Ԃ�
	unsigned short HitObject(const int ny, const int nx, 
											const int  my, const int mx);
	
};

#endif