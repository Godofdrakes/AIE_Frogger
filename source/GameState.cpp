#include "GameState.h"

std::vector<Sprite*> BaseState::mapTiles;
std::vector<Entity*> BaseState::gameObjects;

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	MakeMap();
	MakeCars();
	MakePlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	if( IsKeyDown(GLFW_KEY_TAB) ) { delete a_pSM->PopState(); return; }

	for(auto object : gameObjects) { // Iterate through every object in the vector
		if(dynamic_cast<Player*>(object) != 0) { // If it's the player
			UpdatePlayer(dynamic_cast<Player*>(object), deltaTime);
		}
		if(dynamic_cast<Car*>(object) != 0) { // If it's the player
			UpdateCar(dynamic_cast<Car*>(object), deltaTime);
		}
	}


	// Check if car hit player
/*
		// Slow lanes
	for(int i=0; i<4; ++i) { // Simple distance check so see if the object hit the player and make sure they are both on the same row.
								// The Y comparison isn't technically necessary, but I had an issue or two with it previously so it's checking that for safety.
		if (GodQOL::Distance( player->X(), player->Y(), slowLane_A[i]->X(), slowLane_A[i]->Y() ) < (slowLane_A[i]->W()/2)+(player->W()/2) && player->Y() == slowLane_A[i]->Y() ) {
			player->X(TILE_X*.5f); // Return the player to their starting postiton
			player->Y(TILE_Y*.5f);
		}
	}
	for(int i=0; i<4; ++i) {
		if (GodQOL::Distance( player->X(), player->Y(), slowLane_B[i]->X(), slowLane_B[i]->Y() ) < (slowLane_B[i]->W()/2)+(player->W()/2) && player->Y() == slowLane_B[i]->Y() ) {
			player->X(TILE_X*.5f);
			player->Y(TILE_Y*.5f);
		}
	}
		// Fast lanes
	for(int i=0; i<4; ++i) {
		if (GodQOL::Distance( player->X(), player->Y(), fastLane_A[i]->X(), fastLane_A[i]->Y() ) < (fastLane_A[i]->W()/2)+(player->W()/2) && player->Y() == fastLane_A[i]->Y() ) {
			player->X(TILE_X*.5f);
			player->Y(TILE_Y*.5f);
		}
	}
	for(int i=0; i<3; ++i) {
		if (GodQOL::Distance( player->X(), player->Y(), fastLane_B[i]->X(), fastLane_B[i]->Y() ) < (fastLane_B[i]->W()/2)+(player->W()/2) && player->Y() == fastLane_B[i]->Y() ) {
			player->X(TILE_X*.5f);
			player->Y(TILE_Y*.5f);
		}
	}
	for(int i=0; i<2; ++i) {
		if (GodQOL::Distance( player->X(), player->Y(), fastLane_C[i]->X(), fastLane_C[i]->Y() ) < (fastLane_C[i]->W()/2)+(player->W()/2) && player->Y() == fastLane_C[i]->Y() ) {
			player->X(TILE_X*.5f);
			player->Y(TILE_Y*.5f);
		}
	}
		//River lanes
	for(int i=0; i<3; ++i) {
		if (GodQOL::Distance( player->X(), player->Y(), riverLane_A[i]->X(), riverLane_A[i]->Y() ) < (riverLane_A[i]->W()/2)+(player->W()/2) && player->Y() == riverLane_A[i]->Y() ) {
			player->X(TILE_X*.5f);
			player->Y(TILE_Y*.5f);
		}
	}
	for(int i=0; i<4; ++i) {
		if (GodQOL::Distance( player->X(), player->Y(), riverLane_B[i]->X(), riverLane_B[i]->Y() ) < (riverLane_B[i]->W()/2)+(player->W()/2) && player->Y() == riverLane_B[i]->Y() ) {
			player->X(TILE_X*.5f);
			player->Y(TILE_Y*.5f);
		}
	}
	for(int i=0; i<3; ++i) {
		if (GodQOL::Distance( player->X(), player->Y(), riverLane_C[i]->X(), riverLane_C[i]->Y() ) < (riverLane_C[i]->W()/2)+(player->W()/2) && player->Y() == riverLane_C[i]->Y() ) {
			player->X(TILE_X*.5f);
			player->Y(TILE_Y*.5f);
		}
	}
*/



}

