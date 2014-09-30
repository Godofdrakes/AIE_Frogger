#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "AIE.h"
#include "BaseState.h"
#include "StateMachine.h"

class MainMenuState : public BaseState {
private:
	unsigned int iArcadeMarquee;

protected:

public:
	MainMenuState::MainMenuState(void);
	~MainMenuState::MainMenuState(void);

	void Init();
	void Update(float deltaTime, StateMachine* a_pSM);
	void Draw();
	void Destory();

}


#endif
