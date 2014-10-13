#include "PauseState.h"

PauseState::PauseState(void) {

}

PauseState::~PauseState(void) {

}

void PauseState::Init() {

}

void PauseState::Update(float deltaTime, StateMachine* a_pSM) {
	if( IsKeyDown(GLFW_KEY_Y) ) { delete a_pSM->PopState(); delete a_pSM->PopState(); return; }
	if( IsKeyDown(GLFW_KEY_N) ) { delete a_pSM->PopState(); return; }

}

void PauseState::Draw() {
	for(auto mapTile : mapTiles) { // Iterate through every map tile
		if(mapTile->SpriteID() >= 0) { // Some objects may intentionaly not be given a texture. Don't try to draw these.
			MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
			DrawSprite( mapTile->SpriteID() );
		}
	}

	for(auto object : gameObjects) { // Iterate through every game object
		if(object->SpriteID() >= 0) { // Some objects may intentionaly not be given a texture. Don't try to draw these.
			MoveSprite( object->SpriteID(), object->X(), object->Y() );
			DrawSprite( object->SpriteID() );
		}
	}

	DrawString("Are you sure you want to quit? Y\\N", 30, WINDOW_H / 2);

}

void PauseState::Destroy() {

}
