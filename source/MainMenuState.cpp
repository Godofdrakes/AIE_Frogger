#include "MainMenuState.h"

extern const int WINDOW_W;
extern const int WINDOW_H;
extern bool doExit;

MainMenuState::MainMenuState(void) {}
MainMenuState::~MainMenuState(void) {}

void MainMenuState::Init() {
	MakeMap();

}

void MainMenuState::Update(float deltaTime, StateMachine* a_pSM) {
	if (IsKeyDown(GLFW_KEY_SPACE)) { a_pSM->PushState( new GameState() ); return; }
	if (IsKeyDown(GLFW_KEY_ESCAPE)) { delete a_pSM->PopState(); return; }

}

void MainMenuState::Draw() {
	for(auto mapTile : mapTiles) { // Iterate through every map tile
		MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
		DrawSprite( mapTile->SpriteID() );
	}

}

void MainMenuState::Destroy() {

	for(auto object : mapTiles) { // Iterate through every map tile
		DestroySprite(object->SpriteID());
		delete object;
	}
	mapTiles.clear();

	doExit = true;
}

/* Map fucntions */

void MainMenuState::MakeMap() {
	for(int row = 0; row < (WINDOW_W/TILE_X); ++row) {
		for(int column = 0; column < (WINDOW_H/TILE_Y); ++column) {
			Sprite* mapTile = new Sprite();
			mapTile->X( (column*TILE_X)+(TILE_X*.5f) );
			mapTile->Y( (row*TILE_Y)+(TILE_Y*.5f) );
			if(row == 3 || row == 4 || row == 6 || row == 7 || row == 8) {
				// Make it a road tile
				mapTile->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile2.png", mapTile->W(), mapTile->H(), mapTile->DrawFromCenter()) );
			} else if(row == 10 || row == 11 || row == 12) {
				// Make it a water tile
				mapTile->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile6.png", mapTile->W(), mapTile->H(), mapTile->DrawFromCenter()) );
			} else {
				// Make it a grass tile
				mapTile->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile3.png", mapTile->W(), mapTile->H(), mapTile->DrawFromCenter()) );
			}
			mapTiles.push_back(mapTile);
		}
	}

}
