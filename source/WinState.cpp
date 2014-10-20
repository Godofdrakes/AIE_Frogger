#include "WinState.h"

WinState::WinState(void) {


}

WinState::~WinState(void) {


}

void WinState::Init() {


}

void WinState::Update(float deltaTime, StateMachine* a_pSM) {
	if (IsKeyDown(GLFW_KEY_ESCAPE)) { delete a_pSM->PopState(); delete a_pSM->PopState(); return; }
	if (IsKeyDown(GLFW_KEY_TAB)) { delete a_pSM->PopState(); return; }
	if (IsKeyDown(GLFW_KEY_SPACE)) { delete a_pSM->PopState(); a_pSM->PushState( new GameState() ); return; }

}

void WinState::Draw() {
	for(auto mapTile : mapTiles) { // Iterate through every map tile
		MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
		DrawSprite( mapTile->SpriteID() );
	}

	DrawString("VICTORY!", (WINDOW_W/2)-50, TILE_Y*14);
	DrawString("Press Space to play again", 5, TILE_Y*10);
	DrawString("Press Esc to quit", WINDOW_W-210, TILE_Y*6);

}

void WinState::Destroy() {


}
