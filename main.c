#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "boundingBox.h"

int main()
{
SDL_Surface *screen ; 
Objet Objet, Objet1 ; 
SDL_Event event ; 
int test=0 , x ; 

 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  255,  150 , 255)); 

//initialiser et afficher image
    initialiserObjet( &Objet ,"a.png" ,  0 ,  0 ) ; 
    affichageObjet (Objet ,screen) ;
    initialiserObjet( &Objet1 ,"b.png" ,  500 ,  200 ) ; 
    affichageObjet (Objet1 ,screen) ;
   SDL_EnableKeyRepeat(10,10) ; 
    while  ( test==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 test  =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
test=1 ; 

case SDLK_LEFT : 

Objet.position.x-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObjet (Objet ,screen) ;
affichageObjet (Objet1 ,screen) ;

break ; 

case SDLK_RIGHT : 

Objet.position.x+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObjet (Objet ,screen) ;
affichageObjet (Objet1 ,screen) ;
break ; 
case SDLK_UP : 

Objet.position.y-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObjet (Objet ,screen) ;
affichageObjet (Objet1 ,screen) ;
break ; 
case SDLK_DOWN : 

Objet.position.y+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObjet (Objet ,screen) ;
affichageObjet (Objet1 ,screen) ;
break ; 


                 
			 }
x=collisionboundingBox(Objet.position,Objet1.position) ;

if(x==1) 
{
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
SDL_Flip(screen) ; 
}
break ; 

		 }
	 }


}
return 0 ; 
}
