#include "funcOrdenacoes.h"

//função de ordenação (ordem crescente) -> 'Bubble Sort'
int* ordenarVetor(int* vetor, int tamanho){

    //loop externo para controlar número de vezes que percorre o vetor (diminui número de iterações)
    for(int i = 0; i < tamanho - 1; i++){
        //loop interno para verificar cada par de valores
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
    return vetor;
}