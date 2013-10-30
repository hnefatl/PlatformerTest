#include "GameEntity.h"

GameEntity::GameEntity()
{
	Removable=false;
	Position.x=0;
	Position.y=0;
	Position.h=0;
	Position.w=0;
}

bool GameEntity::Initialise(SDL_Renderer *const Renderer)
{
	return true;
}

void GameEntity::Update(const SDL_Event &Event)
{
	// Do nothing
}
void GameEntity::Draw(SDL_Renderer *const Renderer)
{
	// Do nothing
}

bool GameEntity::IsRemovable() const
{
	return Removable;
}