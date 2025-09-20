#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "funcOrdenacoes.h"
#define TOTAL_CATEGORIAS 15
#define TOTAL_ALIMENTOS 100

//array com as categorias do enum em formato de string para associação dos dados que vem do csv (em texto) para seu enum correspondente
const char* categoriasString[TOTAL_CATEGORIAS] = {
    "Cereais",
    "Leguminosas",
    "Tuberculos",
    "Frutas",
    "Vegetais",
    "Carnes",
    "Laticinios",
    "Ovos",
    "Gorduras",
    "Bebidas",
    "Industrializados",
    "Doces",
    "Oleaginosas",
    "Pescados",
    "Suplementos"
};

const Categoria todasAsCategoriasEnum[] = {
    CEREAIS,
    LEGUMINOSAS,
    TUBERCULOS,
    FRUTAS,
    VEGETAIS,
    CARNES,
    LATICINIOS,
    OVOS,
    GORDURAS,
    BEBIDAS,
    INDUSTRIALIZADOS,
    DOCES,
    OLEAGINOSAS,
    PESCADOS,
    SUPLEMENTOS,
};

//função para converter string Categoria → enum Categoria
Categoria stringParaCategoria(char *categoria){
    for(int i = 0; i < TOTAL_CATEGORIAS; i++){
        if(strcmp(categoria, categoriasString[i]) == 0){
            //cast de i para enum Categoria 
            return (Categoria) i;
        }
    }     
    return -1;
}

//função para exibir todos os alimentos do vetor
void mostrarAlimentos(Alimento vetorAlimentos[], int tamanho){
    if(qntAlimentos != TOTAL_ALIMENTOS) return;
    for(int i = 0; i < qntAlimentos; i++ ){
        Alimento a = vetorAlimentos[i];
        printf("Numero: %d\n Descricao: %s\n Umidade: %.2f\n Energia(kcal): %d\n Proteina(g): %.2f\n Carboidratos(g): %.2f\n Categoria: %s\n ============= \n", 
            a.numero, a.descricao, a.umidade, a.energia, a.proteina, a.carboidrato, categoriasString[a.categoria]);
    }
}

//função para mostrar alimentos de acordo com um índice, ou seja, de acordo com condições específicas
void mostrarAlimentoPorIndice(Alimento vetor[], int indice){
    Alimento a = vetor[indice];
    printf("Numero: %d\n Descricao: %s\n Umidade: %.2f\n Energia(kcal): %d\n Proteina(g): %.2f\n Carboidratos(g): %.2f\n Categoria: %s\n ============= \n", 
    a.numero, a.descricao, a.umidade, a.energia, a.proteina, a.carboidrato, categoriasString[a.categoria]); 
}

//função utilitária para verificar uma categoria
int verificarCategoria(Categoria c){
    int categoriaValida = 0;
    for(int i = 0; i < TOTAL_CATEGORIAS; i++){
        if(todasAsCategoriasEnum[i] == c){
            categoriaValida = 1;
            return categoriaValida;
        }
    }
    printf("Erro: categoria inválida.");
    return categoriaValida;
}

void listarCategorias(){
    printf("Categorias:\n");
    for(int i = 0; i < TOTAL_CATEGORIAS; i++){
        printf("%d - %s\n", i + 1, categoriasString[i]);
    }
}

void listarAlimentoOrdemCrescentePorDescricao(Categoria c){
    if(verificarCategoria(c) == 0 || qntAlimentos <= 0) return;

    //contador para a quantidade de alimentos da categoria fornecida
    int tamanho = 0;

    //vetor para armazenar alimentos da categoria X fornecida e um vetor de INT para o 1º caractere do campo "descricao" de cada alimento usando integer promotion (char → int por conta da tabela ASCII)
    Alimento* alimentosCategoriaX = NULL;
    int* vetorPrimeiroCharDescricao = NULL;

    for(int i = 0; i < qntAlimentos; i++){
        if(vetorAlimentos[i].categoria == c){
            tamanho++; 

            //usando realloc para redimensionar o tamanho dos vetores definidos antes conforme o loop
            alimentosCategoriaX = (Alimento*) realloc(alimentosCategoriaX, tamanho * (sizeof(Alimento)));
            vetorPrimeiroCharDescricao = (int*) realloc(vetorPrimeiroCharDescricao, tamanho * sizeof(int));

            //inserindo os dados nos vetores
            alimentosCategoriaX[tamanho - 1] = vetorAlimentos[i];
            vetorPrimeiroCharDescricao[tamanho - 1] = vetorAlimentos[i].descricao[0];
        }
    }

    //passando o vetor dos caracteres (em forma de int) para uma função de ordenação
    int* vetorCharOrdenado = ordenarVetor(vetorPrimeiroCharDescricao, tamanho);

    //comparando cada char do vetor de char (ordenado) com a primeira letra do campo descricao de cada alimento selecionado de acordo com sua categoria, exibindo os alimentos em ordem alfabética
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(vetorCharOrdenado[i] == alimentosCategoriaX[j].descricao[0]){
                mostrarAlimentoPorIndice(alimentosCategoriaX, j);
            }
        }
    }
}