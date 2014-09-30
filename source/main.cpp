#include "AIE.h"
#include <iostream>
#include <string>

using namespace std;

const string WINDOW_NAME = "AIE_Frogger";

bool doExit = false;

int main( int argc, char* argv[] )
{
    Initialise(800, 600, false, WINDOW_NAME.c_str());

    SetBackgroundColour(SColour(0, 0, 0, 255));

    int myTextureHandle = CreateSprite("./images/crate_sideup.png", 64, 64, true);
    float xPos = 100;
    float yPos = 100;

    //Game Loop
    do
    {
        MoveSprite(myTextureHandle, xPos, yPos);
        DrawSprite(myTextureHandle);

        ClearScreen();

    } while(!FrameworkUpdate() && !doExit);

    Shutdown();

    return 0;
}
