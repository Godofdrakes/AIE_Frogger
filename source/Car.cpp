#include "Car.h"

Car::Car(void) {
	speedX = w;
	speedY = 0;
	xMax = WINDOW_W;
	yMax = WINDOW_H;
	direction = 1.f;

}

Car::~Car(void) {


}

void Car::Move(float deltaTime) {
	x += (speedX*deltaTime)*direction;
	y += (speedY*deltaTime)*direction;

	if(direction < 0) {
		if(x+(w*.5f)<0) {x = xMax+(w*.5f);}
	} else if(direction > 0) {
		if(x-(w*.5f)>xMax) {x = 0-(w*.5f);}
	}
}

void Car::Direction(float set_direction) {
	direction = set_direction;
}

float Car::Direction() {
	return direction;
}
