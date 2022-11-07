#include "Janela.h"


//	Builders

//      Builder com configurando o tamanho da janela
Janela::Janela(int width, int height): 
	width(width),
	height(height),
	janela(SDL_CreateWindow("Teste Sdl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)),
	janelaSuperfice(NULL),
	imagem1(NULL)
{
    if (!WindowInit()) {
        close();

        std::cout << "Erro ao iniciar a janela" << std::endl;
        exit(1);
    };

    janelaSuperfice = SDL_GetWindowSurface(janela);

    if (!RenderInit()) {
        
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        exit(1);

    }

};


//      Builder Padrao
Janela::Janela():
    width(1200),
    height(630),
    janela(SDL_CreateWindow("Teste Sdl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)),
    janelaSuperfice(NULL),
    imagem1(NULL)
{
    if (!WindowInit()) {
        close();

        std::cout << "Erro ao iniciar a janela" << std::endl;
        exit(1);
    };

    janelaSuperfice = SDL_GetWindowSurface(janela);

    if (!RenderInit()) {

        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        exit(1);

    }
};




//	Funcoes Membros

//		Getters
int Janela::GetWidth() const {
    return width;
};

int Janela::GetHeight() const{
    return height;
};

//      Get ponteiros

SDL_Window* Janela::GetWindow() {
    return janela;
};

SDL_Surface* Janela::GetSurface() {
    return janelaSuperfice;
};



//		Setters


//		Manipular Janela
void Janela::open(){
    SDL_Event e;
    while (true) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                close();
                exit(0);
            };
        };
        
        /*SDL_Rect fillRect = {width / 4, height / 4, width / 2, height / 2};


        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect( renderer, &fillRect);


        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderPresent(renderer);*/

        // Essa parte do código é um teste para criar um circulo
        // O raio terá o valor padrão de 10
        // int x = 

    };
};

void Janela::close(){
    //Desalocando a superfice
    SDL_FreeSurface(janelaSuperfice);
    imagem1 = NULL;

    //Destruindo a janela
    SDL_DestroyWindow(janela);
    janela = NULL;

    //Destruindo o renderizador

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    //Saindo dos subsistemas sdl
    SDL_Quit();

};

//		configura�oes da janela


//		Desenhar na janela
void Janela::DrawRect(int x, int y, int Dwidth, int Dheight) {
    SDL_Rect fillRect;

    fillRect.w = Dwidth;
    fillRect.h = Dheight;
    fillRect.x = x;
    fillRect.y = y;

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    SDL_RenderDrawRect(renderer, &fillRect);
    SDL_RenderFillRect(renderer, &fillRect);

}


//		Midia
void Janela::loadBTM(char endereco[]) {

    //Load splash image
    imagem1 = SDL_LoadBMP(endereco);
    if (imagem1 == NULL)
    {
        std::cout << "Error ao carregar a imagem :(" << std::endl;
        
        close();
        exit(1);
    };
    
    //Apply the image
    SDL_BlitSurface(imagem1, NULL, janelaSuperfice, NULL);

    //Update the surface
    SDL_UpdateWindowSurface(janela);
    

};

//		Verifica�ao de erro
bool Janela::WindowInit() {
        
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL nao pode inicializar!!" << std::endl << "Error:" << SDL_GetError() << std::endl;

        //Destroy window
        SDL_DestroyWindow(janela);

        //Quit SDL subsystems
        SDL_Quit();

        return false;
    };

    return true;
};

bool Janela::RenderInit() {
    renderer = SDL_CreateRenderer( janela, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        close();

        return false;
    }

    else {

        //Inicializando a cor do renderizador
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        return true;
    }
};

