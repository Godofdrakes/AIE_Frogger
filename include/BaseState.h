#ifndef _BASESTATE_H_
#define _BASESTATE_H_

#include <vector> // std::vector
#include "Entity.h" // Virtual Class Entity : public Sprite

class StateMachine;

class BaseState {
private:
protected:
	static std::vector<Sprite*> mapTiles;
	static std::vector<Entity*> gameObjects;

	static bool enableCollision;
	static float speedMod;

public:
	BaseState(void) {};
	~BaseState(void) {};

	virtual void Init() = 0;
	virtual void Update(float deltaTime, StateMachine* a_pSM) = 0;

	virtual void Draw() = 0;
	virtual void Destroy() = 0;

};

#endif
