#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include "departSnake.h"
#include "moveSnake.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <SDL/SDL.h>
void init_snake(SDL_Surface* snake[100]);
void init_position_snake(SDL_Rect position_snake[]);
void couleur_snake(SDL_Surface* snake[100], SDL_Surface* screen);
void blit_snake(SDL_Surface* snake[100], SDL_Rect position_snake[100], SDL_Surface* screen);


int main ( int argc, char** argv )
{

    SDL_Surface* screen = SDL_SetVideoMode(1024, 800, 32,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);

    SDL_Surface* snake[1000];
    int taille_snake = 5;
    SDL_Surface* pomme = SDL_LoadBMP("pomme.bmp");
    SDL_Event event;
    init_snake(snake, taille_snake); //initialise le snake de depart
    int tempActuel,tempPrecedent=0;


    bool vers_droite = false;
    bool vers_gauche = true;
    bool vers_bas = false;
    bool vers_haut = false;

    SDL_Rect position_snake[100] = {0}; // on determine les positions du snake
    SDL_Rect position_snake_precedent[100] = {0};
    SDL_Rect position_pomme{0};


    srand(time(NULL));
            do{

                position_pomme.x = (rand() % 1000) + 20;
                position_pomme.y = (rand() % 780) + 20;
            }while(position_pomme.x % 20 != 0 || position_pomme.y %20 != 0);


    SDL_Init(SDL_INIT_VIDEO);




        SDL_FillRect(snake[0], 0, SDL_MapRGB(screen->format, 255, 0, 0)); // couleur rouge pour la tete du snake

        couleur_snake(snake, screen, taille_snake);
        init_position_snake(position_snake, taille_snake);
        blit_snake(snake, position_snake, screen, taille_snake);

    bool continuer = true;
    while (continuer)
    {


        while (SDL_PollEvent(&event))
        {

            switch(event.type)
         {
                case SDL_QUIT:
                continuer = 0;
                break;
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:

                         if(!vers_bas)
                         {
                            vers_droite = false;
                            vers_gauche = false;
                            vers_haut = true;
                            vers_bas = false;
                         }
                            break;

                    case SDLK_DOWN:

                         if(!vers_haut)
                         {
                            vers_droite = false;
                            vers_gauche = false;
                            vers_haut = false;
                            vers_bas = true;
                         }


                        break;

                    case SDLK_LEFT:

                         if(!vers_droite)
                         {
                            vers_droite = false;
                            vers_gauche = true;
                            vers_haut = false;
                            vers_bas = false;
                         }




                        break;

                    case SDLK_RIGHT:

                         if(!vers_gauche)
                         {
                            vers_droite = true;
                            vers_gauche = false;
                            vers_haut = false;
                            vers_bas = false;
                         }




                        break;

                    case SDLK_p:
                        do{
                            SDL_Delay(6000);
                        }while(!SDLK_p);

                    case SDLK_ESCAPE:
                        exit(0);
                        break;

                }

         }
        }


        srand(time(NULL));
        tempActuel = SDL_GetTicks();
       if(tempActuel - tempPrecedent > 1)
        {
            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 150, 100, 150));
            couleur_snake(snake, screen, taille_snake);

            deplacementSnake(position_snake,position_snake_precedent,vers_bas,vers_droite,vers_gauche,vers_haut, taille_snake);
            perdu(position_snake, position_snake_precedent, taille_snake);

            if(snake_mange_pomme(position_snake, position_pomme))
            {
                taille_snake++;
                init_snake2(snake, taille_snake);
            }


             SDL_BlitSurface(pomme, 0, screen, &position_pomme);


            for(int i=0;i<taille_snake;i++)
            {
             SDL_BlitSurface(snake[i], 0, screen, &position_snake[i]);
            }
             SDL_Delay(50);


            tempPrecedent = tempActuel;
        }
        else
        {
           //SDL_Delay(60 - (tempActuel - tempPrecedent));
        }















        SDL_Flip(screen);
    }


    SDL_FreeSurface(*snake);



    return 0;
}
