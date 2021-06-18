/*
	This Kinds of files is the Stander Vertion.
	Support At:www.github.com/
*/

#include<windows.h>
#include <bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#define MAX 32767
#define red  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED)
#define green   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN)
#define normal   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7)
#define blue  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE)
#define yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
#define pink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
#define pureblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define KEY_DOWM(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize(2)
using namespace std;
void mouthclick(void){
	using namespace std;
	int m = 1;
	bool h1 = false; 
	POINT point;
    while(true){
        if(KEY_DOWN('E')){
            if(m == 2){
                if(!h1){
                    h1 = true;
                    POINT    pt;
                    RECT    rt;
                    ::GetCursorPos(&pt);
                    rt.left=rt.right=pt.x;
                    rt.top=rt.bottom=pt.y;
                    rt.right++;
                    rt.bottom++;
                    ::ClipCursor(&rt);
                }
            }
            if(m == 1){
                if(!h1){
                    h1 = true;
                    GetCursorPos(&point);
                }
                SetCursorPos(point.x,point.y);
            }
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
            Sleep(5);
        }else if(KEY_DOWN('Q')){
            if(m == 2)::ClipCursor(NULL);
            break;
        }else{
            if(h1){
                if(m == 2)::ClipCursor(NULL);
                h1 = false;
            }
            Sleep(1);
        }
    }
    return ;
}

int lowjs(int n){
	if(n == 1)return 1;	
	else return lowjs(n - 1) * n; 
}

int highplus(char a1[],char b1[]){
		#include <bits/stdc++.h>
		using namespace std;
    	int a[MAX]={0},b[MAX]={0},c[MAX]={0},la,lb,lc,i,x;
    	cin >> a1 >> b1;
    	la=strlen(a1);
    	lb=strlen(b1);
    	for(i=0;i<=la-1;i++){a[la-i]=a1[i]-48;}
    	for(i=0;i<=lb-1;i++){b[lb-i]=b1[i]-48;}
      	lc=1,x=0;
    	while(lc<=la || lc<=lb){c[lc]=a[lc]+b[lc]+x,x=c[lc]/10,c[lc]%=10,lc++;}
    	c[lc]=x;
    	if(c[lc]==0){lc--;}
    	for(i=lc;i>=1;i--){cout<<c[i];}
    	cout<<endl;	
		return c[i];
}
int* highjs(long int n,int *a)
{
	int bor[52][10000];
    bor[0][0]=1;
    bor[0][1]=1;
    bor[1][0]=1;
    bor[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int r=1;r<=bor[i-1][0];r++)
        bor[i][r]=bor[i-1][r]*i;
        bor[i][0]=bor[i-1][0];
        for(int k=1;k<=bor[i][0];k++)
        {
            if(bor[i][k]>9){
                if(k==bor[i][0])bor[i][0]++;
                bor[i][k+1]+=bor[i][k]/10;
                bor[i][k]%=10;
            }
        }
    }
    for(int i=1;i<=n;i++)
    for(int r=1;r<=bor[n][0];r++)
    bor[n+1][r]+=bor[i][r];
    bor[n+1][0]=bor[n][0];
    for(int k=1;k<=bor[n+1][0];k++)
    {
        if(bor[n+1][k]>9){
            if(k==bor[n+1][0])bor[n+1][0]++;
                bor[n+1][k+1]+=bor[n+1][k]/10;
                bor[n+1][k]%=10;
        }
    }
    for(int i=bor[n+1][0];i>0;i--)bor[n+1][i] = a[i];
//    return bor[n+1][0];
}// cout<<bor[n+1][i];


void TopWindow(HWND &hWnd) {
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}//HWND hWnd=GetForegroundWindow(); 需要使用此代码获取句柄 


