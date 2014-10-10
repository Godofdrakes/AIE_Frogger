#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <iostream>
#include <assert.h>
#include <vector>

#include "AIE.h"
#include "godqol.h"

#include "BaseState.h"
#include "Player.h"
#include "Car.h"
#include "RiverLog.h"
#include "RiverWater.h"
#include "StateMachine.h"

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class GameState : public BaseState {
private:
protected:
public:
	GameState(void);
	~GameState(void);

	void Init(); // Create all objects
	void Update(float deltaTime, StateMachine* a_pSM); // Call update functions for all objects

	void Draw(); // Draw all objects
	void Destroy(); // Call destroy functions for all objects

	void InitPlayer();
	void UpdatePlayer(Player* player, float deltaTime);

	// Currently I'm just making everything cars, but I'll have logs and a water object for the river later
	void InitCars();
	void UpdateCar(Car* car, float deltaTime);

	// Functions for the river
	void InitRiver();
	void UpdateRiver();

	// Collision checking
	bool CheckHit(Player &thePlayer, Car &theCar); // Is player touching car


};

#endif
