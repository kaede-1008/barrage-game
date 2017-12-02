#include "DxLib.h"
#include <iostream>
#include <stdlib.h>
#include "enemy.h"
#include "player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int count = 0;
	int x = 0, y = 0;

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32);
	SetOutApplicationLogValidFlag(FALSE);

	Enemy enemy;
	Bullet bullet[500];

	enemy_init(&enemy);

	while (ProcessMessage() == 0) {
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);

		enemy_act(&enemy);
		if (bullet->cnt <= 499) {
			bullet_locate(&enemy, bullet);
			bullet_act(bullet);
		}

		player_move();

		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}