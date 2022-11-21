#include "Janela.hpp"


// Construtores

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

// Getters

int Janela::GetWidth() const {
    return width;
};

int Janela::GetHeight() const{
    return height;
};

SDL_Window* Janela::GetWindow() {
    return janela;
};

SDL_Surface* Janela::GetSurface() {
    return janelaSuperfice;
};

// Manipuladores da janela

void Janela::open(){
    SDL_Event e;
    
    // Cria o corpo com a força principal
    Circulo buracoNegro = Circulo(30, 30, 5000, Vetor(width / 2, height / 2), Vetor(0, 0));

    // Cria o array com todas as particulas
    const int qtdParticulas = 1000;
    Circulo arrayCirculos[qtdParticulas];
    arrayCirculos[0] = buracoNegro;
    
    // Array auxiliar para saber se as particulas ainda existem
    bool particulaExiste[qtdParticulas];
    for (int z(0); z < qtdParticulas; z++) {
        particulaExiste[z] = true;
    };

    // Insere todas as partículas dentro da array, dando posições aleatórias para cada uma delas
    for (int i = 1; i < qtdParticulas; i++) {
        Circulo particula = Circulo(3, 3, 0, Vetor(rand() % 1200, rand() % 630), Vetor(rand() % 4, 0));
        arrayCirculos[i] = particula;
    }
    
    // Loop principal da tela
    while (true) {
        // Caso o usuário queira fechar a tela 
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                close();
                exit(0);
            };
        };  

        
        // Seta as cores para a renderização
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);              
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        
        for (int a(0); a < qtdParticulas; a++) {
            if (particulaExiste[a]) {

                // Calcula a nova posição da particula caso ela nao seja o buraco negro estatico no centro
                if (a) {
                    arrayCirculos[a].atualiza_fisica(buracoNegro);
                    
                    // Checa se a particula colidio, se sim, fala que ela nao existe mais e pula a renderização dela
                    if (arrayCirculos[a].calcula_colisao(buracoNegro)) {
                        particulaExiste[a] = false;
                        continue;
                    };
                }

                // Coleta os dados para fazer a primeira linha dos objetos
                int inicialX = arrayCirculos[a].GetRaio() * cos(0) + arrayCirculos[a].GetX();
                int inicialY = arrayCirculos[a].GetRaio() * sin(0) + arrayCirculos[a].GetY();

                // Desenhas as linhas dos objetos
                for (int pontoAtual = 0; pontoAtual < arrayCirculos[a].GetArestas() + 1; pontoAtual++) {
                    int x = arrayCirculos[a].GetRaio() * cos((2 * M_PI * pontoAtual) / arrayCirculos[a].GetArestas()) + arrayCirculos[a].GetX();
                    int y = arrayCirculos[a].GetRaio() * sin((2 * M_PI * pontoAtual) / arrayCirculos[a].GetArestas()) + arrayCirculos[a].GetY();

                    SDL_RenderDrawLine(renderer, inicialX, inicialY, x, y);
                    inicialX = x;
                    inicialY = y;
                }
            }
        }
        // Renderiza a tela
        SDL_RenderPresent(renderer);

        int numeroDeParticulas = 0;
        for (int contador(0); contador < qtdParticulas; contador++) {
            if (particulaExiste[contador]) {
                numeroDeParticulas++;
            }
        }

        std::cout << "Numero de particulas: " << numeroDeParticulas << std::endl;

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

bool Janela::WindowInit() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
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
    renderer = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
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

// Auxiliares da janela

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