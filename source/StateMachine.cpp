#include "StateMachine.h"

StateMachine::StateMachine(void) {}

StateMachine::~StateMachine(void) {}

void StateMachine::PushState(BaseState* gameState) {
	stateStack.push_back(gameState);
	gameState->Init();

}

BaseState* StateMachine::PopState() {
	BaseState* lastState = stateStack.back();
	stateStack.pop_back();
	lastState->Destroy();
	return lastState;

}

BaseState* StateMachine::SwitchState(BaseState* gameState) {
	BaseState* lastState = stateStack.back();
	lastState->Destroy();

	stateStack.pop_back();
	stateStack.push_back(gameState);
	gameState->Init();

	return lastState;

}

void StateMachine::Update(float deltaTime) {
	stateStack.back()->Update(deltaTime, this);

}

void StateMachine::Draw() {
	stateStack.back()->Draw();

}
