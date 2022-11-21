#include "Circulo.hpp"

#include <iostream>

// Construtores

Circulo::Circulo() :
	raio(0),
	arestas(0),
	forca(0),
	posicao(Vetor()),
	velocidade(Vetor())
{};

Circulo::Circulo(Vetor posicao) :
	raio(0),
	arestas(0),
	forca(0),
	posicao(posicao),
	velocidade(Vetor())
{};

Circulo::Circulo(int raio, int arestas, float forca, Vetor posicao, Vetor velocidade) :
	raio(raio),
	arestas(arestas),
	forca(forca),
	posicao(posicao),
	velocidade(velocidade)
{};

// Getters 

int Circulo::GetRaio() {
	return raio;
};

int Circulo::GetArestas() {
	return arestas;
};

float Circulo::GetForca() {
	return forca;
};

Vetor Circulo::GetPosicao() {
	return posicao;
};

Vetor Circulo::GetVelocida() {
	return velocidade;
};

float Circulo::GetX() {
	return posicao.getX();
};

float Circulo::GetY() {
	return posicao.getY();
}

// Setter 

void Circulo::setPosicao(Vetor Nposicao) {
	posicao = Nposicao;
};

void Circulo::setVelocidade(Vetor Nvelocidade) {
	velocidade = Nvelocidade;
};

void Circulo::setForca(float Nforca) {
	forca = Nforca;
};

// Fisica

void Circulo::atualiza_fisica(Circulo bola)
{
	// Calculando a distancia entre os dois vetores de posição
	float distancia = bola.GetPosicao().distanciaVetor(GetPosicao());

	// Realiza pitágoras através da raiz quadrada inversa devido a velocidade
	float distancia_inversa = 1.f / distancia;
	float xNormalizado = distancia_inversa * (bola.GetX() - GetX());
	float yNormalizado = distancia_inversa * (bola.GetY() - GetY());
	float raiz_quadrada_inversa = distancia_inversa * distancia_inversa;

	// Calcula a aceleração da partícula
	Vetor aceleracao = Vetor(xNormalizado * bola.GetForca() * raiz_quadrada_inversa, yNormalizado * bola.GetForca() * raiz_quadrada_inversa);
	
	// Adiciona a aceleração na atual velocidade
	velocidade = velocidade.somaVetor(aceleracao);

	// Troca a posição em relação a nova velocidade
	posicao = posicao.somaVetor(velocidade);
};

bool Circulo::calcula_colisao(Circulo bola) {

	// se a soma dos raios for maior ou igual que a distancia entre os dois objetos significa que eles estao se encostando
	if (GetRaio() + bola.GetRaio() >= GetPosicao().distanciaVetor(bola.GetPosicao())) {
		return true;
	};

	return false;
};