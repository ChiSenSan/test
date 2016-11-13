//create.h
#ifndef _CREATE_H__
#define _CREATE_H__

#include <iostream.h>
#include <DxLib.h>
#include <stdlib.h>
#include <time.h>

class Stage
{
	public:
	Stage();//�R���X�g���N�^
	Stage(const int ty, const int tx);
	Stage(Stage& Copy);//�R�s�[�R���X�g���N�^
	~Stage();//�f�X�g���N�^
	
	private:
	int yNum;
	int xNum;
	int count;
	
	private:
	bool CreateStage(int* t_array, const int ny, const int nx, const int bector);//�X�e�[�W����
	
	private:
	unsigned short LookAround(int* t_array, const int ny, const int nx, const int bector);
	
	public:
	void GetStage(int* t_array, const int fy, const int fx)//�X�e�[�W�擾
	{
		if(!CreateStage(t_array, fy, fx, 0)){
			cout << "CreateStage : error" << endl;
		}
	}
};
#endif