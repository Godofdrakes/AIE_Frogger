#ifndef _WINSTATE_H_
#define _WINSTATE_H_

#include <iostream>
#include <cassert>
#include <vector>

#include "AIE.h" // AIE Framework
#include "godqol.h" // My QoL library

#include "BaseState.h" // Class BaseState
#include "GameState.h" // Class GameState : public BaseState
#include "StateMachine.h" // Class StateMachine

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class WinState : public BaseState {
private:
protected:
public:
	WinState(void);
	~WinState(void);

	void Init(); // Create all objects
	void Update(float deltaTime, StateMachine* a_pSM); // Call update functions for all objects

	void Draw(); // Draw all objects
	void Destroy(); // Call destroy functions for all objects

};

#endif
