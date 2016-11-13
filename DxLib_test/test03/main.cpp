//main.cpp

#include <DxLib.h>
#include <iostream.h>
#include "draw.h"
#include "create.h"
#include "object.h"

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
    if( DxLib_Init() == -1)		// �c�w���C�u��������������
    {
        return -1 ;			// �G���[���N�����璼���ɏI��
	}
    SetDrawScreen(DX_SCREEN_BACK);
    
    DrawWindow draw(640, 480, 20);//�C���X�^���Xdraw��錾
    Stage stage(draw.yNum, draw.xNum); //�C���X�^���Xstage��錾
    
    BlockObject* object;//���I�z��|�C���^�Ƃ��ăC���X�^���X�쐬
    object = new BlockObject[draw.Num];
    
    //�z��Table���P�ŏ�����
    int* Table;
   	Table = new int [draw.Num];
    int i;
    for(i=0; i<draw.Num; i++){
    	Table[i]= 1;
    }
    
    stage.GetStage(Table, 1,1);
    
    //�z����R�s�[���ĕ\��
	if(!draw.SetTable(Table, object)){
		cout << "error!!!" << endl;
		DxLib_End() ;
       	delete [] object;
        delete [] Table;
    	return -1;
	}
	ScreenFlip();
	
	//�v���C���[���W�i�I�u�W�F�N�g�̍���j
	int ply = 25;
	int plx = 25;
	//�u���b�N�T�C�Y
	int pbs = 10;
	
	BlockObject player;
	while(1)
    {
    	int ay = ply;
    	int ax = plx;
    	int by = ply+pbs-1;
    	int bx = plx+pbs-1;
    	
    	int xadd = 0;
    	int yadd = 0;
    	//�L�[���͌n
    	if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
			break;				// �L�[���͑҂�
		}
		else if(CheckHitKey(KEY_INPUT_UP)!=0){
			yadd -= 1;
		}
		else if(CheckHitKey(KEY_INPUT_DOWN)!=0){
			yadd += 1;
		}
		else if(CheckHitKey(KEY_INPUT_LEFT)!=0){
			xadd -= 1;
		}
		else if(CheckHitKey(KEY_INPUT_RIGHT)!=0){
			xadd += 1;
		}
		else{
		}
		
		unsigned short flag = 0;
		if(xadd || yadd){
			int i;
			unsigned short temp = 0;
			for(i=0; i<draw.Num; i++){
				flag = object[i].HitObject(ay+yadd,ax+xadd,by+yadd,bx+xadd);
				temp = temp | flag;
				if(flag){
					Table[i] = 2;
					if(flag >= 16)
						Table[i] = 0;
				}
				else{
					Table[i] = 1;
				}
			}
			flag = temp & 0x0F;
			if(flag)
				cout<<"flag : "<<flag<<endl;
			
			ClearDrawScreen();
			player.SetObject(ay,ax,by,bx,10);
    		player.DrawObject();
			
			//�z����R�s�[���ĕ\��
			if(!draw.SetTable(Table, object)){
				cout << "error!!!" << endl;
				DxLib_End() ;
       			delete [] object;
        		delete [] Table;
    			return -1;
			}
			ScreenFlip();
			//�t���O�ɒu������
			bool up    =  flag       & 0x01;
			bool down  = (flag >> 1) & 0x01;
			bool left  = (flag >> 2) & 0x01;
			bool right = (flag >> 3) & 0x01;
			
			if(up){
				cout<<"cant up"<<endl;
			}
			
			if(!up && yadd == 1){
				ply += yadd;
			}
			else if(!down && yadd == -1){
				ply += yadd;
			}
			else if(!left && xadd > 0){
				plx += xadd;
			}
			else if(!right && xadd < 0){
				plx += xadd;
			}
			else{
			}
		}
    }
    
    DxLib_End() ;
    delete [] object;
    delete [] Table;
    return 0;
}