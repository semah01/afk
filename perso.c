#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
 
        void initialiser_personnage(personnage *perso) {
    perso->position_personnage.x=30;
    perso->position_personnage.y=235;
    perso->personnage = IMG_Load("hero.png");
   
    perso->droite[0] = IMG_Load("droite1.png");
    perso->droite[1] = IMG_Load("droite2.png");
    perso->droite[2] = IMG_Load("droite3.png");
    perso->droite[3] = IMG_Load("droite4.png");
    perso->gauche[0] = IMG_Load("gauche1.png");
    perso->gauche[1] = IMG_Load("gauche2.png");
    perso->gauche[2] = IMG_Load("gauche3.png");
    perso->gauche[3] = IMG_Load("gauche4.png");
}
 
        void affichage_personnage(SDL_Surface *screen,personnage *perso){
    SDL_BlitSurface(perso->personnage,NULL,screen,&perso->position_personnage);
}
 
        void initialiser_background_level(background *level) {
    level->positionbackground.x=0;
    level->positionbackground.y=0;
    level->image_background = IMG_Load("map.jpeg");
}
 
        void affichage_background_level(SDL_Surface *screen,background *level){
    SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
}
 
        void deplacer_personnage_droite (SDL_Surface *screen,personnage *perso,background *level,int *i){
    perso->position_personnage.x+=7;
    SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
    SDL_BlitSurface(perso->droite[*(i)],NULL,screen,&perso->position_personnage);
    SDL_Flip(screen);
    SDL_Delay(60);
    (*i)++;
    if ((*i)>=4) { (*i)=0; }
}
 
 
        void deplacer_personnage_gauche (SDL_Surface *screen,personnage *perso,background *level, int *i){
    perso->position_personnage.x-=7;
    SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
    SDL_BlitSurface(perso->gauche[*(i)],NULL,screen,&perso->position_personnage);
    SDL_Flip(screen);
    SDL_Delay(60);
    (*i)++;
    if ((*i)>=4) {  (*i)=0; }
}
