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
void mostrarAlimentos(Alimento vetor[], int tamanho){
    if(qntAlimentos < tamanho) return;
    for(int i = 0; i < tamanho; i++){
        Alimento a = vetor[i];
        printf("Numero: %d\n Descricao: %s\n Umidade: %.2f\n Energia(kcal): %d\n Proteina(g): %.2f\n Carboidratos(g): %.2f\n Categoria: %s\n ============= \n", 
            a.numero, a.descricao, a.umidade, a.energia, a.proteina, a.carboidrato, categoriasString[a.categoria]);
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

//função para armazenar os alimentos de uma categoria X fornecida e exibir esses alimentos em ordem alfabética pelo campo "descrição"
void listarAlimentosOrdemAlfabetica (Categoria categoriaSelecionada) {  
    if (!verificarCategoria(categoriaSelecionada) || qntAlimentos <= 0) return;

    //vetor dinâmico
    Alimento* alimentosFiltrados = NULL;
    int totalAlimentosCategoriaX = 0;

    //filtra alimentos da categoria fornecida
    for (int i = 0; i < qntAlimentos; i++) {
        if (vetorAlimentos[i].categoria == categoriaSelecionada) {
            totalAlimentosCategoriaX++;
            alimentosFiltrados = realloc(alimentosFiltrados, totalAlimentosCategoriaX * sizeof(Alimento));
            alimentosFiltrados[totalAlimentosCategoriaX - 1] = vetorAlimentos[i];
        }
    }
    
    ordenarAlimentosPorDescricao(alimentosFiltrados, totalAlimentosCategoriaX);

    //exibe alimentos
    for (int i = 0; i < totalAlimentosCategoriaX; i++) {
        mostrarAlimento(alimentosFiltrados[i]);
    }
    //liberação de memória do vetor alocado
    free(alimentosFiltrados);
}

