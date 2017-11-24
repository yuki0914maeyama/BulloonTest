/*Å@ç≈èâÇÃéOïbä‘é~ÇﬂÇÈà◊Ç≈Ç∑Å@*/

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"

#define GAMESPEED 1.5

static int GameCount = 0;

CHARCTER_STATE g_count = { 640.f,360.f,128.f };

void CountDraw()
{
	GameCount++;

	CUSTOMVERTEX count[]
	{
			{ g_count.x - g_count.scale, g_count.y - g_count.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_count.x + g_count.scale, g_count.y - g_count.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_count.x + g_count.scale, g_count.y + g_count.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_count.x - g_count.scale, g_count.y + g_count.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	if (GameCount < 60)
	{
		g_pD3Device->SetTexture(0, g_pTexture[COUNT3_TEX]);
	}
	else if (GameCount < 120)
	{
		g_pD3Device->SetTexture(0, g_pTexture[COUNT2_TEX]);
	}
	else if (GameCount < 170)
	{
		g_pD3Device->SetTexture(0, g_pTexture[COUNT1_TEX]);
	}
	else if (GameCount > 170)
	{
		g_pD3Device->SetTexture(0, g_pTexture[COUNTGO_TEX]);
	}

	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, count, sizeof(CUSTOMVERTEX));
}

void CountControl()
{
	g_count.x -= GAMESPEED;
}