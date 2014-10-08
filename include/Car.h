#ifndef _CAR_H_
#define _CAR_H_

#include "Entity.h"

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class Car : public Entity {
private:
protected:
public:
	Car(void);
	~Car(void);

	virtual void Move(float deltaTime);

};

#endif
