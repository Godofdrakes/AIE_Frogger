#ifndef _CAR_H_
#define _CAR_H_

#include "Entity.h"

class Car : public Entity {
private:
protected:
public:
	Car(void);
	~Car(void);

	virtual void Move(float deltaTime);

};

#endif
