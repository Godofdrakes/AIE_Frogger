#include "AIE.h"
#include <iostream>
#include <string>
#include <list>
#include "StateMachine.h"
#include "MainMenuState.h"

using namespace std;

extern const string WINDOW_NAME = "AIE_Frogger";
extern const unsigned int WINDOW_W = 400;
extern const unsigned int WINDOW_H = 800;

int main( int argc, char* argv[] )
{
    //Init the AIE framework
    Initialise(WINDOW_W, WINDOW_H, false, WINDOW_NAME.c_str());
    SetBackgroundColour(SColour(0, 0, 0, 255));
    bool doExit = false;

    StateMachine state;
    state.PushState( new MainMenuState() );

    //Game Loop
    do
    {

        ClearScreen();
        float deltaTime = GetDeltaTime();

        state.Update(deltaTime);
        state.Draw();

    } while(!FrameworkUpdate() && !doExit);

    Shutdown();

    return 0;
}
