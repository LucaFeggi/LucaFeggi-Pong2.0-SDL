#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <cmath>
#include <ctime>
#include <sstream>

#include "headers/globals.hpp"
#include "headers/vec2.hpp"
#include "headers/paddle.hpp"
#include "headers/ball.hpp"
#include "headers/sound.hpp"
#include "headers/game.hpp"

/*
 	First who gets 11 points, wins.
 	Commands
 	- left player: lshift(up), lctrl(down)
	- right player: arrow up(up), arrow down(down)
	- pause: spacebar
*/

int main(int argc, char* argv[]){

	srand(time(NULL));
	
	InitializeSDL();

	SDL_Event event;
	game pong;
	bool quit = false;
	bool is_paused = false;

	while (!quit){
		
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				quit = true;
			if(event.key.state == SDL_PRESSED){
				if(event.key.keysym.sym == SDLK_SPACE)
					is_paused = !is_paused;
			}
		}
		
		pong.cycle(is_paused);
		
	}
	
	CloseSDL();
	
	return 0;

}
