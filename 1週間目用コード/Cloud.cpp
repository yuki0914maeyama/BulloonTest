/* ` â_(è·äQï®) ` */

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"
#include"Cloud.h"

#define GAMESPEED 1.5


CHARCTER_STATE g_cloud = { 1400.f,150.f,128.f };
CHARCTER_STATE g_Rain = { g_cloud.x,g_cloud.y + 105.f,64.f };

static float x = 0;

static int TimeCount = 0;
static int LoadCount = 0;

void CloudDraw()
{
	CUSTOMVERTEX cloud[]
	{
		{ g_cloud.x - g_cloud.scale + x, g_cloud.y - g_cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_cloud.x + g_cloud.scale + x, g_cloud.y - g_cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_cloud.x + g_cloud.scale + x, g_cloud.y + g_cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_cloud.x - g_cloud.scale + x, g_cloud.y + g_cloud.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	g_pD3Device->SetTexture(0, g_pTexture[CLOUD_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cloud, sizeof(CUSTOMVERTEX));
}

void RainCloudDraw()
{
	TimeCount++;

	if (TimeCount > 180)
	{
		LoadCount++;

		CUSTOMVERTEX rain[]
		{
			{ g_Rain.x - g_Rain.scale + x, g_Rain.y - g_Rain.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_Rain.x + g_Rain.scale + x, g_Rain.y - g_Rain.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_Rain.x + g_Rain.scale + x, g_Rain.y + g_Rain.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_Rain.x - g_Rain.scale + x, g_Rain.y + g_Rain.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};
		g_pD3Device->SetTexture(0, g_pTexture[RAIN_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, rain, sizeof(CUSTOMVERTEX));

		if (LoadCount > 60)
		{
			TimeCount = 0;
			LoadCount = 0;
		}
	}
}

void CloudControl()
{
	x -= GAMESPEED;
}