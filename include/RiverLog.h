#ifndef _RIVERLOG_H_
#define _RIVERLOG_H_

#include "Entity.h" // Virtual Class Entity : public Sprite

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class RiverLog : public Entity {
private:
protected:
public:
	RiverLog(void);
	~RiverLog(void);

	virtual void Move(float deltaTime);

};

#endif
