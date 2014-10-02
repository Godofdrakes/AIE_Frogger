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
	keyDelay = .33f;
	currentKeyDelay = 0.f;

}

Player::~Player(void) {


}

void Player::Move(float deltaTime) {
	if(currentKeyDelay > 0.f) { currentKeyDelay -= deltaTime; }
	if(IsKeyDown(keyUp) && currentKeyDelay <= 0.f ) { y += speedY; currentKeyDelay += keyDelay; }
	if(IsKeyDown(keyDown) && currentKeyDelay <= 0.f ) { y += speedY*-1; currentKeyDelay += keyDelay; }
	if(IsKeyDown(keyLeft) && currentKeyDelay <= 0.f ) { x += speedX*-1; currentKeyDelay += keyDelay; }
	if(IsKeyDown(keyRight) && currentKeyDelay <= 0.f ) { x += speedX; currentKeyDelay += keyDelay; }

	if(x+w>xMax) { x = xMax-h;}
	if(x<0) { x = 0;}
	if(y+h>yMax) { y = yMax-w;}
	if(y<0) { y = 0;}

}
