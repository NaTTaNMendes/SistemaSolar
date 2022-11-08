#include "Janela.hpp"


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
    Circulo buracoNegro = Circulo(15, 30, 4000, Vetor(width / 2, height / 2), Vetor(0, 0));
    
    Circulo particula = Circulo(10, 30, 0, Vetor(width / 4, height / 4), Vetor(4, 0));
    Circulo particula2 = Circulo(10, 30, 0, Vetor((width / 4) + width / 2, height / 4), Vetor(-4, 0));


    Circulo arrayCirculos[3];
    arrayCirculos[0] = buracoNegro;
    arrayCirculos[1] = particula;
    arrayCirculos[2] = particula2;

    while (true) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                close();
                exit(0);
            };
        };
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        

        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        for (int a(0); a < 3; a++) {


            // configuraçao da primeira reta do circulo
            int inicialX = arrayCirculos[a].GetRaio() * cos(0) + arrayCirculos[a].GetX();
            int inicialY = arrayCirculos[a].GetRaio() * sin(0) + arrayCirculos[a].GetY();

            for (int pontoAtual = 0; pontoAtual < arrayCirculos[a].GetArestas() + 1; pontoAtual++) {
                int x = arrayCirculos[a].GetRaio() * cos((2 * M_PI * pontoAtual) / arrayCirculos[a].GetArestas()) + arrayCirculos[a].GetX();
                int y = arrayCirculos[a].GetRaio() * sin((2 * M_PI * pontoAtual) / arrayCirculos[a].GetArestas()) + arrayCirculos[a].GetY();

                SDL_RenderDrawLine(renderer, inicialX, inicialY, x, y);
                inicialX = x;
                inicialY = y;       
            }

        }
        SDL_RenderPresent(renderer);

        arrayCirculos[1].atualiza_fisica(buracoNegro);
        arrayCirculos[2].atualiza_fisica(buracoNegro);

        std::cout << "[ " << arrayCirculos[2].GetX() << ", " << arrayCirculos[2].GetY() << "]" << std::endl;
        


        // Faz a taxa de atualização em 60 fps
        SDL_Delay(1000 / 60);

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

//		configuraçoes da janela




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

//		Verificaçao de erro
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

