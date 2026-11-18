#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "carteira.h"

void carregarCarteira(Usuario *u){
    char localizacao[100];
    FILE *arquivo;
    int lidos;

    u->reais = 0;
    u->bitcoin = 0;
    u->ethereum = 0;
    u->ripple = 0;

    sprintf(localizacao, "dados/carteiras/carteira_%s.txt", u->cpf);
    arquivo = fopen(localizacao, "r");
    if (arquivo == NULL){
        return;
    }

    lidos = fscanf(arquivo, "%lf;%lf;%lf;%lf", &u->reais, &u->bitcoin, &u->ethereum, &u->ripple);
    if (lidos != 4){
        u->reais = 0;
        u->bitcoin = 0;
        u->ethereum = 0;
        u-> ripple = 0;
    }
}

void salvarCarteira(const Usuario *u){
    char localizacao[100];
    FILE *arquivo;

    sprintf(localizacao, "dados/carteiras/carteira_%s.txt", u->cpf);
    arquivo = fopen(localizacao, "w");
    if (arquivo == NULL){
        printf("Deu erro\n");
        perror(localizacao);
        return;
    }

    fprintf(arquivo, "%.6f;%.6f;%.6f;%.6f\n", u->reais, u->bitcoin, u->ethereum, u->ripple);
    fclose(arquivo);
}

int confirmarSenha(const Usuario *u){
    char senha[8] = "";

    printf("Informe sua senha: \n");
    fgets(senha, sizeof(senha), stdin);

    if (strchr(senha, '\n') == NULL){
        limparBuffer();
        senha[0] = '\0';
    } else {
        senha[strcspn(senha, "\n")] = '\0';
    }

    if (strcmp(senha, u->senha) != 0){
        printf("Senha incorreta.\n");
        return 0;
    }
    return 1;
}