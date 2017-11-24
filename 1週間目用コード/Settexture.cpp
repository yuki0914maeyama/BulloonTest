/*　画像の設定：作成：貼り付けを行っています　*/

#include<Windows.h>
#include<d3dx9.h>
#include"main.h"

void Settexture()
{
	/*ここを徹底的に勉強する事*/
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

/*createtexture*/
void CreateTexture(const char* text, TEXTURE texture_ID)
{
	D3DXCreateTextureFromFileEx(
		g_pD3Device,
		TEXT(text),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 255, 0),
		NULL,
		NULL,
		&g_pTexture[texture_ID]);
}

void Loadtexture()
{
	//頂点に入れるデータを設定
	g_pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	CreateTexture("Test.jpg", BACKGROUND_TEX);
	CreateTexture("Test.jpg", BACKGROUND_TEX2);
	CreateTexture("風船2.png", BALLOON_TEX);
	CreateTexture("蜂2.png", HORNET_TEX);
	CreateTexture("雷雲2.png", CLOUD_TEX);
	CreateTexture("雷2.png", RAIN_TEX);
	CreateTexture("カウントダウン3.png", COUNT3_TEX);
	CreateTexture("カウントダウン2.png", COUNT2_TEX);
	CreateTexture("カウントダウン1.png", COUNT1_TEX);
	CreateTexture("カウントダウン0.png", COUNTGO_TEX);

}