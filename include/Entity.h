#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Sprite.h"

class Entity : public Sprite {
private:
protected:
	float speedX, speedY;
	int xMax, yMax;

public:
	Entity::Entity(void);
	Entity::~Entity(void);

	virtual void Move(float deltaTime) = 0;
};

#endif
