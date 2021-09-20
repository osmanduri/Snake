#include "departSnake.h"

void init_snake(SDL_Surface* snake[100], int taille_snake)
{
    int i=0;

        for(i=0; i<taille_snake; i++)
    {
        snake[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 20, 32, 0, 0, 0, 0);
    }
}

void init_snake2(SDL_Surface* snake[100], int taille_snake)
{

    snake[--taille_snake] = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 20, 32, 0, 0, 0, 0);
}

void couleur_snake(SDL_Surface* snake[100], SDL_Surface* screen, int taille_snake)
{
    int color_snake_rgb_vert;
    int color_snake_rgb_bleu;

       SDL_FillRect(snake[0], 0, SDL_MapRGB(screen->format, 255, 0, 0));
   for(int i=1; i<taille_snake; i++)
   {
            if(i % 2 == 0)
            {
                  color_snake_rgb_vert = 125;
                  color_snake_rgb_bleu = 0;

            }
            else{
                  color_snake_rgb_vert = 0;
                  color_snake_rgb_bleu = 125;
            }
            SDL_FillRect(snake[i], 0, SDL_MapRGB(screen->format, 0, color_snake_rgb_vert, color_snake_rgb_bleu));



    }
}

void init_position_snake(SDL_Rect position_snake[100], int taille_snake)
{
      int localisation_snake_x = 500;
      int localisation_snake_y = 500;

   for(int i=0; i<taille_snake; i++)
   {
      position_snake[i].x = localisation_snake_x;
      position_snake[i].y = localisation_snake_y;
      localisation_snake_x+= 20;

   }


}


void blit_snake(SDL_Surface* snake[100], SDL_Rect position_snake[100], SDL_Surface* screen, int taille_snake)
{

     for(int i=0; i<5; i++)
     {

         SDL_BlitSurface(snake[i], 0, screen, &position_snake[i]);
     }

}
