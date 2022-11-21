#include "Vetor.hpp"


// Construtores

Vetor::Vetor() :
	x(0.0),
	y(0.0)
{};

Vetor::Vetor(float x, float y) :
	x(x),
	y(y)
{};

// Getters

float Vetor::getX() const {
	return x;
};

float Vetor::getY() const {
	return y;
};

// Opera��es 

Vetor Vetor::somaVetor(Vetor vet) {
	float saidaX = x + vet.getX();
	float saidaY = y + vet.getY();
	Vetor saida = Vetor(saidaX, saidaY);

	return saida;
};

Vetor Vetor::subtraiVetor(Vetor vet) {
	float saidaX = x - vet.getX();
	float saidaY = y - vet.getY();
	Vetor saida = Vetor(saidaX, saidaY);

	return saida;
};

Vetor Vetor::multiplica_Escalar_Vetor(Vetor vet) {
	float saidaX = x * vet.getX();
	float saidaY = y * vet.getY();
	Vetor saida = Vetor(saidaX, saidaY);

	return saida;
};

float Vetor::distanciaVetor(Vetor vet) {
	// Calcula a distancia entre cada coordenada em rela��o ao segundo vetor
	Vetor distanciaVet = subtraiVetor(vet);


	// Calcula a hipotenusa em rela��o ao objeto de atra��o

	float distancia = sqrt(distanciaVet.getX() * distanciaVet.getX() + distanciaVet.getY() * distanciaVet.getY());

	return distancia;

};