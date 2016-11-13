//object.cpp

#include "object.h"

//�R���X�g���N�^
BlockObject::BlockObject()
{
	ax = ay = 0;
	bx = by = 0;
	state = 0;
}
//�R�s�[�R���X�g���N�^
BlockObject::BlockObject(BlockObject& Copy)
{
	ax = ay = 0;
	bx = by = 0;
	state = 0;
}
//�f�X�g���N�^
//BlockObject::~BlockObject{
//}

//���̃Z�b�g
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
		//state��0�̂Ƃ��͉������Ȃ�
	}
}

unsigned short BlockObject::HitObject(const int ny, const int nx, 
											const int  my, const int mx)
{
	unsigned short flags = 0;
	int sizeY = by - ay;
	int sizeX = bx - ax;
	
	if(((nx-bx)*(ax-mx)) > 0){
		//��
		if(ay == my){
			flags = flags | 1; //��1�r�b�g�𗧂Ă�
		}
		//��
		else if(by == ny){
			flags = flags | 2; //��2�r�b�g�𗧂Ă�
		}
		else{
		}
	}
	if(((ny-by)*(ay-my)) > 0){
		//��
		if(ax == mx){
			flags = flags | 4; //��3�r�b�g�𗧂Ă�
		}
		//�E
		if(bx == nx){
			flags = flags | 8; //��4�r�b�g�𗧂Ă�
		}
		else{
		}
	}
	
	if(!state){
		flags = 16;
	}
	
	return flags;
}