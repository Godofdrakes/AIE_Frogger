#include "Car.h"

Car::Car(void) {
	speedX = w;
	speedY = h;
	xMax = WINDOW_W;
	yMax = WINDOW_H;

}

Car::~Car(void) {

}

void Car::Move(float deltaTime) {
	x += (speedX*deltaTime);
	y += (speedY*deltaTime);

	if(speedX < 0) { // If the car goes off the side of the screen we move it to the other side
		if(x+(w*.5f)<0) {x = xMax+(w*.5f);}
	} else if(speedX > 0) {
		if(x-(w*.5f)>xMax) {x = 0-(w*.5f);}
	}

}
