#include "Player.h"

Player::Player()
{

}

bool Player::Initialise(SDLWindow &Window)
{
	if(!Window.LoadImage(Resources::Sprites::Player, Image))
	{
		return false;
	}

	return true;
}

void Player::Update(const SDL_Event &Event)
{

}
void Player::Draw(SDLWindow &Window)
{

}