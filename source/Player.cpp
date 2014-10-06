#include "Player.h"

Player::Player(void) {
	keyUp = GLFW_KEY_W;
	keyDown = GLFW_KEY_S;
	keyLeft = GLFW_KEY_A;
	keyRight = GLFW_KEY_D;
	speedX = w;
	speedY = h;
	xMax = WINDOW_W;
	yMax = WINDOW_H;
	keyDelay = .16f; // Prevent pressing keys faster than this ammount of seconds
	currentKeyDelay = 0.f; // Seconds since last keypress

}

Player::~Player(void) {


}

void Player::Move(float deltaTime) {
	if(currentKeyDelay > 0.f) { currentKeyDelay -= deltaTime; }
	if(currentKeyDelay < 0.f) { currentKeyDelay = 0.f; }

	if(currentKeyDelay <= 0.f) {
		if(IsKeyDown(keyUp)) { y += speedY; currentKeyDelay += keyDelay; }
		if(IsKeyDown(keyDown)) { y += speedY*-1; currentKeyDelay += keyDelay; }
		if(IsKeyDown(keyLeft)) { x += speedX*-1; currentKeyDelay += keyDelay; }
		if(IsKeyDown(keyRight)) { x += speedX; currentKeyDelay += keyDelay; }
	}


	if(x+w>xMax) { x = xMax-h;} // Check X Min/Max
	else if(x<0) { x = 0;}

	if(y+h>yMax) { y = yMax-w;} // Check Y Min/Max
	else if(y<0) { y = 0;}

}
