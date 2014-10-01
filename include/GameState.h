#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include "BaseState.h"
#include "Player.h"
#include "Entity.h"
#include "AIE.h"

class GameState : public BaseState {
private:
	Player* player;
	Entity* lane_A[3];
	Entity* lane_B[3];
	Entity* lane_C[3];
	Entity* frogs[5];

protected:

public:
	GameState(void);
	~GameState(void);

	void Init();
	void Update(float deltaTime, StateMachine* a_pSM);

	void Draw();
	void Destroy();

};

#endif
