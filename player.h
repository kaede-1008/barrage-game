#pragma once

#define PLAYER_SHOT1 3;
#define PLAYER_SHOT2 400

typedef struct{
	
	int flag, pattern, kind, img;
	double x, y, ang;

} Player;

void player_move(void);