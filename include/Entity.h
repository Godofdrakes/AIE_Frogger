#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Sprite.h" // Class Sprite

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class Entity : public Sprite {
private:
protected:
	float speedX, speedY; // Directional speeds
	int xMax, yMax; // Movement limits

public:
	Entity(void);
	~Entity(void);

	virtual void Move(float deltaTime) = 0;

	// Setters
	void SpeedX(float set_speedX);
	void SpeedY(float set_speedY);
	void XMax(int set_XMax);
	void YMax(int set_YMax);

	// Getters
	float SpeedX();
	float SpeedY();
	int XMax();
	int YMax();

};

#endif
