/*　ゲームの処理をここで走らせている　*/

#include"Main.h"
#include"Settexture.h"
#include"Dinput.h"
#include"BackGround.h"
#include"Balloon.h"
#include"hornet.h"
#include"Cloud.h"
#include"Goal.h"
#include"Countdown.h"

/*最初の三秒間止めるためのカウント*/
static int GameCount = 0;

void ManagerRun()
{
	/*ここで1足していく*/
	GameCount++;

	/*3秒間過ぎると動き始める*/
	if (GameCount > 200)
	{
		BalloonControl();
		HornetControl();
		BackControl();
		CloudControl();
		Goalcountrol();
		CountControl();
	}

	BackDraw();
	HornetDraw();
	CloudDraw();
	GoalDraw();
	BalloonDraw();
	RainCloudDraw();

	/*カウントダウンは最初の３秒間経つと消えるように*/
	if (GameCount < 210)
	{
		CountDraw();
	}

}