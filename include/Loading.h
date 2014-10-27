#ifndef _LOADING_H_
#define _LOADING_H_

#include "AIE.h" // AIE Framework
#include "godqol.h" // My QoL library

#include "BaseState.h" // Virtual Class BaseState
#include "MainMenuState.h"

class Loading : public BaseState {
private:
	float timeToWait; // How long should the loading screen show?
	float timeSpent; // How long has the loading screen been showing?
protected:
public:
	Loading(void);
	~Loading(void);

	virtual void Init();
	virtual void Update(float deltaTime, StateMachine* a_pSM);

	virtual void Draw();
	virtual void Destroy();

};

#endif
