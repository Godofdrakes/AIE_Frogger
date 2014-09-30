#include "AIE.h"
#include <iostream>
#include <string>

using namespace std;

const string WINDOW_NAME = "AIE_Frogger";
const unsigned int WINDOW_W = 400;
const unsigned int WINDOW_H = 800;

bool doExit = false;

int main( int argc, char* argv[] )
{
    //Init the AIE framework
    Initialise(800, 600, false, WINDOW_NAME.c_str());
    SetBackgroundColour(SColour(0, 0, 0, 255));

    //Game Loop
    do
    {

        ClearScreen();

    } while(!FrameworkUpdate() && !doExit);

    Shutdown();

    return 0;
}
