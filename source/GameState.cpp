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

	// Check if car hit player
	for(int i=0; i<4; ++i) {
		if( CheckHit(*player, *slowLane_L[i]) ) { player->X(TILE_X*.5f); player->Y(TILE_Y*.5f); }
		if( CheckHit(*player, *slowLane_R[i]) ) { player->X(TILE_X*.5f); player->Y(TILE_Y*.5f); }
	}

	if( IsKeyDown(GLFW_KEY_TAB) ) { delete a_pSM->PopState(); }

}

// Didn't split the draw functions into seperate functions cause all the objects are based off of sprite so the method of drawing them won't change
void GameState::Draw() {
	for(int count = 0; count < 375; ++count) DrawSprite( map[count]->SpriteID() );
	DrawSprite( movementMarker->SpriteID() );
	for(int i=0; i<4; ++i) DrawSprite( slowLane_L[i]->SpriteID() );
	for(int i=0; i<4; ++i) DrawSprite( slowLane_R[i]->SpriteID() );
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
	player->X(player->W()*.5f);
	player->Y(player->H()*.5f);
	player->SpriteID( CreateSprite("./images/pieceRed_border06.png", player->W(), player->H(), player->DrawFromCenter()) );

	movementMarker = new Sprite();
	movementMarker->X(player->X());
	movementMarker->Y(player->Y());
	movementMarker->W(player->W()*3);
	movementMarker->H(player->H()*3);
	movementMarker->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile2.png", movementMarker->W(), movementMarker->H(), movementMarker->DrawFromCenter()) );

}

void GameState::UpdatePlayer(float deltaTime) {
	player->Move(deltaTime);
	MoveSprite(player->SpriteID(), player->X(), player->Y());

	movementMarker->X(player->X());
	movementMarker->Y(player->Y());
	MoveSprite(movementMarker->SpriteID(), movementMarker->X(), movementMarker->Y());

}

void GameState::DestroyPlayer() {
	DestroySprite(player->SpriteID());
	delete player;
	DestroySprite(movementMarker->SpriteID());
	delete movementMarker;

}

/* Lane functions */
void GameState::MakeSlowCars() {
	for(int i=0; i<4; ++i) {
		slowLane_L[i] = new Car();
		slowLane_L[i]->Direction(-1); // Go left
		slowLane_L[i]->Y( (3*TILE_Y)+(TILE_Y*.5f) ); // Third row of tiles from the bottom
		slowLane_L[i]->X((i*4)*TILE_X); // Four tiles in between each car
		slowLane_L[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", slowLane_L[i]->W(), slowLane_L[i]->H(), slowLane_L[i]->DrawFromCenter()) );

		slowLane_R[i] = new Car();
		slowLane_R[i]->Direction(1); // Go left
		slowLane_R[i]->Y( (4*TILE_Y)+(TILE_Y*.5f) ); // Third row of tiles from the bottom
		slowLane_R[i]->X((i*4)*TILE_X); // Four tiles in between each car
		slowLane_R[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", slowLane_R[i]->W(), slowLane_R[i]->H(), slowLane_R[i]->DrawFromCenter()) );
	}

}

void GameState::UpdateSlowCars(float deltaTime) {
	for(int i=0; i<4; ++i) {
		slowLane_L[i]->Move(deltaTime);
		MoveSprite(slowLane_L[i]->SpriteID(), slowLane_L[i]->X(), slowLane_L[i]->Y());

		slowLane_R[i]->Move(deltaTime);
		MoveSprite(slowLane_R[i]->SpriteID(), slowLane_R[i]->X(), slowLane_R[i]->Y());
	}

}

void GameState::DestroySlowCars() {
	for(int i=0; i<4; ++i) {
		DestroySprite(slowLane_L[i]->SpriteID());
		delete slowLane_L[i];

		DestroySprite(slowLane_R[i]->SpriteID());
		delete slowLane_R[i];
	}

}

/* Map fucntions */

void GameState::MakeMap() {
	int count = 0; // Which map tile are we currently working on?

	for(int column = 0; column < 15; ++column) {
		for(int row = 0; row < 25; ++row) {
			map[count] = new Sprite();
			map[count]->X( (column*TILE_X)+(TILE_X*.5f) );
			map[count]->Y( (row*TILE_Y)+(TILE_Y*.5f) );
			map[count]->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile1.png", map[count]->W(), map[count]->H(), map[count]->DrawFromCenter()) );
			count++; // Be sure to increment for the next tile.
		}
	}
}

void GameState::UpdateMap() {
	for(int count = 0; count < 375; ++count) {
		MoveSprite( map[count]->SpriteID(), map[count]->X(), map[count]->Y() );
	}
}

void GameState::DestroyMap() {
	for(int count = 0; count < 375; ++count) {
		DestroySprite( map[count]->SpriteID() );
		delete map[count];
	}
}

// Hit detection using the pythagrian theorum
bool GameState::CheckHit(Player &thePlayer, Car &theCar) {
	float a = ( thePlayer.X() - theCar.X() );
	float b = ( thePlayer.Y() - theCar.Y() );
	float c = (a*a)+(b*b);
	if(sqrt(c)<TILE_X*0.66f) { return true; } else { return false; }

}
