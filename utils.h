#ifndef UTILS_H
#define UTILS_H
#include "alimento.h"

void mostrarAlimentos(Alimento vetor[], int tamanho);
void listarCategorias();
void listarAlimentoPorCategoria();
extern int qntAlimentos;
extern Alimento vetorAlimentos[];
Categoria stringParaCategoria(char *texto);

#endif