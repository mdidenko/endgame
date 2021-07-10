NAME = endgame

HEADER_H = inc/header.h
HEADER = header.h

SOURCE_C = src/main.c src/Draw_Window.c src/Errors.c src/Game_Loop.c src/Load_Resource.c src/Move.c src/Print_Interface.c
		
SOURCE = main.c Draw_Window.c Errors.c Game_Loop.c Load_Resource.c Move.c Print_Interface.c
	

SDL =  -I ./resource/SDL/SDL2.framework/Versions/A/Headers -F ./resource/SDL -framework SDL2 -rpath ./resource/SDL -I ./resource/SDL/SDL2_image.framework/Versions/A/Headers -F ./resource/SDL -framework SDL2_image -rpath ./resource/SDL

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

SDL_MIXER = -I ./resource/SDL/SDL2_mixer.framework/Versions/A/Headers -F ./resource/SDL -framework SDL2_mixer -rpath ./resource/SDL

SDL_TTF = -I ./resource/SDL/SDL2_ttf.framework/Versions/A/Headers -F ./resource/SDL -framework SDL2_ttf -rpath ./resource/SDL

all: install clean

install:
	@cp $(SOURCE_C) .
	@cp $(HEADER_H) .
	@clang $(CFLAG) $(SDL_MIXER) $(SOURCE) $(SDL) $(SDL_TTF) -o $(NAME) -I $(HEADER) 

uninstall:
	@rm -rf $(NAME)

clean:
	@rm -rf $(SOURCE)
	@rm -rf $(HEADER)

reinstall: uninstall all
