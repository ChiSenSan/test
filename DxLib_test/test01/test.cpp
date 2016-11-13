#include <DxLib.h>
#include <stdio.h>

#define X_DEFAULT 200
#define Y_DEFAULT 100
#define WIN_SIZE_X 480
#define WIN_SIZE_Y 620
#define BLOCK_SIZE 20

void DrawWindow(int Handle, int Cr, int* px, int* py);

// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int) 
{
	ChangeWindowMode(TRUE);
	printf("a");

	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);
         SetDrawScreen(DX_SCREEN_BACK);
            
    int blockX=(WIN_SIZE_X-BLOCK_SIZE)/BLOCK_SIZE;
    int blockY=(WIN_SIZE_Y-BLOCK_SIZE)/BLOCK_SIZE;
    int stageBlock[620][480];
    int i,j;

	int x=X_DEFAULT,y=Y_DEFAULT;
	int Handle;
	unsigned int Cr;//白色のカラー
        
         for(i=0; i<blockY; i++)
    {
        for(j=0; j<blockX; j++)
        {
            stageBlock[i][j]=1;
        }
    }

	Handle = LoadGraph("画像/キャラクタ01.png");
	Cr=GetColor(0,255,255);

	while(1){
		if(CheckHitKey(KEY_INPUT_ESCAPE)!=0){
			break;				// キー入力待ち
		}
                for(i=0; i<blockY; i++)
    {
        for(j=0; j<blockX; j++)
        {
            if(stageBlock[i][j]==1)
            {
                int ay=i*BLOCK_SIZE ,ax=j*BLOCK_SIZE;
                int by=(i+1)*BLOCK_SIZE ,bx=(j+1)*BLOCK_SIZE;
                
                ay=ay+2;
                ax=ax+2;
                by=by-2;
                bx=bx-2;
                ClearDrawScreen();
                DrawBox(ax, ay, bx-1, by-1, Cr, TRUE);
                ScreenFlip();
            }
        }
    }
                
		DrawWindow(Handle,Cr,&x,&y);
		
	}

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;				// ソフトの終了 
}

void  DrawWindow(int Handle, int Cr, int* px, int* py)
{

	int x=*px,y=*py;
 	ClearDrawScreen();
        DrawBox(100,100,200-1,200-1,Cr,TRUE);
	DrawGraph(x, y, Handle, TRUE );
	DrawFormatString(250, 1, Cr, "( %d , %d )", x,y);

	     if(CheckHitKey(KEY_INPUT_UP)==1)    y=y-2;
	else if(CheckHitKey(KEY_INPUT_DOWN)==1)  y=y+2;
	else if(CheckHitKey(KEY_INPUT_LEFT)==1)  x=x-2;
	else if(CheckHitKey(KEY_INPUT_RIGHT)==1) x=x+2;
	ScreenFlip();
	*px=x;
	*py=y;
}