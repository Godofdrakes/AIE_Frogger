#include "GameState.h"

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	MakeMap();
	MakeCars();
	MakePlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	UpdateMap(); // Doesn't actually do anything right now
	UpdateCars(deltaTime);
	UpdatePlayer(deltaTime);

	// Check if car hit player

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


	if( IsKeyDown(GLFW_KEY_TAB) ) { delete a_pSM->PopState(); }

}

// Didn't split the draw functions into seperate functions cause all the objects are based off of sprite so the method of drawing them won't change
void GameState::Draw() {
	/* Draw map */for(int count = 0; count < 225; ++count) DrawSprite( map[count].SpriteID() );
	/* Draw movementMarker */DrawSprite( movementMarker->SpriteID() );
	/* Draw slowLane_A */for(int i=0; i<4; ++i) DrawSprite( slowLane_A[i]->SpriteID() );
	/* Draw slowLane_B */for(int i=0; i<4; ++i) DrawSprite( slowLane_B[i]->SpriteID() );
	/* Draw fastLane_A */for(int i=0; i<4; ++i) DrawSprite( fastLane_A[i]->SpriteID() );
	/* Draw fastLane_B */for(int i=0; i<3; ++i) DrawSprite( fastLane_B[i]->SpriteID() );
	/* Draw fastLane_C */for(int i=0; i<2; ++i) DrawSprite( fastLane_C[i]->SpriteID() );
	/* Draw riverLane_A */for(int i=0; i<3; ++i) DrawSprite( riverLane_A[i]->SpriteID() );
	/* Draw riverLane_B */for(int i=0; i<4; ++i) DrawSprite( riverLane_B[i]->SpriteID() );
	/* Draw riverLane_C */for(int i=0; i<3; ++i) DrawSprite( riverLane_C[i]->SpriteID() );
	/* Draw player */DrawSprite( player->SpriteID() );

}

void GameState::Destroy() {
	DestroyCars();
	DestroyMap();
	DestroyPlayer();

}

/* Player functions */

