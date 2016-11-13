#include "DxLib.h"

#define WIN_SIZE_Y 480
#define WIN_SIZE_X 620

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int) 
{
    ChangeWindowMode(TRUE);
    if( DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
    {
        return -1 ;			// エラーが起きたら直ちに終了
    }
    SetDrawScreen(DX_SCREEN_BACK);
    
    int MaxX=WIN_SIZE_X,MaxY=WIN_SIZE_Y;
    int TableX=MaxX/20;
    int TableY=MaxY/20;
    int Cr=GetPixel(0,0,255);
    int ax,ay,bx,by;
    int i,j;
    
    ax=20;
    ay=20;
    bx=40;
    by=40;
    
    for(i=0; i<=TableY; i++)
    {        
        for(j=0;j<=TableX ;j++)
        {
            ax=j*20;
            ay=i*20;
            bx=ax+20;
            by=ay+20;
            DrawBox(ax, ay, bx-1, by-1, GetPixel(0,0,255), TRUE);
        }
    }
    ScreenFlip();
        
    while(1)
    {
    if(CheckHitKey(KEY_INPUT_ESCAPE)!=0)
    {
	break;				// キー入力待ち
    }
}
        
        DxLib_End() ;
        return 0;
}