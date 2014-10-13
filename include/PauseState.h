#ifndef _PAUSESTATE_H_
#define _PAUSESTATE_H_

#include <iostream>
#include <cassert>
#include <vector>
#include <string> // std::string
#include <vld.h> //http://vld.codeplex.com/

#include "AIE.h" // AIE Framework
#include "godqol.h" // My QoL library

#include "BaseState.h" // Class BaseState
#include "Player.h" // Class Player : public Entity
#include "Car.h" // Class Car : public Entity
#include "RiverLog.h" // Class RiverLog : public Entity
#include "RiverWater.h" // Class RiverWater : public Entity
#include "StateMachine.h" // Class StateMachine : public BaseState

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class PauseState : public BaseState {
private:
	// Strings
	std::string askConfirmQuit;

protected:
public:
	PauseState(void);
	~PauseState(void);

	void Init(); // Create all objects
	void Update(float deltaTime, StateMachine* a_pSM); // Call update functions for all objects

	void Draw(); // Draw all objects
	void Destroy(); // Call destroy functions for all object

};

#endif
