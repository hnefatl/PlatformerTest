#include "SDLWindow.h"

SDLWindow::SDLWindow()
{
	Font=NULL;
	Background.a=0;
	Background.b=0;
	Background.g=0;
	Background.r=0;
}
SDLWindow::~SDLWindow()
{
	SDL_DestroyWindow(Window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool SDLWindow::Create(const unsigned int &Width, const unsigned int &Height, const std::string &Title,const SDL_WindowFlags &Flags)
{
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		return false;
	}

	// Create the ImageFlags - JPG and PNG
	int ImgFlags=0 | IMG_InitFlags::IMG_INIT_JPG | IMG_InitFlags::IMG_INIT_PNG;

	if(IMG_Init(ImgFlags)!=ImgFlags)
	{
		return false;
	}
	if(TTF_Init()<0)
	{
		return false;
	}

	Window=SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, Flags);
	if(Window==NULL)
	{
		return false;
	}
	Renderer=SDL_CreateRenderer(Window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if(Renderer==NULL)
	{
		return false;
	}

	return true;
}

bool SDLWindow::LoadImage(const std::string &FileName, SDL_Texture *Output) const
{
	SDL_Surface *Surface=IMG_Load(FileName.c_str());
	if(Surface==NULL)
	{
		return false;
	}

	SDL_Texture *Buffer=SDL_CreateTextureFromSurface(Renderer, Surface);
	if(Buffer==NULL)
	{
		return false;
	}

	if(Output!=NULL)
	{
		FreeImage(Output);
	}
	Output=Buffer;

	return true;
}
bool SDLWindow::ConvertSurfaceToImage(SDL_Surface *Image, SDL_Texture *Output) const
{
	SDL_Texture *Buffer=SDL_CreateTextureFromSurface(Renderer, Image);

	FreeImage(Image);
	if(Buffer==NULL)
	{
		return false;
	}

	Output=Buffer;
	return true;
}

void SDLWindow::FreeImage(SDL_Surface *Image) const
{
	SDL_FreeSurface(Image);
	Image=NULL;
}
void SDLWindow::FreeImage(SDL_Texture *Image) const
{
	SDL_DestroyTexture(Image);
	Image=NULL;
}

void SDLWindow::BeginScene()
{
	SDL_RenderClear(Renderer);
}
void SDLWindow::EndScene()
{
	SDL_RenderPresent(Renderer);
}

void SDLWindow::DrawSprite(SDL_Texture *const Image, const SDL_Rect *Source, const SDL_Rect *Destination)
{
	SDL_RenderCopy(Renderer, Image, Source, Destination);
}
void SDLWindow::DrawSprite(SDL_Texture *const Image, const SDL_Rect *Source, const SDL_Rect *Destination,
						   const double &Angle, SDL_Point *const Centre, const SDL_RendererFlip &Flip)
{
	SDL_RenderCopyEx(Renderer, Image, Source, Destination, Angle, Centre, Flip);
}

bool SDLWindow::CreateText(const std::string &Text, const unsigned int &Size,
						 const SDL_Colour &Back, const SDL_Colour &Fore,
						 SDL_Texture *Output)
{
	Font=TTF_OpenFont("Arial.ttf", Size);

	SDL_Texture *Buffer=NULL;
	if(!ConvertSurfaceToImage(TTF_RenderText_Shaded(Font, Text.c_str(), Fore, Back), Buffer))
	{
		return false;
	}

	Output=Buffer;

	return true;
}

void SDLWindow::SetBackgroundColour(const SDL_Colour &Background)
{
	this->Background=Background;
	SDL_SetRenderDrawColor(Renderer, Background.r, Background.g, Background.b, Background.a);
}

unsigned int SDLWindow::GetWidth() const
{
	return Width;
}
unsigned int SDLWindow::GetHeight() const
{
	return Height;
}