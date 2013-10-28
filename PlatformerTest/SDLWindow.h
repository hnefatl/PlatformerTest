#ifndef _SDLWINDOW_H
#define _SDLWINDOW_H

#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class SDLWindow
{
public:
	SDLWindow();
	~SDLWindow();

	bool Create(const unsigned int &WindowWidth, const unsigned int &WindowHeight, const std::string &Title,
		const SDL_WindowFlags &Flags=SDL_WindowFlags::SDL_WINDOW_SHOWN);

	bool LoadImage(const std::string &FileName, SDL_Texture *Output) const;
	bool ConvertSurfaceToImage(SDL_Surface *Image, SDL_Texture *Output) const;
	void FreeImage(SDL_Texture *Image) const;
	void FreeImage(SDL_Surface *Image) const;

	void BeginScene();
	void EndScene();

	void DrawSprite(SDL_Texture *const Image, const SDL_Rect *Source, const SDL_Rect *Destination);
	void DrawSprite(SDL_Texture *const Image, const SDL_Rect *Source, const SDL_Rect *Destination,
		const double &Angle, SDL_Point *const Centre, const SDL_RendererFlip &Flip=SDL_RendererFlip::SDL_FLIP_NONE);

	bool CreateText(const std::string &Text, const unsigned int &Size,
		const SDL_Colour &Back, const SDL_Colour &Fore,
		SDL_Texture *Output);

	void SetBackgroundColour(const SDL_Colour &Background);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

protected:
	SDL_Window *Window;
	SDL_Renderer *Renderer;

	unsigned int Width;
	unsigned int Height;

	TTF_Font *Font;

	SDL_Colour Background;
};

#endif