/*　風船の表示：行動　*/

#include<Windows.h>
#include<d3d9.h>
#include<dinput.h>
#include"Dinput.h"
#include"Main.h"

#define WIDTH	1280
#define	HEIGHT	720

static float Gravity = 1.2;
float y = 0;

CHARCTER_STATE g_balloon = { 300.f,400.f,64.f };

void BalloonDraw()
{
	CUSTOMVERTEX Balloon[]
	{
		{ g_balloon.x - g_balloon.scale, g_balloon.y - g_balloon.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_balloon.x + g_balloon.scale, g_balloon.y - g_balloon.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_balloon.x + g_balloon.scale, g_balloon.y + g_balloon.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_balloon.x - g_balloon.scale, g_balloon.y + g_balloon.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[BALLOON_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Balloon, sizeof(CUSTOMVERTEX));
}

void BalloonControl()
{
	KEYSTATE key[256];
	KeyCheckDinput(&key[DIK_SPACE], DIK_SPACE);

	static int cnt;

	/*重力を足していって下に落ちていくように*/
	y += Gravity;

	/*SPEACEボタンを押している間は浮く*/
	if (key[DIK_SPACE] == ON)
	{
		y -= 6;
	}

	/*離すと最後に少し上に上昇するように*/
	if (key[DIK_SPACE] == RELEASE)
	{
		cnt = 10;
	}
	
	if (--cnt > 0)
	{
		y -= 3;
	}

	/*当たり判定関数を使う*/

}