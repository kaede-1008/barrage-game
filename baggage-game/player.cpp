#include "Dxlib.h"
#include "player.h"
#include "enemy.h"



void player_move(void) {	//player‚Ì“®ì‚Ì§Œä

	int mouse_x, mouse_y;
	unsigned int color = GetColor(0, 0, 255);

	GetMousePoint(&mouse_x, &mouse_y);

	DrawCircle(mouse_x, mouse_y, 15, color, TRUE);
}

void player_shot(void) {	//player‚Ì’e

	int mouse_x, mouse_y;
	unsigned int color = GetColor(0, 128, 225);

}

void player_hit(Bullet *bullet) {	//“–‚½‚è”»’è


}