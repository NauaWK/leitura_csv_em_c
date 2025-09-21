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
    "Verduras",
    "Frutas",
    "Gorduras",
    "Pescados",
    "Carnes",
    "Leite",
    "Bebidas",
    "Ovos",
    "Acucarados",
    "Miscelaneas",
    "Industrializados",
    "Preparados",
    "Leguminosas",
    "Nozes"
};

const Categoria todasAsCategoriasEnum[] = {
    CEREAIS,
    VERDURAS,
    FRUTAS,
    GORDURAS,
    PESCADOS,
    CARNES,
    LEITE,
    BEBIDAS,
    OVOS,
    ACUCARADOS,
    MISCELANEAS,
    INDUSTRIALIZADOS,
    PREPARADOS,
    LEGUMINOSAS,
    NOZES
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

//função para exibir alimentos de um vetor, com um parâmetro "ordem" para decidir se imprime em ordem crescente/decrescente
void mostrarAlimentos(Alimento vetor[], int tamanho, int ordem){
    if(qntAlimentos < tamanho || ordem > 1 || ordem < 0) return;

    //ordem crescente se "ordem" == 1
    if(ordem == 1){
        for(int i = 0; i < tamanho; i++){
            Alimento a = vetor[i];
            printf("Numero: %d\n Descricao: %s\n Umidade: %.2f\n Energia(kcal): %d\n Proteina(g): %.2f\n Carboidratos(g): %.2f\n Categoria: %s\n ============= \n", 
                a.numero, a.descricao, a.umidade, a.energia, a.proteina, a.carboidrato, categoriasString[a.categoria]);
        }
    }
    else{
        //ordem decrescente se "ordem" == 0
        for(int i = tamanho - 1; i >= 0; i--){
            Alimento a = vetor[i];
            printf("Numero: %d\n Descricao: %s\n Umidade: %.2f\n Energia(kcal): %d\n Proteina(g): %.2f\n Carboidratos(g): %.2f\n Categoria: %s\n ============= \n", 
                a.numero, a.descricao, a.umidade, a.energia, a.proteina, a.carboidrato, categoriasString[a.categoria]);
        }
    }

}

void mostrarAlimento(Alimento a){
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

//função que gera vetores de alimentos com base em uma categoria X, recebe também o endereço de uma variável externa "tamanho" para outros fins
Alimento* gerarVetorPorCategoria(Categoria c, int* tamanho){
    if (!verificarCategoria(c) || qntAlimentos <= 0) return NULL;

    //vetor de alimentos dinâmico para ser populado com alimentos da categoria X fornecida pelo usuário
    Alimento* alimentosFiltrados = NULL;
    *tamanho = 0;

    //filtra alimentos da categoria fornecida e insere no vetor, realocando memória com realloc
    for (int i = 0; i < qntAlimentos; i++) {
        if (vetorAlimentos[i].categoria == c) {
            (*tamanho)++;
            alimentosFiltrados = realloc(alimentosFiltrados, *tamanho * sizeof(Alimento));
            alimentosFiltrados[*tamanho - 1] = vetorAlimentos[i];
        }
    }  
    return alimentosFiltrados;
}

//função para armazenar os alimentos de uma categoria X fornecida e exibir esses alimentos em ordem alfabética pelo campo "descrição"
void listarAlimentosOrdemAlfabetica (Categoria categoriaSelecionada) {  
    if (!verificarCategoria(categoriaSelecionada) || qntAlimentos <= 0) return;

    int totalAlimentosCategoriaX;
    Alimento* alimentosFiltrados = gerarVetorPorCategoria(categoriaSelecionada, &totalAlimentosCategoriaX);

    ordenarAlimentos(alimentosFiltrados, totalAlimentosCategoriaX, compararPorDescricao);

    mostrarAlimentos(alimentosFiltrados, totalAlimentosCategoriaX, 1);

    //liberação de memória do vetor alocado
    free(alimentosFiltrados);
}

void listarAlimentosPorEnergia(Categoria categoriaSelecionada){
    if (!verificarCategoria(categoriaSelecionada) || qntAlimentos <= 0) return;

    int totalAlimentosCategoriaX;
    Alimento* alimentosFiltrados = gerarVetorPorCategoria(categoriaSelecionada, &totalAlimentosCategoriaX);

    ordenarAlimentos(alimentosFiltrados, totalAlimentosCategoriaX, compararPorEnergia);

    mostrarAlimentos(alimentosFiltrados, totalAlimentosCategoriaX, 0);

    free(alimentosFiltrados);
}


