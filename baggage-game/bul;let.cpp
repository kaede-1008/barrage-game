#include "DxLib.h"
#include "bullet.h"
#include <math.h>



Shot shot1_1[BULLET_MAX];
Shot shot1_2[BULLET_MAX];


void shot_main(double x, double y, int n) {
	int is_bullet1_1 = -1;
	int is_bullet1_2 = -1;

	is_bullet1_1 = serch_bullet1();
	is_bullet1_2 = serch_bullet2();

	if (is_bullet1_1 != -1) {
		set_bullet1(is_bullet1_1, x, y);
	}
	if (is_bullet1_2 != -1) {
		set_bullet2(is_bullet1_2, x, y);
	}
	move_bullet1(n);
	move_bullet2(n);
}

int serch_bullet1(void) {
	int i;

	for (i = 0; i < BULLET_MAX; i++) {
		if (shot1_1[i].flag == 0) {
			return i;
		}
	}
	return -1;
}

void set_bullet1(int n, double x, double y) {
	shot1_1[n].flag = 1;
	shot1_1[n].angle = 0;
	shot1_1[n].r = 1;
	shot1_1[n].x = x;
	shot1_1[n].y = y;
	shot1_1[n].cnt = 1;
	shot1_1[n].color = GetColor(255, 128, 128);
}

void move_bullet1(int n) {
	int i;
	double radian;

	for (i = 0; i < BULLET_MAX; i++) {
		if (shot1_1[i].flag == 1) {
			radian = (shot1_1[i].angle + 120) * PI / 180.0;
			if (n % 3 == 0) {
				shot1_1[i].x += shot1_1[i].r * cos(radian);
				shot1_1[i].y += shot1_1[i].r * sin(radian);
				shot1_1[i].r += 0.3;
				shot1_1[i].angle += (14 + i)*shot1_1[i].cnt;
				shot1_1[i].cnt += shot1_1[i].cnt;
			}
			DrawCircleAA((int)shot1_1[i].x, (int)shot1_1[i].y, 2, 32, shot1_1[i].color, TRUE);
		}
		if (shot1_1[i].r >= 25) {
			shot1_1[i].flag = 0;
		}
	}
}

int serch_bullet2(void) {
	int i;

	for (i = 0; i < BULLET_MAX; i++) {
		if (shot1_2[i].flag == 0) {
			return i;
		}
	}
	return -1;
}

void set_bullet2(int n, double x, double y) {
	shot1_2[n].flag = 1;
	shot1_2[n].angle = 0;
	shot1_2[n].r = 1;
	shot1_2[n].x = x;
	shot1_2[n].y = y;
	shot1_2[n].cnt = 1;
	shot1_2[n].color = GetColor(255, 128, 128);
}

void move_bullet2(int n) {
	int i, j = 0;
	double radian;

	for (i = 0; i < BULLET_MAX; i++) {
		if (shot1_2[i].flag == 1) {
			radian = (shot1_2[i].angle + 120) * PI / 180.0;
			if (n % 3 == 0) {
				shot1_2[i].x += shot1_2[i].r * -(cos(radian));
				shot1_2[i].y += shot1_2[i].r * sin(radian);
				shot1_2[i].r += 0.3;
				shot1_2[i].angle += (14 + i)*shot1_2[i].cnt;
				shot1_2[i].cnt += shot1_2[i].cnt;
			}
			DrawCircleAA((int)shot1_2[i].x, (int)shot1_2[i].y, 2, 32, shot1_2[i].color, TRUE);
		}
		if (shot1_2[i].r >= 25) {
			shot1_2[i].flag = 0;
		}
	}
}