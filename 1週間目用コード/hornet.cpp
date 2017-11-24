/*　蜂(障害物)の表示：行動　*/

#include<Windows.h>
#include<d3d9.h>
#include"hornet.h"
#include"Main.h"

#define GAMESPEED 1.5


CHARCTER_STATE g_hornet = { 700.f,300.f,64.f };

static float x = 0;
static float y = 0;

static int count = 0;

void HornetDraw()
{
	CUSTOMVERTEX Hornet[]
	{
		{ g_hornet.x - g_hornet.scale + x, g_hornet.y - g_hornet.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_hornet.x + g_hornet.scale + x, g_hornet.y - g_hornet.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_hornet.x + g_hornet.scale + x, g_hornet.y + g_hornet.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_hornet.x - g_hornet.scale + x, g_hornet.y + g_hornet.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[HORNET_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Hornet, sizeof(CUSTOMVERTEX));
}

void HornetControl()
{
	count++;

	x -= GAMESPEED;

	if (count > 60)
	{
		y -= 3.5;
	}
	else
	{
		y += 3.5;
	}

	if (count > 130)
	{
		count = 0;
	}

	/*ここで回転関数を使って下半身を揺らせれるように*/
}
