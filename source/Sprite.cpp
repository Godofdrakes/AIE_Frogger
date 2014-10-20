#include "Sprite.h"

Sprite::Sprite(void) {
	w = TILE_X; // Default to the dimentions of the "tile"
	h = TILE_Y;
	x = TILE_X/2; // Default to the bottom left corner of the window
	y = TILE_Y/2;
	spriteID = -1;
	drawFromCenter = true;
}

Sprite::~Sprite(void) {}

// Getters
float Sprite::X() { return x; }
float Sprite::Y() { return y; }
int Sprite::W() { return w; }
int Sprite::H() { return h; }
int Sprite::SpriteID() { return spriteID; }
bool Sprite::DrawFromCenter() { return drawFromCenter; }

// Setters
void Sprite::X(float set_x) { x = set_x; }
void Sprite::Y(float set_y) { y = set_y; }
void Sprite::W(int set_w) { w = set_w; }
void Sprite::H(int set_h) { h = set_h; }
void Sprite::SpriteID(int set_sprite) { spriteID = set_sprite; }
void Sprite::DrawFromCenter(bool set_draw) { drawFromCenter = set_draw; }
