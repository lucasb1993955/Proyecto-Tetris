
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "funciones.h"
int main(int argc,char *argv[])
{

    int i=0;
    iniciar_SDL();
    crear_pantalla();
    CargaDeDatos();
    while (true)
    {
        i++;
     unir_pantalla();
    while (SDL_PollEvent(&tecla))
    {
        if (tecla.type == SDL_QUIT)
            {
                return 0;
            }
        if (tecla.type == SDL_KEYDOWN)
        {
        if(tecla.key.keysym.sym==SDLK_SPACE)
        {
        jugar();
        }
        if (tecla.key.keysym.sym==SDLK_ESCAPE)
        {
            return 0;
        }
        }

    }

    SDL_Delay(200);
    if ( i > 100 )
        {
            liberar();
            SDL_Quit();
    }

    }
}
