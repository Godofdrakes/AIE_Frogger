﻿#include "AIE.h"
#include <iostream>
#include <string>
#include <list>
#include "StateMachine.h"
#include "MainMenuState.h"

using namespace std;

extern const string WINDOW_NAME = "AIE_Frogger";
extern const unsigned int WINDOW_W = 600;
extern const unsigned int WINDOW_H = 800;
extern bool doExit = false;

int main( int argc, char* argv[] )
{
    //Init the AIE framework
    Initialise(WINDOW_W, WINDOW_H, false, WINDOW_NAME.c_str());
    SetBackgroundColour(SColour(0, 0, 0, 255));

    StateMachine state;
    state.PushState( new MainMenuState() );

    //Game Loop
    do
    {

        ClearScreen();
        float deltaTime = GetDeltaTime();

        state.Update(deltaTime);
		if (!doExit) { state.Draw(); }


    } while(!FrameworkUpdate() && !doExit);

    Shutdown();

    return 0;
}
