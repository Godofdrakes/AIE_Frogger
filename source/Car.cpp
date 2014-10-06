#include "Car.h"

void Car::Move(float deltaTime) {
	x = x += speedX*deltaTime;
}
