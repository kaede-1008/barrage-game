#include "Dxlib.h"
#include "player.h"
#include "enemy.h"



void player_move(void) {	//playerの動作の制御

	int mouse_x, mouse_y;
	unsigned int color = GetColor(0, 0, 255);

	GetMousePoint(&mouse_x, &mouse_y);

	DrawCircle(mouse_x, mouse_y, 15, color, TRUE);
}

void player_shot(void) {	//playerの弾

	int mouse_x, mouse_y;
	unsigned int color = GetColor(0, 128, 225);

}

void player_hit(Bullet *bullet) {	//当たり判定


}