#ifndef _GAME_H
#define _GAME_H

#include "SDLWindow.h"

#include <SDL.h>
#include <vector>

class Game
{
public:
	Game();

	void Run();

protected:
	bool Update();
	void Draw();

	SDLWindow Window;
};

#endif