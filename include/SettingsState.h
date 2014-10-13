#ifndef _SETTINGSSTATE_H_
#define _SETTINGSSTATE_H_

#include <iostream>
#include <string>

#include "AIE.h"

#include "BaseState.h"
#include "StateMachine.h"

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
