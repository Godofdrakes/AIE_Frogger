#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <fstream> // std::ifstream
#include <sstream> // std::stringstream

#include "AIE.h" // AIE Framework
#include "godqol.h" // My QoL library

#include "StateMachine.h" // Class StateMachine : public BaseState
#include "BaseState.h" // Virtual Class BaseState
#include "PauseState.h" // Class PauseState : public BaseState
#include "WinState.h" // Class WinState : public BaseState
#include "FailState.h" // Class FailState : public BaseState

#include "Player.h" // Class Player : public Entity
#include "Car.h" // Class Car : public Entity
#include "RiverLog.h" // Class RiverLog : public Entity
#include "RiverWater.h" // Class RiverWater : public Entity

extern const int TILE_X;
extern const int TILE_Y;
extern const int WINDOW_W;
extern const int WINDOW_H;

class GameState : public BaseState {
private:
	bool playerHasWon; // default is false. becomes true when player reaches the other side
	int livesLeft; // Reduced by one for each time player dies. lives <= 0 goes to game over screen
protected:
public:
	GameState(void);
	~GameState(void);

	void Init(); // Create all objects
	void Update(float deltaTime, StateMachine* a_pSM); // Call update functions for all objects

	void Draw(); // Draw all objects
	void Destroy(); // Call destroy functions for all objects

	// Fucntions for player
	void InitPlayer();
	void UpdatePlayer(Player* player, float deltaTime);

	// Fucntions for car
	void InitCars();
	void UpdateCar(Car* car, float deltaTime);

	// Functions for the riverLog
	void InitRiverLog();
	void UpdateRiverLog(RiverLog* riverLog, float deltaTime);

	// Functions for the riverWater
	void InitRiverWater();
	void UpdateRiverWater(RiverWater* riverWater, float deltaTime);

	// Functions for saving, loading, and checking the existance of highscores.
	bool FileExists( const char* name );
	void LoadHighscore( char* filename );
	void SaveHighscore( char* filename );


};

#endif
