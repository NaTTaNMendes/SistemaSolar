#include <SDL2/SDL.h>
#include <iostream>


const int width = 1200;
const int height = 630;

SDL_Window* janela = NULL;
SDL_Surface* janelaSuperfice = NULL;
SDL_Surface* imagem1 = NULL;
SDL_Renderer* renderer;


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
    imagem1 = SDL_LoadBMP("cu.bmp");
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

    renderer = SDL_CreateRenderer( janela, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {

        std::cout << "fez merda no renderer" << std::endl;
        exit(1);
    }

    else {

        //Inicializando a cor do renderizador
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }

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
        
        
        //SDL_RenderPresent(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, width / 2, height / 2);
        int raio = 200;
        
        int l = 30.0;

        int posiX = width / 4;
        int posiY = height / 4;

        int inicialX = raio * cos(0) + posiX;
        int inicialY = raio * sin(0) + posiY;


        for (int i = 0; i < l + 1; i++) {
            int x = raio * cos((2 * M_PI * i) / l) + posiX;
            int y = raio * sin((2 * M_PI * i) / l) + posiY;

            SDL_RenderDrawLine(renderer, inicialX, inicialY, x, y);
            inicialX= x;
            inicialY = y;
        }

        SDL_RenderPresent(renderer);


        };
    };


    close();

    return 0;
};