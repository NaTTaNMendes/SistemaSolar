#include "Vetor.hpp"
#include <math.h>

#pragma once


class Circulo {
private:
    int raio;                       // Raio do círculo
    int arestas;                    // Quantidade de arestas que compoem a forma
    float forca;                    // Força gravitacional que o circulo exerce sobre os outros            
    Vetor posicao;                  // Posicao do ponto central
    Vetor velocidade;               // Velocidade do circulo

public:
    
    // Builders
    Circulo();
    Circulo(Vetor posicao);
    Circulo(int raio, int arestas, float forca, Vetor posicao, Vetor velocidade);

    // Getter 
    int GetRaio();
    int GetArestas();
    float GetForca();
    Vetor GetPosicao();
    Vetor GetVelocida();

    float GetX();
    float GetY();

    // Setter
    void setPosicao(Vetor Nposicao);
    void setVelocidade(Vetor Nvelocidade);
    void setForca(float Nforca);

    // Atualiza Fisica
    void atualiza_fisica(Circulo bola);


};