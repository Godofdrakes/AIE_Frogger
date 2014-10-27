#include "WinState.h"

WinState::WinState(void) {

}

WinState::~WinState(void) {

}


void WinState::Init() {

}

void WinState::Update(float deltaTime, StateMachine* a_pSM) {
	if (IsKeyDown(GLFW_KEY_ESCAPE)) { // Quit
		delete a_pSM->PopState();
		delete a_pSM->PopState();
		return;
	}
	if (IsKeyDown(GLFW_KEY_TAB)) { // Return to main menu
		delete a_pSM->PopState();
		return;
	}
	if (IsKeyDown(GLFW_KEY_SPACE)) { // Unload and the reload the gamestate
		delete a_pSM->SwitchState(new GameState());
		return;
	}

}

void WinState::Draw() {
	for(auto mapTile : mapTiles) { // Draw every map tile
		MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
		DrawSprite( mapTile->SpriteID() );
	}

	// Tell the player stuff
	DrawString("VICTORY!", (WINDOW_W/2)-50, TILE_Y*14);
	DrawString("Press Space to play again", (WINDOW_W/2)-150, TILE_Y*9);
	DrawString("Press Tab to return to menu.", 0, TILE_Y*8);
	DrawString("Press Esc to quit", WINDOW_W-210, TILE_Y*7);

}

void WinState::Destroy() {

}
