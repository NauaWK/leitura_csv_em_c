#ifndef ALIMENTO_H
#define ALIMENTO_H

//enum para as categorias dos alimentos selecionados
typedef enum {
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
} Categoria;

//definição da estrutura de um Alimento
typedef struct {
    int numero;
    char descricao[50];
    float umidade;
    int energia;
    float proteina;
    float carboidrato;
    Categoria categoria;
} Alimento;

#endif