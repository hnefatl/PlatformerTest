#ifndef _PLAYER_H
#define _PLAYER_H

#include "GameEntity.h"
#include "AnimatedEntity.h"

class Player
	: public AnimatedEntity
{
public:
	Player();

	virtual bool Initialise(SDL_Renderer *const Renderer);

	virtual void Update(const SDL_Event &Event);
	virtual void Draw(SDL_Renderer *const Renderer);

protected:
};

#endif