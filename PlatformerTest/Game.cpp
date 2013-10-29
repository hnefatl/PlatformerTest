#include "Game.h"

Game::Game()
{

}

void Game::Run()
{
	while(Update())
	{
		Draw();
	}
}

bool Game::Update()
{
	SDL_Event Event;
	while(SDL_PollEvent(&Event))
	{
		if(Event.type==SDL_EventType::SDL_QUIT)
		{
			return false;
		}
	}



	return true;
}
void Game::Draw()
{
	Window.BeginScene();



	Window.EndScene();
}