// Didn't split the draw functions into seperate functions cause all the objects are based off of sprite so the method of drawing them won't change
void GameState::Draw() {

	for(auto mapTile : mapTiles) { // Iterate through every map tile
		MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
		DrawSprite( mapTile->SpriteID() );
	}

	for(auto object : gameObjects) { // Iterate through every game object
		MoveSprite( object->SpriteID(), object->X(), object->Y() );
		DrawSprite( object->SpriteID() );
	}

}

void GameState::Destroy() {

	for(auto object : mapTiles) { // Iterate through every map tile
		DestroySprite(object->SpriteID());
		delete object;
	}

	for(auto object : gameObjects) { // Iterate through every game object
		DestroySprite(object->SpriteID());
		delete object;
	}

}

/* Player functions */

void GameState::MakePlayer() {
	Player* player = new Player();
	player->X(TILE_X*.5f);
	player->Y(TILE_Y*.5f);
	player->W(TILE_X-2);
	player->H(TILE_Y-2);
	player->SpriteID( CreateSprite("./images/pieceRed_border06.png", player->W(), player->H(), player->DrawFromCenter()) );
	gameObjects.push_back(player);

}

void GameState::UpdatePlayer(Player* player, float deltaTime) {
	player->Move(deltaTime);

}

/* Lane functions */
void GameState::MakeCars() {
	// Bunch of code for making each car
	for(int i=0; i<numCars; ++i) {
		Car* car = new Car();
		car->SpeedX(2.f*TILE_X);
		car->SpeedY(0.f);
		car->X((i*4)*TILE_X);
		if(i<4) {
			car->Y( (4*TILE_Y) - (TILE_Y*.5f) );
			car->W(TILE_X-2);
		} else if(i<8) {
			car->Y( (5*TILE_Y)-(TILE_Y*.5f) );
			car->W(TILE_X-2);
		} else if(i<11) {
			car->Y( (8*TILE_Y) - (TILE_Y*.5f) );
			car->W(TILE_X-2);
		} else if(i<13) {
			car->Y( (9*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*2);
		} else if(i<16) {
			car->Y( (11*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*3);
		} else if(i<19) {
			car->Y( (12*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*3);
		} else if(i<22) {
			car->Y( (13*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*3);
		} else {
			car->Y(TILE_Y);
			car->W(TILE_X-2);
		}
		car->H(TILE_Y-2);
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) );
		gameObjects.push_back(car);
	}
}

void GameState::UpdateCar(Car* car, float deltaTime) {
	car->Move(deltaTime);
	MoveSprite(car->SpriteID(), car->X(), car->Y());

}

/* Map fucntions */

void GameState::MakeMap() {
	for(int column = 0; column < (WINDOW_W/TILE_X); ++column) {
		for(int row = 0; row < (WINDOW_H/TILE_Y); ++row) {
			Sprite* mapTile = new Sprite();
			mapTile->X( (column*TILE_X)+(TILE_X*.5f) );
			mapTile->Y( (row*TILE_Y)+(TILE_Y*.5f) );
			if(row == 3 || row == 4 || row == 6 || row == 7 || row == 8) { // Offset by -1 due to math stuff
				// Make it a road tile
				mapTile->SpriteID( CreateSprite("./images/kenneyRoad/roadTile6.png", mapTile->W(), mapTile->H(), mapTile->DrawFromCenter()) );
			} if(row == 10 || row == 11 || row == 12) {
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

void GameState::MakeRiver() {

}

void GameState::UpdateRiver() {

}
