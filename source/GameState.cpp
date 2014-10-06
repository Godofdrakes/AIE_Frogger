#include "GameState.h"

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	MakeMap();
	MakeSlowCars();
	MakePlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	UpdateMap(); // Doesn't actually do anything right now
	UpdateSlowCars(deltaTime);
	UpdatePlayer(deltaTime);
	if( IsKeyDown(GLFW_KEY_TAB) ) delete a_pSM->PopState();

}

// Didn't split the draw functions into seperate functions cause all the objects are based off of sprite so the method of drawing them won't change
void GameState::Draw() {
	for(int count = 0; count < 375; ++count) DrawSprite( map[count]->SpriteID() );
	for(int i=0; i<3; ++i) DrawSprite( slowLane_L[i]->SpriteID() );
	DrawSprite( player->SpriteID() );

}

void GameState::Destroy() {
	DestroySlowCars();
	DestroyMap();
	DestroyPlayer();

}

/* Player functions */

void GameState::MakePlayer() {
	player = new Player();
	player->SpriteID( CreateSprite("./images/pieceRed_border06.png", player->W(), player->H(), player->DrawFromCenter()) );

}

void GameState::UpdatePlayer(float deltaTime) {
	player->Move(deltaTime);
	MoveSprite(player->SpriteID(), player->X(), player->Y());

}

void GameState::DestroyPlayer() {
	DestroySprite(player->SpriteID());
	delete player;

}

/* Lane functions */

void GameState::MakeSlowCars() {
	for(int i=0; i<3; ++i) {
		slowLane_L[i] = new Car();
		slowLane_L[i]->Y(3*TILE_Y); // Third row of tiles from the bottom
		slowLane_L[i]->Y((i*3)*TILE_X);
		slowLane_L[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", slowLane_L[i]->W(), slowLane_L[i]->H(), slowLane_L[i]->DrawFromCenter()) );
	}

}

void GameState::UpdateSlowCars(float deltaTime) {
	for(int i=0; i<3; ++i) { MoveSprite(slowLane_L[i]->SpriteID(), slowLane_L[i]->X(), slowLane_L[i]->Y()); }

}

void GameState::DestroySlowCars() {
	for(int i=0; i<3; ++i) { DestroySprite(slowLane_L[i]->SpriteID()); delete slowLane_L[i]; }

}

/* Map fucntions */

void GameState::MakeMap() {
	int count = 0; // Which map tile are we currently working on?

	for(int column = 0; column < 15; ++column) {
		for(int row = 0; row < 25; ++row) {
			map[count] = new Sprite();
			map[count]->X( column*32 );
			map[count]->Y( row*32 );
			map[count]->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile1.png", map[count]->W(), map[count]->H(), map[count]->DrawFromCenter()) );
			count++; // Be sure to increment for the next tile.
		}
	}
}

void GameState::UpdateMap() {
	for(int count = 0; count < 375; ++count) MoveSprite( map[count]->SpriteID(), map[count]->X(), map[count]->Y() );
}

void GameState::DestroyMap() {
	for(int count = 0; count < 375; ++count) {
		DestroySprite( map[count]->SpriteID() );
		delete map[count];
	}
}
