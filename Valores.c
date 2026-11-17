#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "valores.h"

double precobitcoin;
double precoethereum;
double precoripple;

static void DefinirPadrao(void){
    precobitcoin = 370000.00;
    precoethereum = 10000.00;
    precoripple = 5.50;
}

void salvarCotacoes(void){
    FILE *arquivo = fopen("cotacoes.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao salvar as cotações.\n");
        return;
    }

    fprintf(arquivo, "%.6f;%.6f;%.6f\n", precobitcoin, precoethereum, precoripple);
    
    fclose(arquivo);
}

// Usada uma vez
void carrecarCotacoes(void){
    FILE *arquivo;
    int lidos;

    srand((unsigned int)time(NULL));

    arquivo = fopen("cotacoes.txt", "4");

    // primeiro uso
    if (arquivo == NULL){
        DefinirPadrao();
        salvarCotacoes();
        return;
    }
    
    lidos = fscanf(arquivo, "%lf;%lf;%lf", &precobitcoin, &precoethereum, precoripple);
    fclose(arquivo);

    if(lidos !=3 || precobitcoin <= 0 || precoethereum <= 0 || precoripple <= 0){
        DefinirPadrao();
        salvarCotacoes();
    }

}

void mostrarCotacoes(void){
    printf("Cotacoes: \n");
    printf("Bitcoin: R$ %.2f\n", precobitcoin);
    printf("Ethereum: R$ %.2f\n", precoethereum);
    printf("Ripple: R$ %.2f\n", precoripple);
}

void rerollbitcoin(void){
    double variar = ((rand() % 1001) / 1000.0) * 0.10 - 0.05;
    precobitcoin = precobitcoin * (1 + variar);
}

void rerollethereum(void){
    double variar = ((rand() % 1001) / 1000.0) * 0.10 - 0.05;
    precoethereum = precoethereum * (1 + variar);
}

void rerollripple(void){
    double variar = ((rand() % 1001) / 1000.0) * 0.10 - 0.05;
    precoripple = precoripple * (1 + variar);
}

void atualizarCotacoes(void){
    rerollbitcoin();
    rerollethereum();
    rerollripple();
    salvarCotacoes();
}