void GameState::MakePlayer() {
	player = new Player();
	player->X(TILE_X*.5f);
	player->Y(TILE_Y*.5f);
	player->W(TILE_X-2);
	player->H(TILE_Y-2);
	player->SpriteID( CreateSprite("./images/pieceRed_border06.png", player->W(), player->H(), player->DrawFromCenter()) );

	movementMarker = new Sprite();
	movementMarker->X(player->X());
	movementMarker->Y(player->Y());
	movementMarker->W(player->W()*3);
	movementMarker->H(player->H()*3);
	movementMarker->SpriteID( CreateSprite("./images/kenneyRoad/terrainTile1.png", movementMarker->W(), movementMarker->H(), movementMarker->DrawFromCenter()) );

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
void GameState::MakeCars() {
	// Bunch of code for making each car
	for(int i=0; i<4; ++i) {
		slowLane_A[i] = new Car();
		slowLane_A[i]->Direction(-1.f); // Go left
		slowLane_A[i]->Y( (4*TILE_Y)-(TILE_Y*.5f) ); // 4th row of tiles from the bottom
		slowLane_A[i]->X((i*4)*TILE_X); // 4 tiles in between each car
		slowLane_A[i]->W(TILE_X-2);
		slowLane_A[i]->H(TILE_Y-2);
		slowLane_A[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", slowLane_A[i]->W(), slowLane_A[i]->H(), slowLane_A[i]->DrawFromCenter()) );
	}
	for(int i=0; i<4; ++i) {
		slowLane_B[i] = new Car();
		slowLane_B[i]->Direction(2.f);
		slowLane_B[i]->Y( (5*TILE_Y)-(TILE_Y*.5f) );
		slowLane_B[i]->X((i*4)*TILE_X);
		slowLane_B[i]->W(TILE_X-2);
		slowLane_B[i]->H(TILE_Y-2);
		slowLane_B[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", slowLane_B[i]->W(), slowLane_B[i]->H(), slowLane_B[i]->DrawFromCenter()) );
	}
	for(int i=0; i<4; ++i) {
		fastLane_A[i] = new Car();
		fastLane_A[i]->Direction(3.33f);
		fastLane_A[i]->Y( (7*TILE_Y)-(TILE_Y*.5f) );
		fastLane_A[i]->X((i*4)*TILE_X);
		fastLane_A[i]->W(TILE_X-2);
		fastLane_A[i]->H(TILE_Y-2);
		fastLane_A[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", fastLane_A[i]->W(), fastLane_A[i]->H(), fastLane_A[i]->DrawFromCenter()) );
	}
	for(int i=0; i<3; ++i) {
		fastLane_B[i] = new Car();
		fastLane_B[i]->Direction(-4.66f);
		fastLane_B[i]->Y( (8*TILE_Y)-(TILE_Y*.5f) );
		fastLane_B[i]->X((i*6)*TILE_X);
		fastLane_B[i]->W(TILE_X-2);
		fastLane_B[i]->H(TILE_Y-2);
		fastLane_B[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", fastLane_B[i]->W(), fastLane_B[i]->H(), fastLane_B[i]->DrawFromCenter()) );
	}
	for(int i=0; i<2; ++i) {
		fastLane_C[i] = new Car();
		fastLane_C[i]->Direction(6.f);
		fastLane_C[i]->Y( (9*TILE_Y)-(TILE_Y*.5f) );
		fastLane_C[i]->X((i*8)*TILE_X);
		fastLane_C[i]->W((TILE_X-2)*2);
		fastLane_C[i]->H(TILE_Y-2);
		fastLane_C[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", fastLane_C[i]->W(), fastLane_C[i]->H(), fastLane_C[i]->DrawFromCenter()) );
	}
	for(int i=0; i<3; ++i) {
		riverLane_A[i] = new Car();
		riverLane_A[i]->Direction(-1.f);
		riverLane_A[i]->Y( (11*TILE_Y)-(TILE_Y*.5f) );
		riverLane_A[i]->X((i*6)*TILE_X);
		riverLane_A[i]->W((TILE_X-2)*3);
		riverLane_A[i]->H(TILE_Y-2);
		riverLane_A[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", riverLane_A[i]->W(), riverLane_A[i]->H(), riverLane_A[i]->DrawFromCenter()) );
	}
	for(int i=0; i<4; ++i) {
		riverLane_B[i] = new Car();
		riverLane_B[i]->Direction(3.33f);
		riverLane_B[i]->Y( (12*TILE_Y)-(TILE_Y*.5f) );
		riverLane_B[i]->X((i*4)*TILE_X);
		riverLane_B[i]->W((TILE_X-2)*3);
		riverLane_B[i]->H(TILE_Y-2);
		riverLane_B[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", riverLane_B[i]->W(), riverLane_B[i]->H(), riverLane_B[i]->DrawFromCenter()) );
	}
	for(int i=0; i<3; ++i) {
		riverLane_C[i] = new Car();
		riverLane_C[i]->Direction(3.33f);
		riverLane_C[i]->Y( (13*TILE_Y)-(TILE_Y*.5f) );
		riverLane_C[i]->X((i*6)*TILE_X);
		riverLane_C[i]->W((TILE_X-2)*3);
		riverLane_C[i]->H(TILE_Y-2);
		riverLane_C[i]->SpriteID( CreateSprite("./images/pieceRed_border13.png", riverLane_C[i]->W(), riverLane_C[i]->H(), riverLane_C[i]->DrawFromCenter()) );
	}
}

void GameState::UpdateCars(float deltaTime) {
	for(int i=0; i<4; ++i) {
		slowLane_A[i]->Move(deltaTime);
		MoveSprite(slowLane_A[i]->SpriteID(), slowLane_A[i]->X(), slowLane_A[i]->Y());
	}
	for(int i=0; i<4; ++i) {
		slowLane_B[i]->Move(deltaTime);
		MoveSprite(slowLane_B[i]->SpriteID(), slowLane_B[i]->X(), slowLane_B[i]->Y());
	}
	for(int i=0; i<4; ++i) {
		fastLane_A[i]->Move(deltaTime);
		MoveSprite(fastLane_A[i]->SpriteID(), fastLane_A[i]->X(), fastLane_A[i]->Y());
	}
	for(int i=0; i<3; ++i) {
		fastLane_B[i]->Move(deltaTime);
		MoveSprite(fastLane_B[i]->SpriteID(), fastLane_B[i]->X(), fastLane_B[i]->Y());
	}
	for(int i=0; i<2; ++i) {
		fastLane_C[i]->Move(deltaTime);
		MoveSprite(fastLane_C[i]->SpriteID(), fastLane_C[i]->X(), fastLane_C[i]->Y());
	}
	for(int i=0; i<3; ++i) {
		riverLane_A[i]->Move(deltaTime);
		MoveSprite(riverLane_A[i]->SpriteID(), riverLane_A[i]->X(), riverLane_A[i]->Y());
	}
	for(int i=0; i<4; ++i) {
		riverLane_B[i]->Move(deltaTime);
		MoveSprite(riverLane_B[i]->SpriteID(), riverLane_B[i]->X(), riverLane_B[i]->Y());
	}
	for(int i=0; i<3; ++i) {
		riverLane_C[i]->Move(deltaTime);
		MoveSprite(riverLane_C[i]->SpriteID(), riverLane_C[i]->X(), riverLane_C[i]->Y());
	}

}

void GameState::DestroyCars() {
	for(int i=0; i<4; ++i) {
		DestroySprite(slowLane_A[i]->SpriteID());
		delete slowLane_A[i];
	}
	for(int i=0; i<4; ++i) {
		DestroySprite(slowLane_B[i]->SpriteID());
		delete slowLane_B[i];
	}
	for(int i=0; i<4; ++i) {
		DestroySprite(fastLane_A[i]->SpriteID());
		delete fastLane_A[i];
	}
	for(int i=0; i<3; ++i) {
		DestroySprite(fastLane_B[i]->SpriteID());
		delete fastLane_B[i];
	}
	for(int i=0; i<2; ++i) {
		DestroySprite(fastLane_C[i]->SpriteID());
		delete fastLane_C[i];
	}
	for(int i=0; i<3; ++i) {
		DestroySprite(riverLane_A[i]->SpriteID());
		delete riverLane_A[i];
	}
	for(int i=0; i<4; ++i) {
		DestroySprite(riverLane_B[i]->SpriteID());
		delete riverLane_B[i];
	}
	for(int i=0; i<3; ++i) {
		DestroySprite(riverLane_C[i]->SpriteID());
		delete riverLane_C[i];
	}

}

/* Map fucntions */

void GameState::MakeMap() {
	int count = 0; // Which map tile are we currently working on?

	for(int column = 0; column < 15; ++column) {
		for(int row = 0; row < 15; ++row) {
			Sprite tile;
			map[count] = tile;
			map[count].X( (column*TILE_X)+(TILE_X*.5f) );
			map[count].Y( (row*TILE_Y)+(TILE_Y*.5f) );
			if(row == 3 || row == 4 || row == 6 || row == 7 || row == 8) { // Offset by -1 due to math stuff
				// Make it a road tile
				map[count].SpriteID( CreateSprite("./images/kenneyRoad/roadTile6.png", map[count].W(), map[count].H(), map[count].DrawFromCenter()) );
			} if(row == 10 || row == 11 || row == 12) {
				// Make it a water tile
				map[count].SpriteID( CreateSprite("./images/kenneyRoad/terrainTile6.png", map[count].W(), map[count].H(), map[count].DrawFromCenter()) );
			} else {
				// Make it a grass tile
				map[count].SpriteID( CreateSprite("./images/kenneyRoad/terrainTile3.png", map[count].W(), map[count].H(), map[count].DrawFromCenter()) );
			}

			count++; // Be sure to increment for the next tile.
		}
	}
}

void GameState::UpdateMap() {
	for(int count = 0; count < 225; ++count) {
		MoveSprite( map[count].SpriteID(), map[count].X(), map[count].Y() );
	}
}

void GameState::DestroyMap() {
}

// Hit detection using the pythagrian theorum
bool GameState::CheckHit(Player &thePlayer, Car &theCar) {
	float a = ( theCar.X() - thePlayer.X() );
	float b = ( theCar.Y() - thePlayer.Y() );
	float c = (a*a)+(b*b);
	if(sqrt(c)<TILE_X*0.75f) { return true; } else { return false; }

}
