#include "MainMenuState.h"

MainMenuState::MainMenuState(void) {}
MainMenuState::~MainMenuState(void) {}

void MainMenuState::Init() {
	/*
		As opposed to a ginat sprite, the map is made up of individual srpite objects.
		In main.cpp the size of our universal "tile" is set up.
		This "tile" is used to scale everything from the size of the player to the size of the game's window.
		Probably not the cleanest way to get the map set up, but it works.
	*/

	for(int row = 0; row < (WINDOW_W/TILE_X); ++row) {
		for(int column = 0; column < (WINDOW_H/TILE_Y); ++column) {
			Sprite* mapTile = new Sprite(); // The map doesn't do anything so it's a Sprite, not an Entity.
			mapTile->X( (column*TILE_X)+(TILE_X*.5f) ); // Place the sprite. It's size defaults to the size of the "tile"
			mapTile->Y( (row*TILE_Y)+(TILE_Y*.5f) );
			if(row == 3 || row == 4 || row == 6 || row == 7 || row == 8) { // Depending on which row we are on we want to draw a different sprite
				// Make it a road tile
				mapTile->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile2.png", mapTile->W(), mapTile->H(), mapTile->DrawFromCenter()) );
			} else if(row == 10 || row == 11 || row == 12) {
				// Make it a water tile
				mapTile->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile6.png", mapTile->W(), mapTile->H(), mapTile->DrawFromCenter()) );
			} else {
				// Make it a grass tile
				mapTile->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile3.png", mapTile->W(), mapTile->H(), mapTile->DrawFromCenter()) );
			}
			mapTiles.push_back(mapTile); // Push the new map sprite to the mapTiles vector
		}
	}

}

void MainMenuState::Update(float deltaTime, StateMachine* a_pSM) {
	if (IsKeyDown(GLFW_KEY_SPACE)) { a_pSM->PushState( new GameState() ); return; } // Start the game
	if (IsKeyDown(GLFW_KEY_ESCAPE)) { delete a_pSM->PopState(); return; } // Quit the game
	if (IsKeyDown(GLFW_KEY_GRAVE_ACCENT)) { a_pSM->SwitchState( new Loading() ); doExit = false; return; } // Show the loading screen again.


}

void MainMenuState::Draw() {
	for(auto mapTile : mapTiles) { // Draw every map tile
		MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
		DrawSprite( mapTile->SpriteID() );
	}

	// Tell the player some stuff
	DrawString(WINDOW_NAME.c_str(), 170, TILE_Y*14);
	DrawString("Press Space to play", 130, TILE_Y*10);
	DrawString("W/A/S/D to move", 5, 30);
	DrawString("Esc to pause/quit", WINDOW_W-215, 30);

}

void MainMenuState::Destroy() {

	for(auto object : mapTiles) { // Destroy every map tile
		DestroySprite(object->SpriteID());
		delete object;
	}
	mapTiles.clear();

	doExit = true; // The the main loop that we are done and should quit.
}
