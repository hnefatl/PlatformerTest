#include "Game.h"

#include "Util.h"

#include "Timer.h"

#ifdef _DEBUG
#include <sstream>
#endif

Game::Game()
{
}
Game::~Game()
{
	for(unsigned int x=0; x<Entities.size(); x++)
	{
		delete Entities[x];
		Print("Deleted Entity.");
	}
}

bool Game::Initialise()
{
	if(!Window.Create(480, 480, "Platformer Test"))
	{
		Print("Failed to create window.");
		return false;
	}
	Print("Window initialised.");
	SDL_Colour Background;
	Background.r=0;
	Background.b=0;
	Background.g=0;
	Window.SetBackgroundColour(Background);

	Entities.push_back(new Player());


	for(unsigned int x=0; x<Entities.size(); x++)
	{
		if(!Entities[x]->Initialise(Window.GetRenderer()))
		{
			Print("Failed to initialise Entity.");
			return false;
		}
	}

	return true;
}

void Game::Run()
{
	Print("Game started.");
	const unsigned int FramesPerSecond=50;
	const unsigned int ScreenTicksPerFrame=1000/FramesPerSecond;
	unsigned int Frames=0;
	Timer FPS;
	Timer CapTimer;

#ifdef _DEBUG
	Timer Updater;
	Updater.Start();
#endif

	bool Run=true;
	FPS.Start();
	while(Run)
	{
		CapTimer.Start();
		Run=Update();
		Draw();
		Frames++;

		unsigned int FrameTicks=CapTimer.GetTicks();

		if(FrameTicks<ScreenTicksPerFrame)
		{
			SDL_Delay(ScreenTicksPerFrame-CapTimer.GetTicks());
		}

#ifdef _DEBUG
		unsigned int AverageFPS=Frames/(FPS.GetTicks()/1000.0f);
		if(Updater.GetTicks()>1000) // After a second, display fps
		{
			std::stringstream ss;
			ss<<AverageFPS;
			SDL_SetWindowTitle(Window.GetWindow(), ss.str().c_str());
			Updater.Start();
		}
#endif
	}
}

bool Game::Update()
{
	SDL_Event Event;
	while(SDL_PollEvent(&Event))
	{
		if(Event.type==SDL_EventType::SDL_QUIT)
		{
			Print("Quit message handled.");
			return false;
		}
	}

	for(unsigned int x=0; x<Entities.size(); x++)
	{
		Entities[x]->Update(Event);
		if(Entities[x]->IsRemovable())
		{
			Entities.erase(Entities.begin()+x);
		}
	}

	return true;
}
void Game::Draw()
{
	Window.BeginScene();

	for(unsigned int x=0; x<Entities.size(); x++)
	{
		Entities[x]->Draw(Window.GetRenderer());
	}

	Window.EndScene();
}