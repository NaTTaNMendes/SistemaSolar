#pragma once 

#include <math.h>


class Vetor {
private:
    float x;  // X do vetor
    float y;  // Y do vetor

public:

    // Construtores

    Vetor(float x, float y);
    Vetor();

    // Getters

    float getX() const;
    float getY() const;

    // Opera��es

    Vetor somaVetor(Vetor vect);
    Vetor subtraiVetor(Vetor vect);
    Vetor multiplica_Escalar_Vetor(Vetor vet);
    float distanciaVetor(Vetor vet);
};