#pragma once

typedef struct {
	double vx, vy, sp, ang;	//���xx����, ���xy����, ���x, �p�x
	int x, y, flag, cnt = 1, pattern, kind, hp, hp_max, img;
	int bar_time, bar_kind, color, status, w_time;
} Enemy;

typedef struct {
	double x, y, vx, vy, sp, ang, inx, iny;  //�e�̍��W, �e�̑����̐���, ����, �p�x, �����ʒu
	int is_Bullet = 0, cnt = 0, pattern, kind, img, is_sp = 0;
	unsigned int color;
} Bullet;

void enemy_init(Enemy *enemy);
void enemy_act(Enemy *enemy);
void bullet_locate(Enemy *enemy, Bullet *bullet);
void bullet_act(Bullet *bullet);
void bullet_speed(Bullet *bullet);