#pragma once 

class Vetor {
private:
    float x;                        // X do vetor
    float y;                        // Y do vetor

public:

    // Construtor com argumentos
    Vetor(float x, float y);


    // Construtor sem argumentos
    Vetor();

    // Getters
    float getX() const;
    float getY() const;

    // Metodos

    Vetor somaVetor(Vetor vect);
    Vetor subtraiVetor(Vetor vect);
    Vetor multiplica_Escalar_Vetor(Vetor vet);


};