#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
SDL_Surface * screen=NULL;
SDL_Surface * inicio=NULL;
SDL_Surface * InicioDeJuego=NULL;
SDL_Surface * Bloque=NULL;
void figura();

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
        while(true)
        {
        SDL_BlitSurface(InicioDeJuego,NULL,screen,NULL);
        figura();
        return;
        }
        }

void figura(){
    SDL_Rect Pos_Imag;
    Pos_Imag.x=0;
    Pos_Imag.y=0;
    Pos_Imag.h=600;///alto
    Pos_Imag.w=800;///ancho
            while(Pos_Imag.y!=-600){
        SDL_BlitSurface(InicioDeJuego,NULL,screen,NULL);
        SDL_BlitSurface(Bloque,&Pos_Imag,screen,NULL);
        Pos_Imag.y=Pos_Imag.y-1;
            while (SDL_PollEvent(&tecla))
    {
        if (tecla.type == SDL_QUIT)
            {
                return;
            }
        if(tecla.key.keysym.sym==SDLK_RIGHT)
        {
        Pos_Imag.x=Pos_Imag.x-18;
        }
        if (tecla.key.keysym.sym==SDLK_LEFT)
        {
        Pos_Imag.x=Pos_Imag.x+18;
        }
            }
        SDL_Flip(Bloque);
        SDL_Flip(screen);
        SDL_Delay(200);
}
}

void liberar (){
SDL_FreeSurface(inicio);
SDL_Quit();
}

#endif // FUNCIONES_H_INCLUDED
