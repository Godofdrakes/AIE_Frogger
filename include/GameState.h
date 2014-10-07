#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include <iostream>
#include "godqol.h"
#include "BaseState.h"
#include "Player.h"
#include "Entity.h"
#include "Car.h"
#include "AIE.h"
#include "StateMachine.h"

extern const int TILE_X;
extern const int TILE_Y;
extern const unsigned int WINDOW_W;
extern const unsigned int WINDOW_H;

class GameState : public BaseState {
private:
	Sprite* map[375]; // The level's map, hardcoded for now. Might try and make this resizeable.
	Player* player;
	Sprite* movementMarker; // A small sprite placed behind the player to help visualize where they can move.

	//Slow lanes
	Car* slowLane_A[4]; // Slower car lane moving left
	Car* slowLane_B[4]; // Slower car lane moving right

	//Fast lanes
	Car* fastLane_A[4]; // Faster car lane moving right
	Car* fastLane_B[3]; // Faster car lane moving left
	Car* fastLane_C[2]; // Faster car lane moving right

	//River lanes - technically just cars, but the collision checking will be different
	Car* riverLane_A[3];
	Car* riverLane_B[4];
	Car* riverLane_C[3];

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

	// Currently I'm just making everything cars, but I'll have logs and a water object for the river later
	void MakeCars();
	void UpdateCars(float deltaTime);
	void DestroyCars();

	// Functions for the level's map
	void MakeMap();
	void UpdateMap();
	void DestroyMap();

	// Collision checking
	bool CheckHit(Player &thePlayer, Car &theCar); // Is player touching car


};

#endif
