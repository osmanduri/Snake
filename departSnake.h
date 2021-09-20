#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
void init_snake(SDL_Surface* snake[], int taille_snake);
void init_snake2(SDL_Surface* snake[], int taille_snake);
void init_position_snake(SDL_Rect position_snake[], int taille_snake);
void couleur_snake(SDL_Surface* snake[], SDL_Surface* screen, int taille_snake);
void blit_snake(SDL_Surface* snake[], SDL_Rect position_snake[], SDL_Surface* screen, int taille_snake);
