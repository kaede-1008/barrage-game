#pragma once

#include "enemy.h"
#define PLAYER_SHOT1 3
#define PLAYER_SHOT2 400

typedef struct {

	int flag, pattern, kind, img, hp_max, hp;
	double x, y, ang;

} Player;

void player_move(void);
void player_shot(void);
void player_hit(Bullet *bullet);