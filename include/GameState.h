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
	Player* player;
	Entity* lane_A[3]; // Slower car lane
	Entity* lane_B[3]; // Faster car lane
	Entity* lane_C[3]; // River
	Entity* frogs[5]; // Each frog that muct be collected

protected:

public:
	GameState(void);
	~GameState(void);

	void Init();
	void Update(float deltaTime, StateMachine* a_pSM);

	void Draw();
	void Destroy();

	void MakeCars();
	void MakePlayer();

	void DestroyCars();
	void DestroyPlayer();

	void UpdateCars();
	void UpdatePlayer();

};

#endif
