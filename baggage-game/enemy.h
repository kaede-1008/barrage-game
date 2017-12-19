#pragma once

typedef struct {
	double vx, vy, sp, ang;	//速度x成分, 速度y成分, 速度, 角度
	int x, y, flag, cnt = 1, pattern, kind, hp, hp_max, img;
	int bar_time, bar_kind, color, status, w_time;
} Enemy;

typedef struct {
	float x, y, vx, vy, sp, ang, inx, iny;  //弾の座標, 弾の速さの成分, 速さ, 角度, 初期位置
	int is_Bullet = 0, cnt = 0, pattern, kind, img, is_sp = 0;
	unsigned int color;
} Bullet;

void enemy_init(Enemy *enemy);
void enemy_act(Enemy *enemy);
void bullet_locate(Enemy *enemy, Bullet *bullet);
void bullet_act(Bullet *bullet);
void bullet_speed(Bullet *bullet);
int is_bullet(double x, double y);