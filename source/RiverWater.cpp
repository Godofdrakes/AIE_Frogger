#include "RiverWater.h"

RiverWater::RiverWater(void) {
	speedX = 0;
	speedY = 0;
	xMax = WINDOW_W;
	yMax = WINDOW_H;

}

RiverWater::~RiverWater(void) {

}

void RiverWater::Move(float deltaTime) {
	// Does nothing. Just here cause it's a virtual and thus is required.
}
