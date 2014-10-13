#ifndef _RIVERWATER_H_
#define _RIVERWATER_H_

#include "Entity.h"

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

/*
	The river is a totally stationary object. No logic required.

*/

class RiverWater : public Entity {
private:
protected:
public:
	RiverWater(void);
	~RiverWater(void);

	virtual void Move(float deltaTime);

};

#endif
