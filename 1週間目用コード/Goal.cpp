/*　ゴール(クリアの為に必要)　*/

#include<Windows.h>
#include<d3dx9.h>
#include"Main.h"
#include"Goal.h"

#define GAMESPEED 1.5

CHARCTER_STATE g_Goal = { 4500.f,400.f,128.f };

static float x = 0;

void GoalDraw()
{
	CUSTOMVERTEX Goal[]
	{
		{ g_Goal.x - g_Goal.scale + x, g_Goal.y - g_Goal.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Goal.x + g_Goal.scale + x, g_Goal.y - g_Goal.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Goal.x + g_Goal.scale + x, g_Goal.y + g_Goal.scale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Goal.x - g_Goal.scale + x, g_Goal.y + g_Goal.scale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	g_pD3Device->SetTexture(0, g_pTexture[GOAL_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Goal, sizeof(CUSTOMVERTEX));
}

void Goalcountrol()
{
	x -= GAMESPEED;
}