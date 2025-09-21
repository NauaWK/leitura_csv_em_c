#include <string.h>
#include "funcOrdenacoes.h"
#include "alimento.h"

/* exemplo de função de ordenação (ordem crescente) por Bubble Sort:
void ordenarVetor(int* vetor, int tamanho){
    //loop externo para controlar número de vezes que percorre o vetor (diminui número de iterações do loop interno a cada passo)
    for(int i = 0; i < tamanho - 1; i++){
        //loop interno para verificar cada par de valores adjacentes
        for(int j = 0; j < tamanho - i - 1; j++){
            //essa condição verifica se valor esquerdo > direito
            if(vetor[j] > vetor[j + 1]){
                //inversão de valores             
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}*/

int compararPorNumero(Alimento a, Alimento b) {
    return a.numero > b.numero;
}
int compararPorDescricao(Alimento a, Alimento b) {
    return strcmp(a.descricao, b.descricao) > 0;
}
int compararPorUmidade(Alimento a, Alimento b) {
    return a.umidade > b.umidade;
}
int compararPorEnergia(Alimento a, Alimento b) {
    return a.energia > b.energia;
}
int compararPorProteina(Alimento a, Alimento b) {
    return a.proteina > b.proteina;
}
int compararPorCarboidrato(Alimento a, Alimento b) {
    return a.carboidrato > b.carboidrato;
}
int compararPorCategoria(Alimento a, Alimento b) {
    return a.categoria > b.categoria;
}

//Bubble Sort genérico adaptado para ordenar um vetor de alimentos com base em algum campo decidido pelo usuário
void ordenarAlimentos(Alimento* vetor, int tamanho, ComparadorAtributos comparar) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (comparar(vetor[j], vetor[j + 1])){
                Alimento temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
