#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

int main(){

SDL_Surface *screen = NULL;
int done=1;
personnage perso;
background level;
SDL_Event event;
int i=0;


initialiser_personnage(&perso);
initialiser_background_level(&level);

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(640,360,0,SDL_HWSURFACE);

affichage_background_level(screen,&level);
affichage_personnage(screen,&perso);
SDL_Flip(screen);
	
while (done) { 
	

	SDL_PollEvent(&event);
	switch(event.type) {
			case SDL_QUIT: done=0;
				break;
			case SDL_KEYDOWN: {
				int debutP=perso.position_personnage.x;
				int finP=perso.position_personnage.x+45;

				if(((finP>=debutP)&&(finP<=finP))||(debutP>=debutF)&&(debutP<=finF)) { SDL_Delay(500);
					SDL_Flip(screen);
					SDL_Delay(2000);
					done=0;
				}
				else if(event.key.keysym.sym == SDLK_ESCAPE){
					affichage_background_level(screen,&level);
					affichage_personnage(screen,&perso);
     				SDL_Flip(screen);
					SDL_Delay(5000);} 
				else if(event.key.keysym.sym == SDLK_RIGHT){
					deplacer_personnage_droite (screen, &perso,&level,&i);
				}
				else if(event.key.keysym.sym == SDLK_LEFT){
					deplacer_personnage_gauche (screen,&perso,&level,&i);
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN : {
				if (event.button.button ==  SDL_BUTTON_RIGHT)
					deplacer_personnage_droite (screen,&perso,&level,&i);
				if (event.button.button ==  SDL_BUTTON_LEFT)
					deplacer_personnage_gauche (screen,&perso,&level,&i);
			}
			default: {
				affichage_background_level(screen,&level);
				affichage_personnage(screen,&perso);
				SDL_Flip(screen);
			}
    }
}
SDL_FreeSurface(perso.personnage);
SDL_FreeSurface(level.image_background);
return 0;
}
