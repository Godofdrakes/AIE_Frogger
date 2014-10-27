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
	DrawString("Loading...", 0, 30);

}

void Loading::Destroy() {


}
