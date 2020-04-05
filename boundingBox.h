#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


struct Objet
{
SDL_Surface *image ; 
SDL_Rect position ; 
}; 
typedef struct Objet Objet;

void initialiserObjet( Objet *objet , char nom[] , int x , int y ) ;
void affichageObjet ( Objet objet , SDL_Surface *screen) ;
int collisionboundingBox( SDL_Rect posj , SDL_Rect posoj) ;


#endif /* FONCTIONS_H_ */
