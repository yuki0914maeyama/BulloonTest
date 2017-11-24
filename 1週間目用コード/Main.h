#ifndef MAIN_H
#define MAIN_H

#define SAFE_RELEASE(p){if(p){(p)->Release();(p)=NULL;}}

#include<windows.h>
#include<d3dx9.h>
#include<dsound.h>

/* 頂点構造体 */
struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

enum TEXTURE
{
	BACKGROUND_TEX,
	BACKGROUND_TEX2,
	BALLOON_TEX,
	HORNET_TEX,
	CLOUD_TEX,
	GOAL_TEX,
	RAIN_TEX,
	HP_TEX,
	SCORE_TEX,
	COUNT3_TEX,
	COUNT2_TEX,
	COUNT1_TEX,
	COUNTGO_TEX,
	TEXMAX
};

struct CHARCTER_STATE
{
	float x, y, scale;
};

extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為の配列
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス

#endif