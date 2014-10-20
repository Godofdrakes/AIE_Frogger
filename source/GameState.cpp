#include "GameState.h"

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	playerHasWon = false;

	InitRiverWater();
	InitRiverLog();
	InitCars();
	InitPlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	if(playerHasWon) { delete a_pSM->PopState(); a_pSM->PushState( new WinState() ); return; }

	if( IsKeyDown(GLFW_KEY_ESCAPE) ) {
		if( IsKeyDown(GLFW_KEY_LEFT_SHIFT) ) {
			delete a_pSM->PopState(); delete a_pSM->PopState(); return;
		} else { a_pSM->PushState( new PauseState() ); return; }
	}

	for(auto object : gameObjects) { // Iterate through every object in the vector
		if(dynamic_cast<RiverWater*>(object) != 0) { // If it's RiverWater
			UpdateRiverWater(dynamic_cast<RiverWater*>(object), deltaTime);
		} else if(dynamic_cast<RiverLog*>(object) != 0) { // If it's a RiverLog
			UpdateRiverLog(dynamic_cast<RiverLog*>(object), deltaTime);
		} else if(dynamic_cast<Car*>(object) != 0) { // If it's a car
			UpdateCar(dynamic_cast<Car*>(object), deltaTime);
		} else if(dynamic_cast<Player*>(object) != 0) { // If it's the player
			UpdatePlayer(dynamic_cast<Player*>(object), deltaTime);
		}
	}

}

void GameState::Draw() {

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

	DrawString("W/A/S/D to move", 5, 30);
	DrawString("Esc to pause/quit", WINDOW_W-215, 30);

}

void GameState::Destroy() {

	for(auto object : gameObjects) { // Iterate through every game object
		if (object->SpriteID() >= 0) {
			DestroySprite(object->SpriteID());
		}
		delete object;
	}
	gameObjects.clear();

}

/* Player functions */

void GameState::InitPlayer() {
	Player* player = new Player();
	player->X((TILE_X*6)+(TILE_X*.5f));
	player->Y((TILE_Y*1)+(TILE_X*.5f));
	player->W(TILE_X-2);
	player->H(TILE_Y-2);
	player->SpriteID( CreateSprite("./images/pieceRed_border06.png", player->W(), player->H(), player->DrawFromCenter()) );
	gameObjects.push_back(player);

}

void GameState::UpdatePlayer(Player* player, float deltaTime) {
	if(player->Y() > TILE_Y*13) { playerHasWon = true; } // If the player reaches the other side, they have won.

	player->Move(deltaTime);

	bool touchingWater = false;
	bool touchingLog = false;

	for(auto object : gameObjects) { // Iterate through every game object
		if(dynamic_cast<Car*>(object) != 0) { // If it's a car
			// Check if the player is hit by a car
			if(GodQOL::BoxCollide(player->X(), player->Y(), player->W(), player->H(),
														object->X(), object->Y(), object->W(), object->H())) {
				player->X(TILE_X*.5f);
				player->Y(TILE_Y*.5f);
			}
		} else if(dynamic_cast<RiverWater*>(object) != 0) {
			if(GodQOL::BoxCollide(player->X(), player->Y(), player->W(), player->H(),
														object->X(), object->Y(), object->W(), object->H())) {
				touchingWater = true;
			}
		} else if(dynamic_cast<RiverLog*>(object) != 0) {
			if(GodQOL::BoxCollide(player->X(), player->Y(), player->W(), player->H(),
														object->X(), object->Y(), object->W(), object->H())) {
				touchingLog = true;
			}
		}
	}
	if (touchingWater == true && touchingLog == false) {
		player->X(TILE_X*.5f);
		player->Y(TILE_Y*.5f);
	}

}

