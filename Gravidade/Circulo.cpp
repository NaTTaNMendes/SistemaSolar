#include "Circulo.hpp"


// Builders ----------------------------------------------------------------------------------------------
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
// -------------------------------------------------------------------------------------------------------


// Getters -----------------------------------------------------------------------------------------------
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

// -------------------------------------------------------------------------------------------------------


// Setter ------------------------------------------------------------------------------------------------
void Circulo::setPosicao(Vetor Nposicao) {
	posicao = Nposicao;
};

void Circulo::setVelocidade(Vetor Nvelocidade) {
	velocidade = Nvelocidade;
};

void Circulo::setForca(float Nforca) {
	forca = Nforca;
};

// -------------------------------------------------------------------------------------------------------


// Atualiza Fisica ---------------------------------------------------------------------------------------

void Circulo::atualiza_fisica(Circulo bola)
{
	float distanciaX = bola.GetX() - GetX();
	float distanciaY = bola.GetY() - GetY();

	float distancia = sqrt(distanciaX * distanciaX + distanciaY * distanciaY);

	float distancia_inversa = 1.f / distancia;

	float xNormalizado = distancia_inversa * distanciaX;
	float yNormalizado = distancia_inversa * distanciaY;

	float raiz_quadrada_inversa = distancia_inversa * distancia_inversa;

	Vetor aceleracao = Vetor(xNormalizado * bola.GetForca() * raiz_quadrada_inversa, yNormalizado * bola.GetForca() * raiz_quadrada_inversa);

	velocidade = velocidade.somaVetor(aceleracao);

	posicao = posicao.somaVetor(velocidade);
};