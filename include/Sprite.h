#ifndef _SPRITE_H_
#define _SPRITE_H_

extern const int TILE_X;
extern const int TILE_Y;

class Sprite {
private:
protected: // Lowercase is the variable ( x ), uppercase is the function ( X() )
	float x, y; // Position of the sprite
	int w, h; // Dimentions of the sprite
	int spriteID; // Sprite identifier to pass to the AIE framework. When this is set it will be changed to a positive number. If it is still a negitive then there is no sprite and should not be drawn.
	bool drawFromCenter; // Should the sprite be drawn from the center (true) or from the top-left (false)

public:
	Sprite(void);
	~Sprite(void);

	// Getters
	float X();
	float Y();
	int W();
	int H();
	int SpriteID();
	bool DrawFromCenter();

	// Setters
	void X(float set_x);
	void Y(float set_y);
	void W(int set_w);
	void H(int set_h);
	void SpriteID(int set_sprite);
	void DrawFromCenter(bool set_draw);
};

#endif
