#include "header.h"

void Create_Window(Settings_Struct *Set) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{	
		SDL_Error_Case();
	}
	
	Set -> width = 1440;
	Set -> height = 900;
	Set -> window = SDL_CreateWindow("Bomb Zone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Set -> width, Set -> height, SDL_WINDOW_SHOWN);
	
	if (Set -> window == NULL) 
	{
	    SDL_Error_Case();
	}
	if ((Set -> MainSurface = SDL_GetWindowSurface(Set -> window)) == NULL)
	{
		SDL_Error_Case();
	}
}

void Draw_Menu(Settings_Struct* Set)
{
	SDL_BlitSurface(Set -> MenuSurface, NULL, Set -> MainSurface, NULL);
	SDL_UpdateWindowSurface(Set -> window);

	SDL_Event menu_event;
	int key = 0;
	bool Start_Play = false;
	while(Start_Play == false)
	{
		while (SDL_PollEvent(&menu_event)) 
		{	
			if(menu_event.type == SDL_KEYDOWN)
			{
				key = menu_event.key.keysym.sym;
				switch(key)
				{
					case SDLK_RETURN:

						Start_Play = true;
						break;
					case SDLK_ESCAPE:
						exit(0);
						break;
				}
			}
		}
	}
	SDL_FillRect(Set -> MenuSurface, NULL, 0x000000);
	SDL_FreeSurface(Set -> MenuSurface);
}

void Draw_Window(Settings_Struct *Set) 
{

	SDL_BlitSurface(Set -> ScreenSurface, NULL, Set -> MainSurface, NULL);
	Draw_HP(Set);
	Draw_Score(Set);
	if (Set -> hp > 0) 
	{
		SDL_BlitSurface(Set -> bomb.ImageSurface, NULL, Set -> MainSurface, &Set -> bomb.rect1);
	}
	SDL_UpdateWindowSurface(Set -> window);
}
