#include "header.h"

int main() 
{
	SDL_ClearError();
	Settings_Struct* Set = (Settings_Struct*)malloc(sizeof(Settings_Struct));
	if(Set == NULL)
	{
		General_Error_Case();
	}
	
	Audio_Struct* Audio = (Audio_Struct*)malloc(sizeof(Audio_Struct));
	if(Audio == NULL)
	{
		General_Error_Case();
	}

	Create_Window(Set);
	Load_Resources(Set, Audio);
	Draw_Menu(Set);
	
	Set -> hp = 10;
	Set -> score = 0; 

	Draw_Window(Set);
	Missile_Struct* Missile = (Missile_Struct*)malloc(sizeof(Missile_Struct));
	if(Missile == NULL)
	{
		General_Error_Case();
	}

	Game_Loop(Set, Audio, Missile);
	free(Missile);
	free(Audio);
	free(Set);
	return 0;
}
