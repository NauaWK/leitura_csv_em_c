#include <stdio.h>
#include <string.h>  // strcmp, strcpy, strtok
#include <stdlib.h>  // atoi, atof
#include "utils.h"

//variável de controle para inserir os alimentos no vetor e evitar ultrapassar a quantidade de linhas
int qntAlimentos = 0;

//vetor de alimentos que salvará os dados do csv na memória
Alimento vetorAlimentos[100];

int main(){
   
    //apontando para o arquivo de dados csv dos alimentos
    FILE *arquivo = fopen("dados_alimentos.csv", "r");

    //caso arquivo esteja inexistente/corrompido
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    //variável de controle para ser modificada a cada passo do loop e salva no vetor
    Alimento alimento;

    //buffer para armazenar cada linha do csv
    char linha[255];

    //acessando a primeira linha do csv para ignorá-la, pois contém apenas o nome dos campos
    fgets(linha, sizeof(linha), arquivo);

    //loop principal de leitura (partir da 2º linha)
    while(fgets(linha, sizeof(linha), arquivo)){

        //funcao strktok para dividir cada linha em substrings (tokens), usando virgula como delimitador e armazenando o endereço do primeiro caráctere de cada campo separado em "token"
        char *token = strtok(linha, ",");

        //convertendo número do alimento para inteiro com atoi
        alimento.numero = atoi(token);

        //a partir da segunda leitura sempre nesse formato com NULL
        token = strtok(NULL, ",");

        //função strcpy para copiar string do token para o campo correspondente no struct Alimento
        strcpy(alimento.descricao, token);

        token = strtok(NULL, ",");
        alimento.umidade = atof(token);

        token = strtok(NULL, ",");
        alimento.energia = atoi(token);

        token = strtok(NULL, ",");
        alimento.proteina = atof(token);

        token = strtok(NULL, ",");
        alimento.carboidrato = atof(token);

        token = strtok(NULL, ",");

        //trocando o caractere de quebra de linha "\n" do último campo para um caractere nulo "\0"
        token[strcspn(token, "\n")] = '\0';
        alimento.categoria = stringParaCategoria(token);

        if(qntAlimentos < 100){
            vetorAlimentos[qntAlimentos] = alimento;
            qntAlimentos++;
        }
    }

    //testes
    listarAlimentosPorEnergia(CARNES);

    return 0;
}