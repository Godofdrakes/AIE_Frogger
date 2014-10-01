#include "MainMenuState.h"

extern const unsigned int WINDOW_W;
extern const unsigned int WINDOW_H;

MainMenuState::MainMenuState(void) {}
MainMenuState::~MainMenuState(void) {}

void MainMenuState::Init() {
	iArcadeMarquee = new Sprite();
	iArcadeMarquee->SetSprite( CreateSprite( "./images/Space-Invaders-Marquee.png", WINDOW_W, WINDOW_H, true ), WINDOW_W, WINDOW_H );
	iArcadeMarquee->SetPos(WINDOW_W/2, WINDOW_H/2);
}

void MainMenuState::Update(float deltaTime, StateMachine* a_pSM) {
	MoveSprite(iArcadeMarquee->sprite, iArcadeMarquee->x, iArcadeMarquee->y);
}

void MainMenuState::Draw() {
	DrawSprite(iArcadeMarquee->sprite);
}

void MainMenuState::Destroy() {
	DestroySprite(iArcadeMarquee->sprite);
}
