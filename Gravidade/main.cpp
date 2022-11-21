#include <SDL2/SDL.h>
#include <iostream>
#include "Janela.hpp"

#undef main

int main() {

    Janela JanelaMain = Janela();

    // Coleta os dados da janela
    int largura = JanelaMain.GetWidth();
    int altura = JanelaMain.GetHeight();   
    
    // Inicia a janela
    JanelaMain.open();

    // Coleta os ponteir
    SDL_Window* janelaPonteiro = JanelaMain.GetWindow();
    SDL_Surface* bufferPonteiro = JanelaMain.GetSurface();

    return 0;
}