/* Lane functions */
void GameState::InitCars() {
	// Bunch of code for making each car

	// (from the bottom) Road 1
	for(int i=0; i<4; ++i) {
		Car* car = new Car(); // Make the car object
		car->SpeedY( 0.f ); // Disable movement on the Y axis
		car->SpeedX( 1.5f * TILE_X ); // Positive is Left-Right movement, negitive is the reverse
		car->Y( (3*TILE_Y) + (TILE_X/2) ); // The row of tiles the car will be driving on
		car->X( (i*4) * TILE_X ); // Spread the cars out along the road
		car->W( TILE_X-2 ); // Make the car just slightly smaller than a single "tile". It looks nicer that way.
		car->H( TILE_X-2 );
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) );
		gameObjects.push_back(car); // And add it to the list of objects

	}

	// Road 2
	for(int i=0; i<4; ++i) {
		Car* car = new Car();
		car->SpeedY( 0.f );
		car->SpeedX( -1.0f * TILE_X );
		car->Y( (4*TILE_Y) + (TILE_X/2) );
		car->X( (i*4) * TILE_X );
		car->W( TILE_X-2 );
		car->H( TILE_X-2 );
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) );
		gameObjects.push_back(car);

	}

	// Road 3
	for(int i=0; i<4; ++i) {
		Car* car = new Car();
		car->SpeedY( 0.f );
		car->SpeedX( 2.f * TILE_X );
		car->Y( (6*TILE_Y) + (TILE_X/2) );
		car->X( (i*4) * TILE_X );
		car->W( TILE_X-2 );
		car->H( TILE_X-2 );
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) );
		gameObjects.push_back(car);

	}

	// Road 4
	for(int i=0; i<4; ++i) {
		Car* car = new Car();
		car->SpeedY( 0.f );
		car->SpeedX( 3.5f * TILE_X );
		car->Y( (7*TILE_Y) + (TILE_X/2) );
		car->X( (i*4) * TILE_X );
		car->W( TILE_X-2 );
		car->H( TILE_X-2 );
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) );
		gameObjects.push_back(car);

	}

	// Road 5
	for(int i=0; i<4; ++i) {
		Car* car = new Car();
		car->SpeedY( 0.f );
		car->SpeedX( -2.5f * TILE_X );
		car->Y( (8*TILE_Y) + (TILE_X/2) );
		car->X( (i*4) * TILE_X );
		car->W( TILE_X-2 );
		car->H( TILE_X-2 );
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) );
		gameObjects.push_back(car);

	}

}

void GameState::UpdateCar(Car* car, float deltaTime) {
	car->Move(deltaTime);

}

void GameState::InitRiverLog() {
	// River 1
	for(int i=0; i<4; ++i) {
		RiverLog* riverLog = new RiverLog();
		riverLog->SpeedY( 0.f );
		riverLog->SpeedX( -1.5f * TILE_X );
		riverLog->Y( (10*TILE_Y) + (TILE_X/2) );
		riverLog->X( (i*4.5f) * TILE_X );
		riverLog->W( TILE_X*3 );
		riverLog->H( TILE_X-2 );
		riverLog->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile5.png", riverLog->W(), riverLog->H(), riverLog->DrawFromCenter()) );
		gameObjects.push_back(riverLog);

	}
	// River 2
	for(int i=0; i<4; ++i) {
		RiverLog* riverLog = new RiverLog();
		riverLog->SpeedY( 0.f );
		riverLog->SpeedX( 3.0f * TILE_X );
		riverLog->Y( (11*TILE_Y) + (TILE_X/2) );
		riverLog->X( (i*4.5f) * TILE_X );
		riverLog->W( TILE_X*3 );
		riverLog->H( TILE_X-2 );
		riverLog->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile5.png", riverLog->W(), riverLog->H(), riverLog->DrawFromCenter()) );
		gameObjects.push_back(riverLog);

	}
	// River 3
	for(int i=0; i<4; ++i) {
		RiverLog* riverLog = new RiverLog();
		riverLog->SpeedY( 0.f );
		riverLog->SpeedX( -2.f * TILE_X );
		riverLog->Y( (12*TILE_Y) + (TILE_X/2) );
		riverLog->X( (i*4.5f) * TILE_X );
		riverLog->W( TILE_X*3 );
		riverLog->H( TILE_X-2 );
		riverLog->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile5.png", riverLog->W(), riverLog->H(), riverLog->DrawFromCenter()) );
		gameObjects.push_back(riverLog);

	}

}

void GameState::UpdateRiverLog(RiverLog* riverLog, float deltaTime) {
	riverLog->Move(deltaTime);

}

void GameState::InitRiverWater() {
	RiverWater* riverWater = new RiverWater();
	riverWater->SpeedY( 0.f );
	riverWater->SpeedX( 0.f );
	riverWater->Y( (11*TILE_Y) + (TILE_X/2) );
	riverWater->X( WINDOW_W*.5f );
	riverWater->W( WINDOW_W );
	riverWater->H( TILE_X*3 );
	//riverWater->SpriteID( CreateSprite("./images/pieceRed_border13.png", riverWater->W(), riverWater->H(), riverWater->DrawFromCenter()) );
	gameObjects.push_back(riverWater);

}

void GameState::UpdateRiverWater(RiverWater* riverWater, float deltaTime) {
	riverWater->Move(deltaTime);

}
