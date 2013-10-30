#ifndef _ANIMATEDENTITY_H
#define _ANIMATEDENTITY_H

#include "GameEntity.h"

class AnimatedEntity
	: public GameEntity
{
public:
	AnimatedEntity();
	
	virtual void Update(const SDL_Event &Event);

protected:
	SDL_Rect GetCurrentClip();

	unsigned int ClipSet;
	unsigned int Clips;
	unsigned int CurrentClip;
	unsigned int UpdatesPerClip;
	unsigned int ClipUpdates;
	SDL_Rect ClipAdvancement;
};

#endif