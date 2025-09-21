#ifndef UTILS_H
#define UTILS_H
#include "alimento.h"

void mostrarAlimentos(Alimento vetor[], int tamanho, int ordem);
void mostrarAlimento(Alimento a);
void listarCategorias();
Alimento* gerarVetorPorCategoria(Categoria c, int* tamanho);
void listarAlimentosOrdemAlfabetica(Categoria c);
void listarAlimentosPorEnergia(Categoria c);
extern int qntAlimentos;
extern Alimento vetorAlimentos[];
Categoria stringParaCategoria(char *texto);

#endif