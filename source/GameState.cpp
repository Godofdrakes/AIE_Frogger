#include "GameState.h"

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	//MakeCars();
	MakeMap();
	MakePlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	//UpdateCars(deltaTime);
	UpdatePlayer(deltaTime);
	UpdateMap();
	if (IsKeyDown(GLFW_KEY_TAB)) {
		delete a_pSM->PopState();;
	}

}

// Didn't split the draw functions into seperate functions cause all the objects are based off of sprite so the method of drawing them won't change
void GameState::Draw() {
	for(int count = 0; count < 375; ++count) DrawSprite( map[count]->SpriteID() );/*
	for(int i=0; i<3; ++i) DrawSprite( lane_A[i]->SpriteID() );
	for(int i=0; i<3; ++i) DrawSprite( lane_B[i]->SpriteID() );
	for(int i=0; i<3; ++i) DrawSprite( lane_C[i]->SpriteID() );*/
	DrawSprite(player->SpriteID());
}

void GameState::Destroy() {
	//DestroyCars();
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

void GameState::MakeCars() {/*
	for(int i=0; i<3; ++i) {
		lane_A[i] = new Entity();
		lane_A[i]->SpriteID( CreateSprite("./images/Space-Invaders-Marquee.png", lane_A[i]->W(), lane_A[i]->H(), lane_A[i]->DrawFromCenter()) );
	}

	for(int i=0; i<3; ++i) {
		lane_B[i] = new Entity();
		lane_B[i]->SpriteID( CreateSprite("./images/Space-Invaders-Marquee.png", lane_B[i]->W(), lane_B[i]->H(), lane_B[i]->DrawFromCenter()) );
	}

	for(int i=0; i<3; ++i) {
		lane_C[i] = new Entity();
		lane_C[i]->SpriteID( CreateSprite("./images/Space-Invaders-Marquee.png", lane_C[i]->W(), lane_C[i]->H(), lane_C[i]->DrawFromCenter()) );
	}*/

}

void GameState::UpdateCars(float deltaTime) {/*
	for(int i=0; i<3; ++i) { MoveSprite(lane_A[i]->SpriteID(), lane_A[i]->X(), lane_A[i]->Y()); }
	for(int i=0; i<3; ++i) { MoveSprite(lane_B[i]->SpriteID(), lane_B[i]->X(), lane_B[i]->Y()); }
	for(int i=0; i<3; ++i) { MoveSprite(lane_C[i]->SpriteID(), lane_C[i]->X(), lane_C[i]->Y()); }*/

}

void GameState::DestroyCars() {/*
	for(int i=0; i<3; ++i) {
		DestroySprite(lane_A[i]->SpriteID());
		delete lane_A[i];
	}

	for(int i=0; i<3; ++i) {
		DestroySprite(lane_B[i]->SpriteID());
		delete lane_B[i];
	}

	for(int i=0; i<3; ++i) {
		DestroySprite(lane_C[i]->SpriteID());
		delete lane_C[i];
	}*/

}

/* Map fucntions */

void GameState::MakeMap() {
	int count = 0; // Which map tile are we currently working on?

	for(int column = 0; column < 15; ++column) {
		for(int row = 0; row < 25; ++row) {
			map[count] = new Sprite();
			map[count]->X( column*32 );
			map[count]->Y( row*32 );
			map[count]->DrawFromCenter(false);
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
