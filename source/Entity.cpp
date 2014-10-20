#include "Entity.h"

Entity::Entity(void) {
	speedX = w;
	speedY = h;
	xMax = WINDOW_W;
	yMax = WINDOW_H;


}

Entity::~Entity(void) {

}

// Setters
void Entity::SpeedX(float set_speedX) {speedX = set_speedX;}
void Entity::SpeedY(float set_speedY) {speedY = set_speedY;}
void Entity::XMax(int set_xMax) {xMax = set_xMax;}
void Entity::YMax(int set_xMax) {yMax = set_xMax;}

// Getters
float Entity::SpeedX() {return speedX;}
float Entity::SpeedY() {return speedY;}
int Entity::XMax() {return xMax;}
int Entity::YMax() {return yMax;}
