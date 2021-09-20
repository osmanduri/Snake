#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
void deplacementSnake(SDL_Rect position_snake[100],SDL_Rect position_snake_precedent[100],bool vers_bas, bool vers_droite,bool vers_gauche, bool vers_haut, int taille_snake);
void perdu(SDL_Rect position_snake[100], SDL_Rect position_snake_precedent[100], int taille_snake);
bool snake_mange_pomme(SDL_Rect position_snake[100], SDL_Rect& position_pomme);
