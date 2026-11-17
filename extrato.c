#include <stdio.h>
#include <string.h>
#include <time.h>
#include "extrato.h"
#include "carteira.h"
// Chamar DEPOIS de atualizar os saldos!!!!!!!
// sinal - soma ou subtração
// valor - valor da operacao em reais
// moeda - "REAL", "BTC", "ETH" ou "XRP"
// cotacao - cotacao usada (0.0 em deposito e saque)
// taxa - taxa aplicada em fracao, 0.02 = 2% (0.0 em deposito e saque)
void registrarExtrato(const Usuario *u, char sinal, double valor, const char *moeda, double cotacao, double taxa){
    
    char localizacao[100];
    char data[20];
    time_t agora;
    FILE *arquivo;

    sprintf(localizacao, "dados/extratos/extrato_%s.txt", u->cpf);
    arquivo = fopen(localizacao, "a");
    if (arquivo == NULL){
        printf("Deu ruim");
        return;
    }

    agora = time(NULL);
    strftime(data, sizeof(data), "%d-%m-%Y %H:%M", localtime(&agora));

    fprintf(arquivo, "%s %c %.2f %s CT: %.2f TX: %.2f REAL: %.2f BTC: %.6f ETH: %.6f XRP: %.6f\n", data, sinal, valor, moeda, cotacao, taxa, u->reais, u->bitcoin, u->ethereum, u->ripple);
    fclose(arquivo);
}

void consultarExtrato(const Usuario *u){
    char localizacao[100];
    char linha[200];
    FILE *arquivo;

    if(confirmarSenha(u) == 0){
        return;
    }

    printf("Nome: %s\n", u->nome);
    printf("CPF: %.3s.%.3s.%.3s-%.2s\n", u->cpf, u->cpf + 3, u->cpf + 6, u->cpf + 9);

    sprintf(localizacao, "dados/extratos/extrato_%s.txt", u->cpf);
    if (arquivo == NULL){
        printf("Deu ruim");
        return;
    }

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }

    fclose(arquivo);
}