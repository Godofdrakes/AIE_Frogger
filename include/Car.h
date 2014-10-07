#ifndef _CAR_H_
#define _CAR_H_

#include "Entity.h"

extern const int TILE_X;
extern const int TILE_Y;
extern const unsigned int WINDOW_W;
extern const unsigned int WINDOW_H;

class Car : public Entity {
private:
protected:
	float direction; // 1 for right, -1 for left
public:
	Car(void);
	~Car(void);

	virtual void Move(float deltaTime);

	void Direction(float set_direction);
	float Direction();

};

#endif
