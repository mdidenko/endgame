#include "header.h"

void Draw_Missile(Settings_Struct* Set, Missile_Struct* Missile)
{
	Missile -> x_start = 100;
	Missile -> y_start = 100;
    Check_Hit(Set, Missile);
}

bool Check_Hit(Settings_Struct* Set, Missile_Struct* Missile)
{
	if(Missile -> x_end >= Set -> bomb.rect1.x && Missile -> x_end <= Set -> bomb.rect1.x + Set -> bomb.rect1.w)
	{
		if(Missile -> y_end >= Set -> bomb.rect1.y && Missile -> y_end <= Set -> bomb.rect1.y + Set -> bomb.rect1.h)
		{
			Set -> bomb.rect1.y = 0;
			time_t t;
			srand((unsigned)time(&t));
			int x = rand() % 1300;
			Set -> bomb.rect1.x = x;
			Set -> score = Set -> score + 1;
			return true;
		}
	}
	return false;
}

SDL_Rect Set_Coordinate(SDL_Rect rct, Settings_Struct* Set) 
{
	if(rct.y > 770)
	{
		SDL_BlitSurface(Set -> LossHP.ImageSurface, NULL, Set -> MainSurface, NULL);
		Set -> hp--;
		rct.y = 0;
		SDL_FillRect(Set -> MainSurface, NULL, 0x000000);
	}
	else
	{
		int speed;
		if(Set -> score < 20)
  		{
  			speed = 1;
  		}
  		if(Set -> score > 19)
  		{
  			speed = 2;
  		}		
		if(Set -> score > 39)
  		{
  			speed = 3;
  		}	
  		if(Set -> score > 59)
  		{
  			speed = 4;
  		}
  		if(Set -> score > 79)
  		{
  			speed = 5;
  		}
  		if(Set -> score > 99)
  		{
  			speed = 6;
  		}
 		rct.y = rct.y + speed;
	}

	if (rct.y == 0)
	{	
		time_t t;
		srand((unsigned)time(&t));
		rct.x = rand() % 1375;

		if(Set -> spawn_bombx == rct.x)
		{
			if(rct.x < 1230)
			{
				rct.x = rct.x + 100;
			}
			else
			{
				rct.x = rct.x - 200;
			}
			Set -> spawn_bombx = rct.x;
		}
	}
	return (rct);
}

void Motion(Settings_Struct *Set) 
{
	Set -> bomb.rect1 = Set_Coordinate(Set -> bomb.rect1, Set);
} 




