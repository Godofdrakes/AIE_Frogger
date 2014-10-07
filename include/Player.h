#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AIE.h"
#include "Entity.h"

extern const int TILE_X;
extern const int TILE_Y;
extern const unsigned int WINDOW_W;
extern const unsigned int WINDOW_H;

class Player : public Entity {
private:
protected:
	unsigned int keyUp, keyDown, keyLeft, keyRight; // Keybinds
	float keyDelay; // How long to wait before allowing the next keypress
	float currentKeyDelay; // Remaining time before delay is finished

public:

	Player::Player(void);
	Player::~Player(void);

	virtual void Move(float deltaTime);
};

#endif
