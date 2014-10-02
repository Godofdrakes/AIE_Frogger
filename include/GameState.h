#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include "BaseState.h"
#include "Player.h"
#include "Entity.h"
#include "AIE.h"
#include "StateMachine.h"

class GameState : public BaseState {
private:
	Player* player;/*
	Entity* lane_A[3]; // Slower car lane
	Entity* lane_B[3]; // Faster car lane
	Entity* lane_C[3]; // River
	Entity* frogs[5]; // Each frog that muct be collected*/

protected:

public:
	GameState(void);
	~GameState(void);

	void Init(); // Create all objects
	void Update(float deltaTime, StateMachine* a_pSM); // Call update functions for all objects

	void Draw(); // Draw all objects
	void Destroy(); // Call destroy functions for all objects

	void MakePlayer();
	void UpdatePlayer(float deltaTime);
	void DestroyPlayer();

	// Currently I'm just making everything cars, but I'll have logs and a water object for the rivver later
	void MakeCars();
	void UpdateCars(float deltaTime);
	void DestroyCars();


};

#endif
