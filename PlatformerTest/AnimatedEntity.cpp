#include "AnimatedEntity.h"

AnimatedEntity::AnimatedEntity()
	:Clips(0),
	ClipSet(0),
	CurrentClip(0),
	UpdatesPerClip(0),
	ClipUpdates(0)
{
}

void AnimatedEntity::Update(const SDL_Event &Event)
{
	ClipUpdates++;
	if(ClipUpdates>=UpdatesPerClip)
	{
		// Advance the clip
		ClipUpdates=0;
		CurrentClip++;
		// If we've reachd the end, loop back to the beginning
		if(CurrentClip>=Clips)
		{
			CurrentClip=0;
		}
	}
}

SDL_Rect AnimatedEntity::GetCurrentClip()
{
	// Create a new Rect of the clip that needs to be displayed
	SDL_Rect Clip;
	Clip.x=ClipAdvancement.x * CurrentClip;
	Clip.y=ClipAdvancement.y * ClipSet;
	Clip.h=ClipAdvancement.h;
	Clip.w=ClipAdvancement.w;

	return Clip;
}