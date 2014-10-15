#include "SettingsState.h"

SettingsState::SettingsState(void) {


}

SettingsState::~SettingsState(void) {


}

void SettingsState::Init() {


}

void SettingsState::Update(float deltaTime, StateMachine* a_pSM) {
	if (IsKeyDown(GLFW_KEY_TAB)) { delete a_pSM->PopState(); return; }

}

void SettingsState::Draw() {
	for(auto mapTile : mapTiles) { // Iterate through every map tile
		MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
		DrawSprite( mapTile->SpriteID() );
	}

}

void SettingsState::Destroy() {


}
