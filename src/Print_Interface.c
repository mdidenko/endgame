#include "header.h"

void Draw_HP(Settings_Struct* Set) 
{
	Set -> health.rect1 = Set -> health.ImageSurface -> clip_rect;
	for (int i = 0; i < Set -> hp; i++) 
	{
		SDL_BlitSurface(Set -> health.ImageSurface, NULL, Set -> MainSurface, &Set -> health.rect1);
		Set -> health.rect1.x += 50;
	}
}

void Draw_Score(Settings_Struct* Set)
{
	char str[30];
 	SDL_Color color = {0, 0, 0, 0};
 	Set -> txt = TTF_RenderText_Solid(Set -> font, SDL_itoa(Set -> score, str, 10), color);
 	SDL_Rect nbr = Set -> txt -> clip_rect;
 	nbr.x = 720;
 	SDL_BlitSurface(Set -> txt ,NULL, Set -> MainSurface, &nbr);
 	if (Set -> hp <= 0) 
 	{
 		SDL_Color color = {255, 0, 0, 0};
 		Set -> Game_Over = TTF_RenderText_Solid(Set -> font, "Game  Over", color);
  		nbr.x = 660;
  		nbr.y = 450;
  		SDL_BlitSurface(Set -> ScreenSurface , NULL, Set -> MainSurface, NULL);
  		SDL_BlitSurface(Set -> Game_Over , NULL, Set -> MainSurface, &nbr);
 	}
}
