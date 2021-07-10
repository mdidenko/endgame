#ifndef HEADER_H
#define HEADER_H

//====== LIBS ======
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>

//------ SDL2 -------
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_render.h"	
#include "SDL_ttf.h"

//========== Structs =========
typedef struct
{
	SDL_Surface* ImageSurface;
	SDL_Rect	rect1;
} Image_Struct;

typedef struct 
{
	Mix_Music* beat1; 
	Mix_Music* beat2; 
	Mix_Music* beat3;
	Mix_Music* shot; 
	Mix_Music* hit; 
	Mix_Music* LossHP; 
	Mix_Music* GameOver; 
} Audio_Struct;

typedef struct 
{
	int x_start;
	int y_start; 
	int x_end;
	int y_end;
} Missile_Struct;


typedef struct
{
	SDL_Window* window;
	SDL_Surface* MenuSurface; 	
	
	SDL_Surface* ScreenSurface;
	SDL_Surface* MainSurface;

	SDL_Surface* MissileSurface;
	SDL_Surface* txt;
	SDL_Surface* Game_Over; 
	TTF_Font* font;

	Image_Struct bomb;
	Image_Struct health;
	Image_Struct LossHP;

	Audio_Struct music;

	Missile_Struct missile;
	
	int	width;
	int height;
	int hp;
	int score;
	
	int spawn_bombx;
} Settings_Struct;

//======== Functs ========
void Create_Window(Settings_Struct* Set);

void Load_Resources(Settings_Struct *Set, Audio_Struct* Audio);
void Load_Images(Settings_Struct *Set);
void Load_Audio(Audio_Struct *music);
void Load_Fonts(Settings_Struct *Set);

void Draw_Menu(Settings_Struct * Set);
void Draw_Window(Settings_Struct* Set) ;
void Game_Loop(Settings_Struct* Set, Audio_Struct *music, Missile_Struct* missile);
void Draw_Missile(Settings_Struct* Set, Missile_Struct* missile);
void Motion(Settings_Struct *Set);
void Draw_HP(Settings_Struct *Set);
void Draw_Score(Settings_Struct* Set);


SDL_Rect Set_Coordinate(SDL_Rect rct, Settings_Struct* Set);
bool Check_Hit(Settings_Struct* Set, Missile_Struct* missile);
void General_Error_Case();
void SDL_Error_Case();
int mx_strlen(const char* str);



#endif
