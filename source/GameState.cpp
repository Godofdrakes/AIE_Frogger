#include "GameState.h"

GameState::GameState(void) {}
GameState::~GameState(void) {}

void GameState::Init() {
	//MakeCars();
	MakePlayer();

}

void GameState::Update (float deltaTime, StateMachine* a_pSM) {
	//UpdateCars(deltaTime);
	UpdatePlayer(deltaTime);
	if (IsKeyDown(GLFW_KEY_TAB)) {
		delete a_pSM->PopState();;
	}

}

void GameState::Draw() {
	DrawSprite(player->SpriteID());/*
	for(int i=0; i<3; ++i) { DrawSprite( lane_A[i]->SpriteID() ); }
	for(int i=0; i<3; ++i) { DrawSprite( lane_B[i]->SpriteID() ); }
	for(int i=0; i<3; ++i) { DrawSprite( lane_C[i]->SpriteID() ); }*/
}

void GameState::Destroy() {
	//DestroyCars();
	DestroyPlayer();

}

/* Player functions */

void GameState::MakePlayer() {
	player = new Player();
	player->SpriteID( CreateSprite("./images/Space-Invaders-Marquee.png", player->W(), player->H(), true) );

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
		lane_A[i]->SpriteID( CreateSprite("./images/Space-Invaders-Marquee.png", lane_A[i]->W(), lane_A[i]->H(), true) );
	}

	for(int i=0; i<3; ++i) {
		lane_B[i] = new Entity();
		lane_B[i]->SpriteID( CreateSprite("./images/Space-Invaders-Marquee.png", lane_B[i]->W(), lane_B[i]->H(), true) );
	}

	for(int i=0; i<3; ++i) {
		lane_C[i] = new Entity();
		lane_C[i]->SpriteID( CreateSprite("./images/Space-Invaders-Marquee.png", lane_C[i]->W(), lane_C[i]->H(), true) );
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
