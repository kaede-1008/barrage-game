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

	if (enemy->y == 30) {	//å„Ç≈å∏ÇÁÇ∑
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

		bullet[bullet->cnt].x = enemy->x;	//íeÇ…ìGÇÃç¿ïWÇë„ì¸
		bullet[bullet->cnt].y = enemy->y;
		DrawCircleAA(bullet[bullet->cnt].x, bullet[bullet->cnt].y, 2, 32, bullet[bullet->cnt].color, TRUE);	//â~ÇÃï`âÊ
		bullet[bullet->cnt].is_Bullet = 1;

		bullet->cnt++;  //íeÇÃçXêV
	}
}

void bullet_act(Bullet *bullet) {

	int k = 0;

	for (k = 0; k < bullet->cnt; k++) {
		if (bullet[k].is_Bullet == 1) {
			if ( bullet[k].is_sp == 0 ) {
				bullet[k].inx = bullet[k].x;
				bullet[k].iny = bullet[k].y;
				bullet_speed(bullet);
			}
			if (bullet[k].inx > 320) {
				bullet[k].x -= 3;	//ÇªÇÍÇºÇÍÇÃíeÇÃç¿ïWçXêV
			}
			else {
				bullet[k].x += 3;
			}
			bullet[k].y += 3 * bullet[k].sp;
			DrawCircleAA(bullet[k].x, bullet[k].y, 2, 32, bullet[k].color, TRUE);
		}
	}
}

void bullet_speed(Bullet *bullet) {

	int k;
	for ( k = 0; k < bullet->cnt; k++ ) {

		bullet[k].sp = (bullet[k].iny - 280 ) / (bullet[k].inx - 320);
		bullet[k].is_sp = 1;

	}
	
}