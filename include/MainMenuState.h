#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "AIE.h" // AIE Framework

#include "StateMachine.h" // Class StateMachine
#include "BaseState.h" // Cirtual Class BaseState
#include "SettingsState.h" // Class SettingsState : public BaseState
#include "GameState.h" // Class GameState : public BaseState

#include "Sprite.h" // Class Sprite

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

};


#endif
