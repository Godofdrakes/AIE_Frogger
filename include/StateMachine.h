#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void PushState(BaseState* gameState);
	BaseState* PopState();
	BaseState* SwitchState(BaseState* gameState);

	void Update(float deltaTime);
	void Draw();

private:
	std::list<BaseState*> stateStack;

};

#endif
