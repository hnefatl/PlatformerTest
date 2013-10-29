#include "GameEntity.h"

GameEntity::GameEntity()
{
	Removable=false;
	Image=NULL;
	Position.x=0;
	Position.y=0;
	Position.h=0;
	Position.w=0;
}

bool GameEntity::Initialise(SDLWindow &Window)
{
	return true;
}

void GameEntity::Update(const SDL_Event &Event)
{
	// Do nothing
}
void GameEntity::Draw(SDLWindow &Window)
{
	// Do nothing
}

bool GameEntity::IsRemovable() const
{
	return Removable;
}