#include "AIE.h"
#include "godqol.h" //https://github.com/Godofdrakes/Godofdrakes-CPP-QOL
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

//Class containing Helper functions
GodQOL HELPER;

int main( int argc, char* argv[] ) {
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
		    state.Draw();


    } while(!FrameworkUpdate() && !doExit);

    Shutdown();

    return 0;
}
