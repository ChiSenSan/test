//game.cpp
//簡単なゲーム

#include "DxLib.h"
#include<iostream.h>

#define WIN_SIZE_X 620
#define WIN_SIZE_Y 480
#define BLOCK_SIZE 20

int blocks[100][100];

unsigned short SetBlock(int x, int y );

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int) 
{
    ChangeWindowMode(TRUE);
    if( DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
    {
        return -1 ;			// エラーが起きたら直ちに終了
    }
    SetDrawScreen(DX_SCREEN_BACK);
    
    int MaxX=WIN_SIZE_X,MaxY=WIN_SIZE_Y;
    int TableX=MaxX/BLOCK_SIZE;
    int TableY=MaxY/BLOCK_SIZE;
   // int Cr=GetPixel(0,0,255);
    int ax,ay,bx,by;
    int i,j;
    
    
    //ステージ生成
    
    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++){
            if(i<=TableY && j<=TableX)
                blocks[j][i]=1;
            else
                blocks[j][i]=0;
        }
            
    }
    
//    if(SetBlock(1,1)!=1)
//        return -2;
    SetBlock(1,1);
    for(i=0; i<=TableY; i++)
    {        
        for(j=0;j<=TableX ;j++)
        {
            ax=j*BLOCK_SIZE;
            ay=i*BLOCK_SIZE;
            bx=ax+BLOCK_SIZE;
            by=ay+BLOCK_SIZE;
            if(blocks[j][i]==1){
                DrawBox(ax, ay, bx-1, by-1, GetColor(0,0,255), TRUE);
            }
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

unsigned short SetBlock(int x, int y )
{
    unsigned short flag=0;
    
    cout << "test" <<endl;
    
    blocks[y][x]=0;
    
    while(flag!=2)
    {
        switch(GetRand(4))
        {
            case 0://上 
                 cout<<"up"<<endl;

                if(blocks[x-2][y]==1 ){
                    cout<<"detect"<<endl;
                    blocks[x-1][y]=0;
                    flag=SetBlock(x,y-2);
                    
                }
                break;
                
            case 1://下
                cout << "down" <<endl;
                if(blocks[x+2][y]==1 && x>=0){
                    cout<<"detect"<<endl;
                    blocks[x+1][y]=0;
                    flag=SetBlock(x,y+2);
                }
                
                break;
                
            case 2://右
                cout<<"right"<<endl;
                if(blocks[x][y+2]==1 ){
                    cout<<"detect"<<endl;
                    blocks[x][y+1]=0;
                    flag=SetBlock(x+2,y);
                }
                
                break;
                
            case 3://左
                cout<<"left"<<endl;
                if(blocks[x][y-2]==1 && y>=0){
                    cout<<"detect"<<endl;
                    blocks[x][y-1]=0;
                    flag=SetBlock(x-2,y);
                }
                
                break;
                
            default:
                cout << "err" <<endl;
                
        }
        if(    blocks[y+2][x]==0 &&  blocks[y-2][x]==0 
           &&  blocks[y][x+2]==0 &&  blocks[y][x-2]==0 )
            break;
            flag=2;
                
    }
    
    return 2;
    
}