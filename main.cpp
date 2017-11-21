#include "DxLib.h"
#include <iostream>
#include <stdlib.h>
#include "enemy.h"

void chara_move(unsigned int color);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int count = 0;
	int x = 0, y = 0;
	unsigned int Cr = GetColor(0, 0, 255);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32);
	SetOutApplicationLogValidFlag(FALSE);

	Enemy enemy;
	Bullet bullet[100];

	enemy_init(&enemy);

	while (ProcessMessage() == 0) {
		ClearDrawScreen();
		SetDrawScreen( DX_SCREEN_BACK );

		enemy_act(&enemy);
		if (bullet->cnt <= 99) {
			bullet_locate(&enemy, bullet);
			bullet_act(bullet, 0, 3);
			bullet_act(bullet, -3, 3);
			bullet_act(bullet, 3, 3);
		}

		chara_move(Cr);

		ScreenFlip();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

void chara_move(unsigned int color) {

	int mouse_x, mouse_y;

	GetMousePoint(&mouse_x, &mouse_y);

	DrawCircle(mouse_x, mouse_y, 15, color, TRUE);
}