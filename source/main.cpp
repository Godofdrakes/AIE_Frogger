#include "AIE.h"
#include "godqol.h" //https://github.com/Godofdrakes/Godofdrakes-CPP-QOL
#include <iostream>
#include <string>
#include <list>
#include "StateMachine.h"
#include "MainMenuState.h"
#include "TextureStrings.h"

using namespace std;

extern const string WINDOW_NAME = "AIE_Frogger";
extern const int TILE_X = 32;
extern const int TILE_Y = 32; // The X and Y dimentions of a single tile, which will be used to make the main game's map.
extern const unsigned int WINDOW_W = TILE_X*15; // 15 tiles wide
extern const unsigned int WINDOW_H = TILE_Y*25; // and 25 tall

extern bool doExit = false; // When true, close the program

extern TextureStrings Textures; // Object with lists of each texture
extern GodQOL HELPER; //Class containing Helper functions

int main( int argc, char* argv[] ) {
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
