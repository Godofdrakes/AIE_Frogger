#include "GameState.h"

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	playerHasWon = false;
	livesLeft = 3;

	InitRiverWater();
	InitRiverLog();
	InitCars();
	InitPlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	if (playerHasWon) { delete a_pSM->SwitchState(new WinState()); return; } // Did player win?
	else if (livesLeft <= 0) { delete a_pSM->SwitchState(new FailState()); return; } // DId player loose?

	if( IsKeyDown(GLFW_KEY_ESCAPE) ) { // Return to main menu
		if( IsKeyDown(GLFW_KEY_LEFT_SHIFT) ) { // IF shift is held then we just quit
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

	for(auto mapTile : mapTiles) { // Draw every map tile
		if(mapTile->SpriteID() >= 0) { // Some objects may intentionaly not be given a texture. Don't try to draw these.
			MoveSprite( mapTile->SpriteID(), mapTile->X(), mapTile->Y() );
			DrawSprite( mapTile->SpriteID() );
		}
	}

	for(auto object : gameObjects) { // Draw every game object
		if(object->SpriteID() >= 0) { // Some objects may intentionaly not be given a texture. Don't try to draw these.
			MoveSprite( object->SpriteID(), object->X(), object->Y() );
			DrawSprite( object->SpriteID() );
		}
	}

	// Tell the player stuff
	DrawString("W/A/S/D to move", 5, 30);
	DrawString("Esc to pause/quit", WINDOW_W-215, 30);

}

void GameState::Destroy() {

	for(auto object : gameObjects) { // Destroy every game object
		if (object->SpriteID() >= 0) {
			DestroySprite(object->SpriteID());
		}
		delete object;
	}
	gameObjects.clear();

	/*
		We don't destroy the map itself yet. We'll need that until we actually quit the game so it's handled by MainMenuState
	*/

}

/* Player functions */
void GameState::InitPlayer() {
	Player* player = new Player(); // Create
	player->X((TILE_X*6)+(TILE_X*.5f)); // Place
	player->Y((TILE_Y*1)+(TILE_X*.5f));
	player->W(TILE_X-2); // Resize
	player->H(TILE_Y-2);
	player->SpriteID( CreateSprite("./images/pieceRed_border06.png", player->W(), player->H(), player->DrawFromCenter()) ); // Load image
	gameObjects.push_back(player); // Add to object list

}

void GameState::UpdatePlayer(Player* player, float deltaTime) {
	if(player->Y() > TILE_Y*13) { playerHasWon = true; return; } // If the player reaches the other side, they have won.

	player->Move(deltaTime); // First move the player

	bool touchingWater = false;
	bool touchingLog = false;

	for(auto object : gameObjects) { // Iterate through every game object
		if(dynamic_cast<Car*>(object) != 0) { // If it's a car
			// Check if the player is hit by a car
			if(GodQOL::BoxCollide(player->X(), player->Y(), player->W(), player->H(),
														object->X(), object->Y(), object->W(), object->H())) {
				player->X((TILE_X*6)+(TILE_X*.5f));
				player->Y((TILE_Y*1)+(TILE_X*.5f));
				livesLeft -= 1;
				return;
				/*
					If the player hits a car we shove them back to the start and take a life
				*/
			}

		} else if(dynamic_cast<RiverWater*>(object) != 0) {
			if(GodQOL::BoxCollide(player->X(), player->Y(), player->W(), player->H(),
														object->X(), object->Y(), object->W(), object->H())) {
				touchingWater = true; // We still need to check if they are on a log
			}

		} else if(dynamic_cast<RiverLog*>(object) != 0) {
			if(GodQOL::BoxCollide(player->X(), player->Y(), player->W(), player->H(),
														object->X(), object->Y(), object->W(), object->H())) {
				touchingLog = true; // If they are touching any log they are considered on a log and are safe from the water
			}
		}
	}
	if (touchingWater == true && touchingLog == false) { // If they are on the water and not on a log they are dead.
		player->X((TILE_X*6)+(TILE_X*.5f));
		player->Y((TILE_Y*1)+(TILE_X*.5f));
		livesLeft -= 1;
		return;
	}

}

/* Car functions */
void GameState::InitCars() {
	// Bunch of code for making each car

	/*
		This is probably the messiest part of the whole game.
		I didn't want to hardcode every single car so I'm looping through each lane.
		Not the greatest way to do it, I'm sure, but it works.
		Get it fucking working.
	*/

	// (counting from the bottom) Road 1
	for(int i=0; i<4; ++i) {
		Car* car = new Car(); // Make the car object
		car->SpeedY( 0.f ); // Disable movement on the Y axis
		car->SpeedX( 1.5f * TILE_X ); // Positive is Left-Right movement, negitive is the reverse
		car->Y( (3*TILE_Y) + (TILE_X/2) ); // The row of tiles that the car will be driving on
		car->X( (i*4) * TILE_X ); // Spread the cars out along the road
		car->W( TILE_X-2 ); // Make the car just slightly smaller than a single "tile". It looks nicer that way and is a shortcut for a logic issue I'm to lazy to fix.
		car->H( TILE_X-2 );
		car->SpriteID( CreateSprite("./images/pieceRed_border13.png", car->W(), car->H(), car->DrawFromCenter()) ); // Load the car's sprite
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
	car->Move(deltaTime); // All the cars do is move. It's pretty simple.

}

/* Log functions */
void GameState::InitRiverLog() {
	/*
		The logs are basically cars.
		In fact, the only reason they are a different class is I needed a way to tell them appart for collision checking.
	*/

	// River 1
	for(int i=0; i<4; ++i) { // See GameState::InitCars (scroll up a bit) for an explination of this code
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
	riverLog->Move(deltaTime); // Again, all these do is move. Nothign fancy.

}

/* Water functions */
void GameState::InitRiverWater() {
	/*
		The water is an entity, but it doesn't ever get drawn.
		The line of code about the spriteID is just there to make sure it's placed properly on screen. Once placed it can be commented out and it will no longer be drawn in game.
	*/

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
	/*
		I don't even need to actually call this. The water doesn't move.
		It's speed is 0.f and it's move function doesn't do anything anyway.
		It's here just cause I guess.
	*/

	riverWater->Move(deltaTime);

}
