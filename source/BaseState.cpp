#include "BaseState.h"

std::vector<Sprite*> BaseState::mapTiles;
std::vector<Entity*> BaseState::gameObjects;
bool BaseState::enableCollision = true;
float BaseState::speedMod = 1.f;