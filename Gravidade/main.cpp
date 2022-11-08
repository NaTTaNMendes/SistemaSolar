#include <SDL2/SDL.h>
#include <iostream>


#include "Janela.hpp"

#undef main


int main() {

    Janela JanelaMain = Janela();

    //char endereco[] = "Src/Dotted.bmp";
    //JanelaMain.loadBTM(endereco);
    

    int largura = JanelaMain.GetWidth();
    int altura = JanelaMain.GetHeight();

    
    
    JanelaMain.open();



    SDL_Window* janelaPonteiro = JanelaMain.GetWindow();

    SDL_Surface* bufferPonteiro = JanelaMain.GetSurface();

  

    return 0;
}

