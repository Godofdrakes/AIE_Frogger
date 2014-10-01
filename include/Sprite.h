#ifndef _SPRITE_H_
#define _SPRITE_H_

class Sprite {
private:
protected:
public:
	float x, y;
	int w, h;
	unsigned sprite;

	Sprite(void);
	~Sprite(void);

	void SetSprite(int set_srpite, int set_w, int set_h); // Used as func(CreateSprite(), w, h) to hold the sprite's ID and dimentions.
	void SetPos(int set_x, int set_y);
};

#endif
