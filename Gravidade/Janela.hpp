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
	
	//	Builders
	Janela(int width, int height);
	Janela();

	
	//	Funcoes Membros
	
	//		Getters
	int GetWidth() const;	
	int GetHeight() const;


	//		Setters


	//		Manipular Janela
	void open();
	void close();

	//		Configura�oes da janela

	//		Desenhar na janela

	//		Midia
	void loadBTM(char endereco[]);

	//		Ponteiros
	SDL_Window* GetWindow();
	SDL_Surface* GetSurface();


	//		Verifica�ao de erro
	bool WindowInit();
	bool RenderInit();
};