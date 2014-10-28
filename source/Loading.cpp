#include "Loading.h"

Loading::Loading(void) {
	timeToWait = 2.5f;
	timeSpent = 0.f;

}

Loading::~Loading(void) {


}


void Loading::Init() {

}

void Loading::Update(float deltaTime, StateMachine* a_pSM) {
	if(timeSpent >= timeToWait) { delete a_pSM->SwitchState( new MainMenuState() ); return; }
	timeSpent += deltaTime;
}

void Loading::Draw() {
	DrawString(WINDOW_NAME.c_str(), 170, TILE_Y*14);
	DrawString("By Urias", 170, TILE_Y*13);
	DrawString("Loading...", 0, TILE_Y*1);

}

void Loading::Destroy() {


}
