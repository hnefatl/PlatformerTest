#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include "SDLWindow.h"
#include "Resources.h"
#include "Texture.h"

#include <SDL.h>

class GameEntity
{
public:
	GameEntity();

	virtual bool Initialise()=0;

	virtual void Update(const SDL_Event &Event);
	virtual void Draw(SDL_Renderer &Window);

	bool IsRemovable() const;

protected:
	Texture Image;
	SDL_Rect Position;

	bool Removable;
};

#endif