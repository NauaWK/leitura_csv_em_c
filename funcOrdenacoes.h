#ifndef FUNC_ORDENACOES_H
#define FUNC__ORDENACOES_h
#include "alimento.h"

//definindo um ponteiro para função que será usado na função de ordenação dos alimentos, tornando a função de ordenação genérica para aceitar qualquer campo (umidade, energia etc)
typedef int (*ComparadorAtributos)(Alimento a, Alimento b);

//funções de comparação (ordem crescente) que seguem o modelo definido antes pelo ponteiro de função "ComparadorAtributos"
int compararPorNumero(Alimento a, Alimento b);
int compararPorDescricao(Alimento a, Alimento b);
int compararPorUmidade(Alimento a, Alimento b);
int compararPorEnergia(Alimento a, Alimento b);
int compararPorProteina(Alimento a, Alimento b);
int compararPorCarboidrato(Alimento a, Alimento b);
int compararPorCategoria(Alimento a, Alimento b);

void ordenarAlimentos(Alimento* vetor, int tamanho, ComparadorAtributos comparar);

#endif