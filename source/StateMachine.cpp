#include "StateMachine.h"

StateMachine::StateMachine(void) {}

StateMachine::~StateMachine(void) {}

void StateMachine::PushState(BaseState* gameState) {
	// Addes the passed state to the end of the list (meaning it is now considered the active state)
	stateStack.push_back(gameState);
	gameState->Init();

}

BaseState* StateMachine::PopState() {
	BaseState* lastState = stateStack.back(); // Get the pointer to the last state in the list in a seperate variable
	stateStack.pop_back(); // Remove the pointer to the last state in the list
	lastState->Destroy(); // Call the (now removed) lastState's Destroy function (this is not deleting the object)
	return lastState; // Return the pointer to the lastState
	// REMEMBER TO DELETE THE POINTER
	// Basically just call { delete StateMachine::PopState(); }

}

BaseState* StateMachine::SwitchState(BaseState* gameState) {
	// Essentaly this is the same is PopState but it automatically adds the state passed to it.
	BaseState* lastState = stateStack.back();
	lastState->Destroy();

	stateStack.pop_back();
	stateStack.push_back(gameState);
	gameState->Init();

	return lastState;
	// REMEMBER TO DELETE THE POINTER
	// Basically just call { delete StateMachine::SwitchState(new gameState); }

}

void StateMachine::Update(float deltaTime) {
	// Calls the Update function of the currently active (last) state in the list.
	stateStack.back()->Update(deltaTime, this);

}

void StateMachine::Draw() {
	// Calls the Draw function of the currently active (last) state in the list.
	stateStack.back()->Draw();

}
