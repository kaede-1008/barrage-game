#pragma once

typedef struct {
	double x, y, vx, vy, sp, ang;
	int flag, cnt = 1, pattern, kind, hp, hp_max, img;
	int bar_time, bar_kind, color, status, w_time, lo_flag;
} Enemy;

typedef struct {
	float x, y, vx, vy, sp, ang, inx, iny;
	int is_Bullet = 0, cnt = 0, pattern, kind, img, is_sp = 0;
	unsigned int color;
} Bullet;

void enemy_init(Enemy *enemy);
void enemy_act(Enemy *enemy);
void bullet_locate(Enemy *enemy, Bullet *bullet);
void bullet_act(Bullet *bullet);
void bullet_speed(Bullet *bullet);
int is_bullet(double x, double y);