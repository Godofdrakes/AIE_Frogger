#ifndef _SPRITE_H_
#define _SPRITE_H_

class Sprite {
private:
protected:
	float x, y; // Lowercase is the variable ( x ), uppercase is the function ( X() )
	int w, h;
	int spriteID;

public:
	Sprite(void);
	~Sprite(void);

	float X();
	float Y();
	int W();
	int H();
	int SpriteID();

	void X(float set_x);
	void Y(float set_y);
	void W(int set_w);
	void H(int set_h);
	void SpriteID(int set_sprite);
};

#endif
