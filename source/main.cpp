#include <iostream>
#include <string>
#include <assert.h>
//#include <vld.h> //http://vld.codeplex.com/
#include "AIE.h"
#include "godqol.h" //https://github.com/Godofdrakes/Godofdrakes-CPP-QOL
#include "StateMachine.h"
#include "MainMenuState.h"

extern const std::string WINDOW_NAME = "AIE_Frogger";
// A single tile of the map will be this size, and the basic sprite will be just a few pixels smaller than this.
extern const int TILE_X = 32; // How wide a tile will be
extern const int TILE_Y = 32; // How tall a tile will be
extern const int WINDOW_W = TILE_X*15; // Number of tiles wide
extern const int WINDOW_H = TILE_Y*15; // Number of tiles tall

extern bool doExit = false; // When true, close the program

int main(int argc, char* argv[]) {
    //Init the AIE framework
    Initialise(WINDOW_W, WINDOW_H, false, WINDOW_NAME.c_str());
    SetBackgroundColour(SColour(0, 0, 0, 255));

    StateMachine state;
    state.PushState( new MainMenuState() );

    //Game Loop
    do {

        ClearScreen();
        float deltaTime = GetDeltaTime();

        state.Update(deltaTime);
		    if(!doExit) {state.Draw();}


    } while(!FrameworkUpdate() && !doExit);

    Shutdown();
    return 0;
}
