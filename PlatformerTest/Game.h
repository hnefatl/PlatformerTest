#ifndef _GAME_H
#define _GAME_H

#include "SDLWindow.h"
#include "Player.h"

#include <SDL.h>
#include <vector>

class Game
{
public:
	Game();
	~Game();

	bool Initialise();

	void Run();

protected:
	bool Update();
	void Draw();

	SDLWindow Window;

	std::vector<GameEntity *> Entities;
};

#endif