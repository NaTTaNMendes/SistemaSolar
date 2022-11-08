.PHONY: all clean

CXX = g++
RM = rm -f

main: main.o Vetor.o Janela.o Circulo.o
	$(CXX) main.o Vetor.o Janela.o Circulo.o -o main -lSDL2

main.o: main.cpp
	$(CXX) -o main.o -c main.cpp -lSDL2 

Vetor.o: Vetor.cpp Vetor.hpp
	$(CXX) -o Vetor.o -c Vetor.cpp -lSDL2

Janela.o: Janela.cpp Janela.hpp
	$(CXX) -o Janela.o -c Janela.cpp -lSDL2

Circulo.o: Circulo.cpp Circulo.hpp
	$(CXX) -o Circulo.o -c Circulo.cpp -lSDL2