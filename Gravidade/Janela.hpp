#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <cstring>
#include <iostream>

#include "Circulo.hpp"
#include "Vetor.hpp"


class Janela {
private:
	const int width;
	const int height;

	SDL_Window* janela;
	SDL_Surface* janelaSuperfice;
	SDL_Surface* imagem1;
	SDL_Renderer* renderer;

public:
	
	// Construtores

	Janela(int width, int height);
	Janela();

	// Getters

	int GetWidth() const;	
	int GetHeight() const;
	SDL_Window* GetWindow();
	SDL_Surface* GetSurface();

	// Manipuladores da janela

	void open();
	void close();
	bool WindowInit();
	bool RenderInit();
	
	// Auxiliares da janela
	
	void loadBTM(char endereco[]);
};