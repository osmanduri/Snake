#include "moveSnake.h"

void deplacementSnake(SDL_Rect position_snake[100],SDL_Rect position_snake_precedent[100],bool vers_bas, bool vers_droite,bool vers_gauche, bool vers_haut, int taille_snake)
{



                if(vers_gauche)
                {
                    position_snake_precedent[0] = position_snake[0];
                    position_snake[0].x-=20;
                }

                if(vers_droite)
                {
                    position_snake_precedent[0] = position_snake[0];
                    position_snake[0].x+=20;
                }
                if(vers_haut)
                {
                    position_snake_precedent[0] = position_snake[0];
                    position_snake[0].y-=20;
                }
                if(vers_bas)
                {
                    position_snake_precedent[0] = position_snake[0];
                    position_snake[0].y+=20;
                }

                    for(int i = 1; i<taille_snake; i++)
                 {
                    position_snake_precedent[i] = position_snake[i];
                    position_snake[i] = position_snake_precedent[i-1];
                 }




}

void perdu(SDL_Rect position_snake[100], SDL_Rect position_snake_precedent[100], int taille_snake)
{

                if(position_snake[0].x < 0 || position_snake[0].x > 1024 || position_snake[0].y > (800) || position_snake[0].y < 0)
                {
                    SDL_Delay(800);
                    exit(0);
                }

                for(int i=0; i<taille_snake; i++)
                {
                    if((position_snake[0].x == position_snake_precedent[i].x) && (position_snake[0].y == position_snake_precedent[i].y))
                    {
                    SDL_Delay(800);
                    exit(0);
                    }
                }



}

bool snake_mange_pomme(SDL_Rect position_snake[100], SDL_Rect& position_pomme)
{

    if((position_snake[0].x == position_pomme.x) && (position_snake[0].y == position_pomme.y))
    {




                srand(time(NULL));
            do{

                position_pomme.x = (rand() % 1000) + 20;
                position_pomme.y = (rand() % 780) + 20;
            }while(position_pomme.x % 20 != 0 || position_pomme.y %20 != 0);

            return true;
    }

    else
        return false;



}

