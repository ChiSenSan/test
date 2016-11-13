//create.cpp

#include "create.h"

//デフォルトコンストラクタ
Stage::Stage(){
	srand(time(NULL));
}

//引数つきコンストラクタ
Stage::Stage(const int ty, const int tx)
{
	yNum = ty;
	xNum = tx;
	count = 0;
	srand(time(NULL));
}

//コピーコンストラクタ
Stage::Stage(Stage& Copy){
	srand(time(NULL));
}

//デストラクタ
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
		
		//フラグに置き換え
		bool up    =  flags       & 0x01;
		bool down  = (flags >> 1) & 0x01;
		bool left  = (flags >> 2) & 0x01;
		bool right = (flags >> 3) & 0x01;
		bool way   = (flags >> 4) & 0x01;
		
		int num;
		int state = 0;
		if(!flags || count >1000){
			return true;//もう行く場所がなければtrueを返す
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
		
		if(num == 0 && up){//上へ
			t_array[((ny-1)*xNum) + nx] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny-2,nx,0);
			}
		}
		else if(num == 1 && down){//下へ
			t_array[((ny+1)*xNum) + nx] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny+2,nx,1);
			}
		}
		else if(num == 2 && left){//左へ
			t_array[(ny*xNum) + (nx-1)] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny,nx-2,2);
			}
		}
		else if(num == 3 && right){//右へ
			t_array[(ny*xNum) + (nx+1)] = state;
			if(way)
				return true;
			else{
				//t_array[(ny*xNum) + nx] = 0;
				CreateStage(t_array,ny,nx+2,3);
			}
		}
		else{
		}//なにもしない
	}
}

unsigned short Stage::LookAround(int* t_array, const int ny, const int nx,const int bector)
{
	unsigned short flags = 0;
	
	 //上方向
	if(ny-2 > 0){
		if(t_array[((ny-2)*xNum) + nx]){
			flags = flags | 1; //第1ビットを立てる 
		}
		else{
			if(bector == 0 && t_array[((ny-1)*xNum) + nx])
				flags = flags | 16;
		}
	}
	//下方向
	if(ny+2 < yNum-1){
		if(t_array[((ny+2)*xNum) + nx]){
			flags = flags | 2; //第2ビットを立てる 
		}
		else{
			if(bector == 1 && t_array[((ny+1)*xNum) + nx])
				flags = flags | 16;
		}
	}
	//左方向
	if(nx-2 > 0){
		if(t_array[(ny*xNum) + (nx-2)]){
			flags = flags | 4; //第3ビットを立てる 
		}
		else{
			if(bector == 2 && t_array[(ny*xNum) + (nx-1)])
				flags = flags | 16;
		}
	}
	//右方向
	if(nx+2 < xNum-1){
		if(t_array[(ny*xNum) + (nx+2)]){
			flags = flags | 8; //第4ビットを立てる 
		}
		else{
			if(bector == 3 && t_array[(ny*xNum) + (nx+1)])
				flags = flags | 16;
		}
	}
	
	return flags;
}
