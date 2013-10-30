#include <SDL.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include "Util.h"

#include "Game.h"

int main(int argc, char *argv[])
{
	UtilInitialise();
	Game PlatformerTest;
	if(!PlatformerTest.Initialise())
	{
		return -1;
	}
	PlatformerTest.Run();

	return 0;
}