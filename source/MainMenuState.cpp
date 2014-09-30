#include "MainMenuState.h"

extern const unsigned int WINDOW_W;
extern const unsigned int WINDOW_H;

MainMenuState::MainMenuState(void) {}
~MainMenuState::MainMenuState(void) ()

void MainMenuState::Init() {
	iArcadeMarquee = CreateSprite( "./images/Space-Invaders-Marquee.png", WINDOW_W, WINDOW_H, true );
}

void MainMenuState::Update(float deltaTime, StateMachine* a_pSM) {
	MoveSprite(iArcadeMarquee, WINDOW_W, WINDOW_H);
}

void MainMenuState::Draw() {
	DrawSprite(iArcadeMarquee);
}

void MainMenuState::Destory() {
	DestroySprite(iArcadeMarquee);
}
