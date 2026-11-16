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


void carrecarCotacoes(void){

}

void mostrarCotacoes(void){
    printf("Cotações: \n");
    printf("Bitcoin: R$ %.2f\n", precobitcoin);
    printf("Ethereum: R$ %.2f\n", precoethereum);
    printf("Ripple: R$ %.2f\n", precoripple);
}

void atualizarCotacoes(void){

}