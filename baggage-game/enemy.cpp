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
	enemy->lo_flag = 0;
}

void enemy_act(Enemy *enemy) {

	unsigned int e_color;

	e_color = GetColor(255, 0, 0);

	DrawCircle(enemy->x, enemy->y, 15, e_color, TRUE);
	enemy->cnt++;

	/*if (enemy->y == 30) {	//後で減らす
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
	}*/
	/*if (enemy->x == 400) {
	enemy->lo_flag = 1;
	}
	else if (enemy->x == 240) {
	enemy->lo_flag = 0;
	}

	if (enemy->lo_flag == 0) {
	enemy->x += 2;
	}
	else if (enemy->lo_flag == 1) {
	enemy->x -= 2;
	}*/
}

void bullet_locate(Enemy *enemy, Bullet *bullet) {

	if (enemy->cnt % 3 == 0) {

		bullet[bullet->cnt].color = GetColor(255, 128, 128);

		bullet[bullet->cnt].x = enemy->x;	//弾に敵の座標を代入
		bullet[bullet->cnt].y = enemy->y;
		DrawCircleAA((int)bullet[bullet->cnt].x, (int)bullet[bullet->cnt].y, 2, 32, bullet[bullet->cnt].color, TRUE);	//円の描画
		bullet[bullet->cnt].is_Bullet = 1;

		bullet->cnt++;  //弾の更新
	}
}

void bullet_act(Bullet *bullet) {

	int k = 0;

	for (k = 0; k < bullet->cnt; k++) {
		if (bullet[k].is_Bullet == 1) {
			if (bullet[k].is_sp == 0) {
				bullet[k].inx = bullet[k].x;
				bullet[k].iny = bullet[k].y;
				bullet_speed(bullet);
			}
			if (bullet[k].inx > 320) {
				bullet[k].x -= 3;	//それぞれの弾の座標更新
			}
			else {
				bullet[k].x += 3;
			}
			bullet[k].y += 3 * bullet[k].sp;
			if (is_bullet(bullet[k].x, bullet[k].y) == 1) {
				DrawCircleAA(bullet[k].x, bullet[k].y, 2, 32, bullet[k].color, TRUE);
			}
		}
	}
}

void bullet_speed(Bullet *bullet) {

	int k;
	for (k = 0; k < bullet->cnt; k++) {

		bullet[k].sp = (bullet[k].iny - 280) / (bullet[k].inx - 320);
		bullet[k].is_sp = 1;

	}
}

int is_bullet(double x, double y) {

	if (x > 0 && x < 640) {
		if (y > 0 && y < 480) {
			return 1;
		}
	}
	return 0;
}