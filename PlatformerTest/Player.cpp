#include "Player.h"

Player::Player()
{
}

bool Player::Initialise(SDL_Renderer *const Renderer)
{
	if(!Image.Load(Resources::Sprites::Player, Renderer))
	{
		return false;
	}
	
	// Set up clips
	Clips=6;
	ClipSet=0;
	ClipAdvancement.x=48;
	ClipAdvancement.y=32;
	ClipAdvancement.w=Image.GetWidth()/Clips;
	ClipAdvancement.h=Image.GetHeight()/4;
	UpdatesPerClip=4; // At 50 fps, this'll be 0.16 seconds

	return true;
}

void Player::Update(const SDL_Event &Event)
{
	AnimatedEntity::Update(Event);
}
void Player::Draw(SDL_Renderer *const Renderer)
{
	Image.Render(Renderer, Position.x, Position.y, &GetCurrentClip());
}