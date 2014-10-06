#include "Sprite.h"

Sprite::Sprite(void) {
	w = 32;
	h = 32;
	x = 32;
	y = 32;
	spriteID = -1;
	drawFromCenter = true;
}

Sprite::~Sprite(void) {}

float Sprite::X() { return x; }
float Sprite::Y() { return y; }
int Sprite::W() { return w; }
int Sprite::H() { return h; }
int Sprite::SpriteID() { return spriteID; }
bool Sprite::DrawFromCenter() { return drawFromCenter; }

void Sprite::X(float set_x) { x = set_x; }
void Sprite::Y(float set_y) { y = set_y; }
void Sprite::W(int set_w) { w = set_w; }
void Sprite::H(int set_h) { h = set_h; }
void Sprite::SpriteID(int set_sprite) { spriteID = set_sprite; }
void Sprite::DrawFromCenter(bool set_draw) { drawFromCenter = set_draw; }
