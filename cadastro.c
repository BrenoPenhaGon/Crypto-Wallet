#include <stdio.h>
#include <stdlib.h>
#include "Cadastro.h"

int gerarid(){
    FILE *arquivo;
    char linha[100];
    int contador = 0, id;

    arquivo = fopen("users.txt", "r");
    while (fgets(linha, sizeof(linha), arquivo) !=NULL){
        contador++;
    }
    id = contador+1;
    fclose(arquivo);
    return id;
}

void cadastrarUsuario(){
    char nome[50];
    char senha[50];
    int id;


    printf("Informe seu usuário: \n");
    scanf("%49s", nome);
    printf("Informe a senha: \n");
    scanf("%49s", senha);
    id = gerarid();

    FILE *arquivo = fopen("users.txt", "a");

    // Conferir se abriu direito
    if (arquivo == NULL){
        printf("Deu ruim fi");
    }

    // Manda nome e senha pro arquivo
    fprintf(arquivo, "%04d;%s;%s\n", id, nome, senha);
    fclose(arquivo);

    system("pause");
}