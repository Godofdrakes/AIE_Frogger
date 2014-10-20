#ifndef _SETTINGSSTATE_H_
#define _SETTINGSSTATE_H_

#include "AIE.h" // AIE Framework

#include "StateMachine.h" // Class StateMachine : public BaseState
#include "BaseState.h" // Virtual Class BaseState

extern const int WINDOW_W;
extern const int WINDOW_H;
extern const int TILE_X;
extern const int TILE_Y;

class SettingsState : public BaseState {
private:
protected:
public:
	SettingsState(void);
	~SettingsState(void);

	void Init();
	void Update(float deltaTime, StateMachine* a_pSM);
	void Draw();
	void Destroy();

};

#endif
