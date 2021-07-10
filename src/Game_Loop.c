#include "header.h"

void Game_Loop(Settings_Struct *Set, Audio_Struct* music, Missile_Struct* Missile) 
{
	SDL_Event move_event;
	bool GameOver = false;
	
	if (Mix_PlayMusic(music -> beat1 , 1) < 0)
	{
		SDL_Error_Case();
	}

	while (GameOver == false) 
	{
		while (SDL_PollEvent(&move_event)) 
		{	
			int key = move_event.key.keysym.sym;
			int button = move_event.button.button;
			if(move_event.type == SDL_MOUSEBUTTONDOWN)
			{
				switch(button)
				{
					case SDL_QUIT: 
						GameOver = true;
						break;
					case SDL_BUTTON_LEFT:
						Missile -> x_end = move_event.motion.x;
						Missile -> y_end = move_event.motion.y;

						Draw_Missile(Set, Missile);
						break;
				}
			}
			else if(move_event.type == SDL_KEYDOWN)
			{
				switch(key)
				{
					case SDLK_ESCAPE:
						GameOver = true;
						break;
				}
			}
		}
		if (Set -> hp > 0)
		{
  			Motion(Set);
  		}
		Draw_Window(Set);
	}

	SDL_FreeSurface(Set -> MainSurface);
	SDL_DestroyWindow(Set -> window);
	TTF_CloseFont(Set -> font);
	TTF_Quit();
	SDL_Quit();
}
