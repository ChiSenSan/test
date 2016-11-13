//create.cpp

#include "create.h"

//�f�t�H���g�R���X�g���N�^
Stage::Stage(){
	srand(time(NULL));
}

//�������R���X�g���N�^
Stage::Stage(const int ty, const int tx)
{
	yNum = ty;
	xNum = tx;
	count = 0;
	srand(time(NULL));
}

//�R�s�[�R���X�g���N�^
Stage::Stage(Stage& Copy){
	srand(time(NULL));
}

//�f�X�g���N�^
Stage::~Stage(){
}

bool Stage::CreateStage(int* t_array, const int ny, const int nx, const int bector)
{
	if(t_array == NULL){
		return false;
	}
	t_array[(ny*xNum) + nx] = 0;
	while(1){
		
		unsigned short flags = LookAround(t_array, ny, nx, bector);
		
		cout << "Counts :" << count++ << " : " << flags <<"(x,y)="<<nx<<","<<ny<<endl;
		
		//�t���O�ɒu������
		bool up    =  flags       & 0x01;
		bool down  = (flags >> 1) & 0x01;
		bool left  = (flags >> 2) & 0x01;
		bool right = (flags >> 3) & 0x01;
		bool way   = (flags >> 4) & 0x01;
		
		int num;
		int state = 0;
		if(!flags || count >1000){
			return true;//�����s���ꏊ���Ȃ����true��Ԃ�
		}
		else if(flags == 16){
			//if(!t_array[(ny*xNum) + nx])
			//	return true;
			 
			num = bector;
			up = down = left = right = true;
			state = 10;
		}
		else{
			num = rand()%4;
			way = false;
		}
		
		if(num == 0 && up){//���
			t_array[((ny-1)*xNum) + nx] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny-2,nx,0);
			}
		}
		else if(num == 1 && down){//����
			t_array[((ny+1)*xNum) + nx] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny+2,nx,1);
			}
		}
		else if(num == 2 && left){//����
			t_array[(ny*xNum) + (nx-1)] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny,nx-2,2);
			}
		}
		else if(num == 3 && right){//�E��
			t_array[(ny*xNum) + (nx+1)] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny,nx+2,3);
			}
		}
		else{
		}//�Ȃɂ����Ȃ�
	}
}

unsigned short Stage::LookAround(int* t_array, const int ny, const int nx,const int bector)
{
	unsigned short flags = 0;
	
	 //�����
	if(ny-2 > 0){
		if(t_array[((ny-2)*xNum) + nx]){
			flags = flags | 1; //��1�r�b�g�𗧂Ă� 
		}
		else{
			if(bector == 0 && t_array[((ny-1)*xNum) + nx])
				flags = flags | 16;
		}
	}
	//������
	if(ny+2 < yNum-1){
		if(t_array[((ny+2)*xNum) + nx]){
			flags = flags | 2; //��2�r�b�g�𗧂Ă� 
		}
		else{
			if(bector == 1 && t_array[((ny+1)*xNum) + nx])
				flags = flags | 16;
		}
	}
	//������
	if(nx-2 > 0){
		if(t_array[(ny*xNum) + (nx-2)]){
			flags = flags | 4; //��3�r�b�g�𗧂Ă� 
		}
		else{
			if(bector == 2 && t_array[(ny*xNum) + (nx-1)])
				flags = flags | 16;
		}
	}
	//�E����
	if(nx+2 < xNum-1){
		if(t_array[(ny*xNum) + (nx+2)]){
			flags = flags | 8; //��4�r�b�g�𗧂Ă� 
		}
		else{
			if(bector == 3 && t_array[(ny*xNum) + (nx+1)])
				flags = flags | 16;
		}
	}
	
	return flags;
}
