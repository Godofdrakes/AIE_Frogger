#include "Sprite.h"

Sprite::Sprite(void) {}

Sprite::~Sprite(void) {}

void Sprite::SetSprite(int set_srpite, int set_w, int set_h) {
	w = set_w;
	h = set_h;
	sprite = set_srpite;
}

void Sprite::SetPos(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}
