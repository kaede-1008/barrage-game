#pragma once

#define BULLET_MAX 150
#define PI 3.141592653589793

typedef struct {
	int flag, kind, cnt, state, time;
	double x, y, angle, spd, base_angle[1], rem_spd[1], r;
	unsigned int color;
} Shot;

void shot_main(double x, double y, int n);
int serch_bullet1(void);
void set_bullet1(int n, double x, double y);
void move_bullet1(int n);
int serch_bullet2(void);
void set_bullet2(int n, double x, double y);
void move_bullet2(int n);