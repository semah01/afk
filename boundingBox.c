#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "boundingBox.h"


void initialiserObjet( Objet *objet , char nom[] , int x , int y ) 
{

	       objet->image =  IMG_Load(nom); 
	      if  ( objet->image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     objet->position.x  =  x ; 
     objet->position.y  =  y ; 
     objet->position.h  =  objet->image->h ;
objet->position.w = objet->image->w ;
}

}


void affichageObjet ( Objet objet , SDL_Surface *screen) 
{

SDL_BlitSurface(objet.image, NULL, screen, &(objet.position));
SDL_Flip(screen);

}


int collisionboundingBox( SDL_Rect posj , SDL_Rect posoj )
{
 int x ; 
if ( ((posj.y+posj.h>=posoj.y)&&(posj.y<=posoj.y+posoj.h)&&(posj.x+posj.w>=posoj.x)&&(posj.x<=posoj.x+posoj.w)) )
{
	x=1 ; 
}

else x=0 ; 
return x ;
}
