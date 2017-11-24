#pragma once

typedef struct {
	double vx, vy, sp, ang;	//速度x成分, 速度y成分, 速度, 角度
	int x, y, flag, cnt = 1, pattern, kind, hp, hp_max, img;
	int bar_time, bar_kind, color, status, w_time;
} Enemy;

typedef struct {
	double x, y, vx, vy, sp, ang;
	int flag = 0, cnt = 0, pattern, kind, img;
	unsigned int color;
} Bullet;

void enemy_init(Enemy *enemy);
void enemy_act(Enemy *enemy);
void bullet_locate(Enemy *enemy, Bullet *bullet);
void bullet_act(Bullet *bullet);