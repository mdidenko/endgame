#include "header.h"

void Load_Resources(Settings_Struct *Set, Audio_Struct* Audio)
{
	Load_Images(Set);
	Load_Audio(Audio);
	Load_Fonts(Set);
}

void Load_Images(Settings_Struct *Set)
{
	if ((Set -> MenuSurface = IMG_Load("./resource/images/Menu.png")) == NULL)
	{	
		SDL_Error_Case();
	}
	if ((Set -> ScreenSurface = IMG_Load("./resource/images/Screen.png")) == NULL)
	{	
		SDL_Error_Case();
	}
	if ((Set -> bomb.ImageSurface = IMG_Load("./resource/images/bomb.png")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((Set -> health.ImageSurface = IMG_Load("./resource/images/hp.png")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((Set -> LossHP.ImageSurface = IMG_Load("./resource/images/LossHP.png")) == NULL)
	{
		SDL_Error_Case();
	}
}

void Load_Audio(Audio_Struct* music)
{	
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		SDL_Error_Case();
	}
	if ((music -> beat1 = Mix_LoadMUS("./resource/music/Beat1.mp3")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((music -> beat2 = Mix_LoadMUS("./resource/music/Beat2.mp3")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((music -> beat3 = Mix_LoadMUS("./resource/music/Beat3.mp3")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((music-> shot = Mix_LoadMUS("./resource/music/shot.mp3")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((music -> hit = Mix_LoadMUS("./resource/music/hit.mp3")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((music -> LossHP = Mix_LoadMUS("./resource/music/LossHP.mp3")) == NULL)
	{
		SDL_Error_Case();
	}
	if ((music -> GameOver = Mix_LoadMUS("./resource/music/GameOver.mp3")) == NULL)
	{
		SDL_Error_Case();
	}
}

void Load_Fonts(Settings_Struct *Set)
{
	if(TTF_Init() == -1)
	{
		SDL_Error_Case();
	}
	if((Set -> font = TTF_OpenFont("./resource/ttf/font.ttf", 30)) == NULL)
	{
		SDL_Error_Case();
	}
}
