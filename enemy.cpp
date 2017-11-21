#include "DxLib.h"
#include "enemy.h"
#include <math.h>

Enemy enemy;
Bullet bullet;

void enemy_init(Enemy *enemy) {

		enemy->x = 320;
		enemy->y = 30;
		enemy->flag = 1;
		enemy->pattern = 0;
		enemy->kind = 0;
		enemy->hp = 10000;
		enemy->hp_max = enemy->hp;
}

void enemy_act(Enemy *enemy) {

	unsigned int e_color;

	e_color = GetColor(255, 0, 0);

	DrawCircle(enemy->x, enemy->y, 15, e_color, TRUE);
	enemy->cnt++;

	if (enemy->y == 30) {	//Œã‚ÅŒ¸‚ç‚·
		enemy->x += 5;
		if (enemy->x == 625) {
			enemy->y += 5;
		}
	}
	else if (enemy->x == 625) {
		enemy->y += 5;
		if (enemy->y == 465) {
			enemy->x -= 5;
		}
	}
	else if (enemy->y == 465) {
		enemy->x -= 5;
		if (enemy->x == 15) {
			enemy->y -= 5;
		}
	}
	else if (enemy->x == 15) {
		enemy->y -= 5;
		if (enemy->y == 30) {
			enemy->x += 5;
		}
	}
}

void bullet_locate(Enemy *enemy, Bullet *bullet) {

	if (enemy->cnt % 3 == 0) {

		bullet[bullet->cnt].color = GetColor(255, 128, 128);

		bullet[bullet->cnt].x = enemy->x;	//’e‚É“G‚ÌÀ•W‚ğ‘ã“ü
		bullet[bullet->cnt].y = enemy->y;
		DrawCircle(bullet[bullet->cnt].x, bullet[bullet->cnt].y, 2, bullet[bullet->cnt].color, TRUE);	//‰~‚Ì•`‰æ
		bullet[bullet->cnt].flag = 1;

		bullet->cnt++;  //’e‚ÌXV
	}
}

void bullet_act(Bullet *bullet, int plus_x, int plus_y) {

	int k;

	for (k = 0; k < bullet->cnt; k++ ) {
		if (bullet[k].flag == 1) {
			bullet[k].x += plus_x;	//‚»‚ê‚¼‚ê‚Ì’e‚ÌÀ•WXV
			bullet[k].y += plus_y;
			DrawCircle(bullet[k].x, bullet[k].y, 2, bullet[k].color, TRUE);
		}
	}

}