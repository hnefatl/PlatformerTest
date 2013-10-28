#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include "SDLWindow.h"
#include <SDL.h>

class GameEntity
{
public:
	virtual void Update(const SDL_Event &Event);
	virtual void Draw(SDLWindow &Window);

};

#endif