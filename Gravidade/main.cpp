#include <SDL2/SDL.h>
#include <iostream>



#include "Janela.h"

#undef main


int main() {

    Janela JanelaMain = Janela();

    //char endereco[] = "Src/Dotted.bmp";
    //JanelaMain.loadBTM(endereco);
    

    int largura = JanelaMain.GetWidth();
    int altura = JanelaMain.GetHeight();

    JanelaMain.DrawRect(largura / 4, altura / 4, largura / 2, altura / 2);
    
    
    JanelaMain.open();



    SDL_Window* janelaPonteiro = JanelaMain.GetWindow();

    SDL_Surface* bufferPonteiro = JanelaMain.GetSurface();

  
    

    return 0;
}


/*
#include <SDL2\SDL.h>
#include <iostream>

#undef main

const int width = 1200;
const int height = 630;

SDL_Window* janela = NULL;
SDL_Surface* janelaSuperfice = NULL;
SDL_Surface* imagem1 = NULL;


bool WindowInit() {


    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL nao pode inicializar!!" << std::endl << "Error:" << SDL_GetError() << std::endl;

        //Destroy window
        SDL_DestroyWindow(janela);

        //Quit SDL subsystems
        SDL_Quit();

        return false;

    };


    janela = SDL_CreateWindow("Teste Sdl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (janela == NULL) {
        std::cout << "Janela nao conseguiu abrir :(" << std::endl << "Error:" << SDL_GetError() << std::endl;

        //Destroy window
        SDL_DestroyWindow(janela);

        //Quit SDL subsystems
        SDL_Quit();

        return false;
    };

    janelaSuperfice = SDL_GetWindowSurface(janela);


    return true;
};

void close()
{
    //Deallocate surface
    SDL_FreeSurface(janelaSuperfice);
    imagem1 = NULL;

    //Destroy window
    SDL_DestroyWindow(janela);
    janela = NULL;

    //Quit SDL subsystems
    SDL_Quit();
};

bool loadMedia()
{
    // success flag
    bool success = true;

    //Load splash image
    imagem1 = SDL_LoadBMP("Src/Google-earth.bmp");
    if (imagem1 == NULL)
    {
        std::cout << "Error ao carregar a imagem :(" << std::endl;

        success = false;
    };

    return success;
};


int main() {

    if (!WindowInit()) {
        close();

        std::cout << "Erro ao iniciar a janela" << std::endl;
        exit(1);
    };

    if (!loadMedia()) {
        close();

        std::cout << "Erro ao iniciar a Imagem" << std::endl;
        exit(1);
    };

    //Apply the image
    SDL_BlitSurface(imagem1, NULL, janelaSuperfice, NULL);

    //Update the surface
    SDL_UpdateWindowSurface(janela);

    SDL_Event e;
    bool quit = false;
    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            };
        };
    };


    close();

    return 0;
};
*/