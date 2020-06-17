#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
SDL_Surface * screen=NULL;
SDL_Surface * inicio=NULL;
SDL_Surface * InicioDeJuego=NULL;
SDL_Surface * Bloque=NULL;

SDL_Event tecla;

void iniciar_SDL(){
SDL_Init( SDL_INIT_EVERYTHING );
}
void CargaDeDatos(){
  inicio = IMG_Load( "inicio.png" );
  InicioDeJuego = IMG_Load("InicioDeJuego.png");
  Bloque=IMG_Load("bloque.png");
}
void crear_pantalla(){
     screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
     }

void unir_pantalla(){
    SDL_FillRect(screen,0,SDL_MapRGB(screen->format, 1000,0,1000));
    SDL_BlitSurface( inicio, NULL, screen, NULL);
        SDL_Flip(screen);

}

void jugar(){
    SDL_Rect Pos_Imag;
    Pos_Imag.x=0;
    Pos_Imag.y=0;
    Pos_Imag.h=600;///alto
    Pos_Imag.w=800;///ancho
        while(true)
        {
        SDL_FillRect(screen,0,SDL_MapRGB(screen->format, 1000,0,1000));
        while(Pos_Imag.y!=-600){

        Pos_Imag.y=Pos_Imag.y-10;
        SDL_BlitSurface(InicioDeJuego,NULL,screen,NULL);
        SDL_BlitSurface(Bloque,&Pos_Imag,screen,NULL);
        SDL_Flip(screen);
        SDL_Delay(200);
        }
        return;
        }
}

void liberar (){
SDL_FreeSurface(inicio);
SDL_Quit();
}

#endif // FUNCIONES_H_INCLUDED
