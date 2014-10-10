#include "RiverLog.h"

RiverLog::RiverLog(void) {
	speedX = w;
	speedY = h;
	xMax = WINDOW_W;
	yMax = WINDOW_H;

}

RiverLog::~RiverLog(void) {

}

void RiverLog::Move(float deltaTime) {
	x += (speedX*deltaTime);
	y += (speedY*deltaTime);

	if(speedX < 0) {
		if(x+(w*.5f)<0) {x = xMax+(w*.5f);}
	} else if(speedX > 0) {
		if(x-(w*.5f)>xMax) {x = 0-(w*.5f);}
	}

}
