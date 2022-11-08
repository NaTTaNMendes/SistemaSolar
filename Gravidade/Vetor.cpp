#include "Vetor.hpp"


// Builders ----------------------------------------------------------------------------------------------
Vetor::Vetor() :
	x(0.0),
	y(0.0)
{};

Vetor::Vetor(float x, float y) :
	x(x),
	y(y)
{};
// -------------------------------------------------------------------------------------------------------


// Getters------------------------------------------------------------------------------------------------
float Vetor::getX() const {
	return x;
};

float Vetor::getY() const {
	return y;
};
// -------------------------------------------------------------------------------------------------------


// Metodos------------------------------------------------------------------------------------------------
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
