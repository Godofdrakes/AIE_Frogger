#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Sprite.h"

extern const int TILE_X;
extern const int TILE_Y;
extern const unsigned int WINDOW_W;
extern const unsigned int WINDOW_H;

class Entity : public Sprite {
private:
protected:
	float speedX, speedY;
	int xMax, yMax;

public:
	Entity(void);
	~Entity(void);

	virtual void Move(float deltaTime) = 0;
};

#endif
