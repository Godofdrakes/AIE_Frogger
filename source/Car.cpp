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
	x = x += speedX*deltaTime;
}
