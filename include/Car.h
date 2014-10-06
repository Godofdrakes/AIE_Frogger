#ifndef _CAR_H_
#define _CAR_H_

#include "Entity.h"

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
