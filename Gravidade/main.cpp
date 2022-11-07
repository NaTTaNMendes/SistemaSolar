#include <SDL2/SDL.h>
#include <iostream>


const int width = 1200;
const int height = 630;

SDL_Window* janela = NULL;
SDL_Surface* janelaSuperfice = NULL;
SDL_Surface* imagem1 = NULL;
SDL_Renderer* renderer;

class Vetor {
    public:
        float x;                        // X do vetor
        float y;                        // Y do vetor
    
    Vetor(float x, float y):            // Construtor com argumentos
        x(x),
        y(y){};

    Vetor():                            // Construtor sem argumentos
        x(0.0)
        y(0.0){};

    Vetor somaVetor(Vetor vect) {
        Vetor saida = Vetor();
        saida.x = x + vect.x;
        saida.y = y + vect.y;
        return saida;
    }

}

class Circulo{
    public:
        int raio;                       // Raio do círculo
        int arestas;                    // Quantidade de arestas que compoem a forma
        int posiX;                      // Posição X do círculo
        int posiY;                      // Posição Y do círculo
        float forca;                    // Força gravitacional que o circulo exerce sobre os outros            
        Vetor velocidade;               // Velocidade do circulo


    Circulo(int x, int y, int r, int ar, float f, Vetor vel){      // Construtor com argumentos
        posiX = x;
        posiY = y;
        raio = r;
        arestas = ar;
        forca = f;
        
    };

    Circulo():                          // Construtor sem argumentos
        raio(0),
        arestas(0),
        posiX(0),
        posiY(0){};

};

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

    // Verificações padrão-------------------------------------------------------------------------------------------
    if (!WindowInit()) {
        close();

        std::cout << "Erro ao iniciar a janela" << std::endl;
        exit(1);
    };
    //---------------------------------------------------------------------------------------------------------------

    
    // Cria o renderer-----------------------------------------------------------------------------------------------
    renderer = SDL_CreateRenderer( janela, -1, SDL_RENDERER_ACCELERATED);
    // Verifica se o renderer foi de fato criado
    if (renderer == NULL) {
        std::cout << "fez merda no renderer" << std::endl;
        exit(1);
    }

    else {

        //Inicializando a cor do renderizador
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    //---------------------------------------------------------------------------------------------------------------
    
    // Caso exista uma imagem, ela é carregada no projeto------------------------------------------------------------
    if (!loadMedia()) {
        close();

        std::cout << "Erro ao iniciar a Imagem" << std::endl;
        exit(1);
    };

    // Insere a imagem
    SDL_BlitSurface(imagem1, NULL, janelaSuperfice, NULL);

    // Atualiza a superficie
    SDL_UpdateWindowSurface(janela);
    //---------------------------------------------------------------------------------------------------------------
    
    // Definindo variaveis para a criacao do circulo
    int posicaoX = width / 15;
    int posicaoY = height / 10;

    // Criando o array de Circulos
    Circulo arrayCirculos[10];
    
    // definindo os circulos no array
    for (int i(0); i < 10; i++){
        arrayCirculos[i] = Circulo(posicaoX, posicaoY);

        //atualiza a posicao x para ficar a direita do circulo anterior
        posicaoX += 30;
    };

    SDL_Event e;
    bool quit = false;
    
    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            };
        
        };

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        for (int a(0); a < 10; a++){ 
            
            arrayCirculos[a].aumentaX(10);
            std::cout << "[" <<arrayCirculos[a].posiX << "]  ";

            // configuraçao da primeira reta do circulo
            int inicialX = arrayCirculos[a].raio * cos(0) + arrayCirculos[a].posiX;
            int inicialY = arrayCirculos[a].raio * sin(0) + arrayCirculos[a].posiY;
                        
            for (int pontoAtual = 0; pontoAtual < arrayCirculos[a].arestas + 1; pontoAtual++) {
                int x = arrayCirculos[a].raio * cos((2 * M_PI * pontoAtual) / arrayCirculos[a].arestas) + arrayCirculos[a].posiX;
                int y = arrayCirculos[a].raio * sin((2 * M_PI * pontoAtual) / arrayCirculos[a].arestas) + arrayCirculos[a].posiY;

                SDL_RenderDrawLine(renderer, inicialX, inicialY, x, y);
                inicialX= x;
                inicialY = y;
            }

        }

        SDL_RenderPresent(renderer);

        // Faz a taxa de atualização em 60 fps
        SDL_Delay(1000/60);

    };


    close();

    return 0;
};