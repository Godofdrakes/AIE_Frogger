#include "MainMenuState.h"

extern const int WINDOW_W;
extern const int WINDOW_H;
extern bool doExit;

MainMenuState::MainMenuState(void) {}
MainMenuState::~MainMenuState(void) {}

void MainMenuState::Init() {
	iArcadeMarquee = new Sprite();
	iArcadeMarquee->W(WINDOW_W); iArcadeMarquee->H(WINDOW_H);
	iArcadeMarquee->SpriteID(CreateSprite("./images/Space-Invaders-Marquee.png", iArcadeMarquee->W(), iArcadeMarquee->H(), true));
	iArcadeMarquee->X(WINDOW_W/2); iArcadeMarquee->Y(WINDOW_H/2);
}

void MainMenuState::Update(float deltaTime, StateMachine* a_pSM) {
	MoveSprite(iArcadeMarquee->SpriteID(), iArcadeMarquee->X(), iArcadeMarquee->Y());
	
	if (IsKeyDown(GLFW_KEY_SPACE)) { a_pSM->PushState( new GameState() ); }
	if (IsKeyDown(GLFW_KEY_ESCAPE)) { delete a_pSM->PopState(); }
}

void MainMenuState::Draw() {
	DrawSprite(iArcadeMarquee->SpriteID());
}

void MainMenuState::Destroy() {
	DestroySprite(iArcadeMarquee->SpriteID());
	doExit = true;
}
