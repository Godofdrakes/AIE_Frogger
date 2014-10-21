#include <string> // std::string
#include <vld.h> // http://vld.codeplex.com/

#include "AIE.h" // AIE Framework
#include "godqol.h" // https://github.com/Godofdrakes/Godofdrakes-CPP-QOL

#include "StateMachine.h" // class StateMachine
#include "MainMenuState.h" // class MainMenuState : public BaseState

extern const std::string WINDOW_NAME = "AIE_Frogger";

// A single tile of the map will be this size, and the basic sprite will be just a few pixels smaller than this.
extern const int TILE_X = 32; // How wide a tile will be
extern const int TILE_Y = 32; // How tall a tile will be

extern const int WINDOW_W = TILE_X*15; // Number of tiles wide
extern const int WINDOW_H = TILE_Y*15; // Number of tiles tall

extern bool doExit = false; // When true, close the program

int main(int argc, char* argv[]) {
  /*
    The AIE Framework leaks more than a frightened puppy. I'm ignoring it's memory leaks as much as possible.
    Building in RELEASE will not init VLD.
  */
  VLDDisable(); // Disabling and enabling vld around the framework functions will make it ignore any memory allocated durring that time.

  //Init the AIE framework
  Initialise(WINDOW_W, WINDOW_H, false, WINDOW_NAME.c_str());
  SetBackgroundColour(SColour(0, 0, 0, 255));

  VLDEnable(); // Make sure it's enabled.

  StateMachine state;
  state.PushState( new MainMenuState() );

  //Game Loop
  do {
    VLDEnable(); // Make sure it's enabled.

    ClearScreen();
    float deltaTime = GetDeltaTime();

    state.Update(deltaTime);
    if(!doExit) {state.Draw();}

    VLDDisable(); // Disable VLD before FrameworkUpdate() runs.

  } while(!FrameworkUpdate() && !doExit);

  Shutdown();
  return 0;
}
