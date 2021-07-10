#include "header.h"

void General_Error_Case()
{	
	char* Error = (char*)strerror(errno);
	write(2, "[Error] Endgame: ", mx_strlen("[Error] Endgame: "));
	write(2, Error, mx_strlen(Error));
	write(2, "\n", 1);
	exit(0);
}

void SDL_Error_Case()
{
	write(2, "[SDL Error] Endgame: ", mx_strlen("[SDL Error] Endgame: "));
	write(2, SDL_GetError() , mx_strlen(SDL_GetError()));
	write(2, "\n", 1);
	exit(0);
}

int mx_strlen(const char* str)
{
	int length = 0;
	while(str[length] != '\0')
	{
		length++;
	}
	return length;
}
