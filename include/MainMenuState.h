#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "AIE.h"
#include "BaseState.h"
#include "SettingsState.h"
#include "StateMachine.h"
#include "Sprite.h"
#include "GameState.h"

extern const int WINDOW_W;
extern const int WINDOW_H;
extern const int TILE_X;
extern const int TILE_Y;
extern bool doExit;

class MainMenuState : public BaseState {
private:
protected:
public:
	MainMenuState(void);
	~MainMenuState(void);

	void Init();
	void Update(float deltaTime, StateMachine* a_pSM);
	void Draw();
	void Destroy();

	// Functions for the level's map
	void MakeMap();

};


#endif
