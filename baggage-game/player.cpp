#include "Dxlib.h"
#include "player.h"



void player_move(void) {

	int mouse_x, mouse_y;
	unsigned int color = GetColor(0, 0, 255);

	GetMousePoint(&mouse_x, &mouse_y);

	DrawCircle(mouse_x, mouse_y, 15, color, TRUE);
}

void player_shot(void) {

	int mouse_x, mouse_y;
	unsigned int color = GetColor(0, 128, 225);


}