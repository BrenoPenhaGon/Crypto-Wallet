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

    sprintf(localizacao, "dados/carteira/carteira_%s.txt", u->cpf);
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