#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include "Util.h"

#include "SDLWindow.h"
#include "Resources.h"
#include "Texture.h"

#include <SDL.h>

class GameEntity
{
public:
	GameEntity();

	virtual bool Initialise(SDL_Renderer *const Renderer)=0;

	virtual void Update(const SDL_Event &Event);
	virtual void Draw(SDL_Renderer *const Renderer);

	bool IsRemovable() const;

protected:
	Texture Image;
	SDL_Rect Position;

	bool Removable;
};

#endif