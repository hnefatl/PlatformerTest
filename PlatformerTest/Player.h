#ifndef _PLAYER_H
#define _PLAYER_H

#include "GameEntity.h"

class Player
	: public GameEntity
{
public:
	Player();

	virtual bool Initialise(SDLWindow &Window);

	virtual void Update(const SDL_Event &Event);
	virtual void Draw(SDLWindow &Window);

protected:
	SDL_Texture *Image;
	SDL_Rect Position;
};

#endif