#include "GameState.h"

std::vector<Sprite*> BaseState::mapTiles;
std::vector<Entity*> BaseState::gameObjects;

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	MakeRiver();
	MakeCars();
	MakePlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	if( IsKeyDown(GLFW_KEY_TAB) ) { delete a_pSM->PopState(); return; }

	for(auto object : gameObjects) { // Iterate through every object in the vector
		if(dynamic_cast<Player*>(object) != 0) { // If it's the player
			UpdatePlayer(dynamic_cast<Player*>(object), deltaTime);
		}
		if(dynamic_cast<Car*>(object) != 0) { // If it's a car
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

	}
*/



}

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

	for(auto object : gameObjects) { // Iterate through every game object
		DestroySprite(object->SpriteID());
		delete object;
	}
	gameObjects.clear();

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

	for(auto object : gameObjects) { // Iterate through every game object
		if(dynamic_cast<Car*>(object) != 0) { // If it's a car
			// Check if the player is hit by a car
			if (GodQOL::Distance( player->X(), player->Y(),
														object->X(), object->Y() ) <
														(object->W()/2) + (player->W()/2) &&  // If player is hit by car
														player->Y() == object->Y() ) { // And both are on the same lane
														/* Not using box colision for reasons.
														An issue with distance however is that the car wil "hit" the player even if the player is on a different lane then them.
														By making sure the player and car are on the same lane we fix that.*/
				player->X(TILE_X*.5f);
				player->Y(TILE_Y*.5f);
			}
		}
	}

}

/* Lane functions */
void GameState::MakeCars() {
	// Bunch of code for making each car
	for(int i=0; i<numCars; ++i) {
		Car* car = new Car(); // Make the car object
		car->SpeedY(0.f);
		if(i<4) { // Set it's X, Y, and witdh
			car->SpeedX(2.f*TILE_X);
			car->Y( (4*TILE_Y) - (TILE_Y*.5f) );
			car->W(TILE_X-2);
			car->X((i*4)*TILE_X);

		} else if(i<8) {
			car->SpeedX(2.f*TILE_X);
			car->Y( (5*TILE_Y)-(TILE_Y*.5f) );
			car->W(TILE_X-2);
			car->X(((i-4)*4)*TILE_X);

		} else if(i<11) {
			car->SpeedX(2.f*TILE_X);
			car->Y( (8*TILE_Y) - (TILE_Y*.5f) );
			car->W(TILE_X-2);
			car->X(((i-7)*3)*TILE_X);

		} else if(i<13) {
			car->SpeedX(2.f*TILE_X);
			car->Y( (9*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*2);
			car->X(((i-9)*2)*TILE_X);

		} else if(i<16) {
			car->SpeedX(2.f*TILE_X);
			car->Y( (11*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*3);
			car->X(((i-12)*6)*TILE_X);

		} else if(i<19) {
			car->SpeedX(2.f*TILE_X);
			car->Y( (12*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*3);
			car->X(((i-15)*5)*TILE_X);

		} else if(i<22) {
			car->SpeedX(2.f*TILE_X);
			car->Y( (13*TILE_Y) - (TILE_Y*.5f) );
			car->W((TILE_X-2)*3);
			car->X(((i-18)*6)*TILE_X);

		} else {
			car->SpeedX(2.f*TILE_X);
			car->Y(TILE_Y);
			car->W(TILE_X-2);
			car->X((i*4)*TILE_X);

		}
		car->H(TILE_Y-2); // Set the height
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) ); // The sprite
		gameObjects.push_back(car); // And add it to the list of objects
	}

}

void GameState::UpdateCar(Car* car, float deltaTime) {
	car->Move(deltaTime);
	MoveSprite(car->SpriteID(), car->X(), car->Y());

}

void GameState::MakeRiver() {

}

void GameState::UpdateRiver() {

}
