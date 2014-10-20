#ifndef _FAILSTATE_H_
#define _FAILSTATE_H_

#include "AIE.h" // AIE Framework
#include "godqol.h" // My QoL library

#include "BaseState.h" // Virtual Class BaseState
#include "GameState.h" // Class GameState : public BaseState
#include "StateMachine.h" // Class StateMachine

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class FailState : public BaseState {
private:
protected:
public:
	FailState(void);
	~FailState(void);

	void Init();
	void Update(float deltaTime, StateMachine* a_pSM);

	void Draw();
	void Destroy();

};

#endif
