#include <string.h>
#include "funcOrdenacoes.h"
#include "alimento.h"

/* exemplo de função de ordenação (ordem crescente) por Bubble Sort:
void ordenarVetor(int* vetor, int tamanho){
    //loop externo para controlar número de vezes que percorre o vetor (diminui número de iterações do loop interno a cada passo)
    for(int i = 0; i < tamanho - 1; i++){
        //loop interno para verificar cada par de valores adjacentes
        for(int j = 0; j < tamanho - i - 1; j++){
            //verifica se valor esquerdo > direito
            if(vetor[j] > vetor[j + 1]){
                //inversão de valores             
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}*/

//Bubble Sort adaptado para ordenar um vetor de alimentos em ordem alfabética pela descrição
void ordenarAlimentosPorDescricao(Alimento* vetor, int tamanho){
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            //strcmp para comparar descrições e descobrir se está em ordem alfabética
            if (strcmp(vetor[j].descricao, vetor[j + 1].descricao) > 0) {
                Alimento temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void ordenarAlimentosPorEnergia(Alimento* vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j].energia > vetor[j + 1].energia) {
                // troca os elementos
                Alimento temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
