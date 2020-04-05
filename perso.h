#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
	SDL_Surface *personnage;
	SDL_Surface *droite[4];
	SDL_Surface *gauche[4];
	SDL_Rect position_personnage;
	}personnage;

typedef struct {
	SDL_Surface *image;
	SDL_Rect position_image;
	}image;

typedef struct {
	SDL_Surface *image_background;
	SDL_Rect positionbackground;
	}background;

void initialiser_personnage(personnage *perso);
void affichage_personnage(SDL_Surface *screen,personnage *perso);
void initialiser_background_level(background *level);
void affichage_background_level(SDL_Surface *screen,background *level);
void deplacer_personnage_droite (SDL_Surface *screen,personnage *perso, background *level, int *i);
void deplacer_personnage_gauche (SDL_Surface *screen,personnage *perso, background *level, int *i);


#endif
