#ifndef _BASESTATE_H_
#define _BASESTATE_H_

class StateMachine;

class BaseState
{
public:
	BaseState(void) {};
	~BaseState(void) {};

	virtual void Init() = 0;
	virtual void Update(float deltaTime, StateMachine* a_pSM) = 0;

	virtual void Draw() = 0;
	virtual void Destroy() = 0;

};

#endif
