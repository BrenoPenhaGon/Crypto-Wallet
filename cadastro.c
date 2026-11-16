#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cadastro.h"

// int gerarid(){
//     FILE *arquivo;
//     char linha[100];
//     int contador = 0, id;

//     arquivo = fopen("users.txt", "r");
//     while (fgets(linha, sizeof(linha), arquivo) !=NULL){
//         contador++;
//     }
//     id = contador+1;
//     fclose(arquivo);
//     return id;
// }

void limparBuffer(){
    int a;
    while ((a = getchar()) != '\n' && a != EOF);
}

int conferirDigitos(const char *s){
    int i;
    for (i = 0; i < strlen(s); i++){
        if (isdigit((unsigned char)s[i]) == 0){
        return 0;
        }
    }
    return 1;
}

void cadastrarUsuario(){
    char cpf[13] = "";
    char nome[50];
    char senha[8] = "";
    // int id;

    while (strlen(cpf) != 11 || conferirDigitos(cpf) == 0){
        printf("Informe seu CPF sem pontos e sem tracos: \n");
        fgets(cpf, sizeof(cpf), stdin);
        // Corrige o erro que da se exceder a quantidade de caracteres do char, 
        // basicamente vai conferir se digitaram excedentes, 
        // limpar o buffer e descarta o resto da linha.
        // Depois zera a string cpf pro resto não passar como valido
        if(strchr(cpf, '\n') == NULL){ 
            limparBuffer();
            cpf[0] = '\0';
        } else{
            cpf[strcspn(cpf, "\n")] = '\0';  
        }

        if (strlen(cpf) != 11 || conferirDigitos(cpf) == 0){
            printf("CPF invalida\n");
        }
    }

    printf("Informe seu nome: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    while (strlen(senha) != 6 || conferirDigitos(senha) == 0){
        printf("Informe a senha: \n");
        fgets(senha, sizeof(senha), stdin);
        if(strchr(senha, '\n') == NULL){
            limparBuffer();
            senha[0] = '\0';
        }else{
            senha[strcspn(senha, "\n")] = '\0';
        }
        if(strlen(senha) != 6 || conferirDigitos(senha) == 0){
            printf("Senha invalida\n");
        }
    }

    

    // id = gerarid();

    FILE *arquivo = fopen("users.txt", "a");

    // Conferir se abriu direito
    if (arquivo == NULL){
        printf("Deu ruim fi");
        return;
    }

    // Manda nome e senha pro arquivo
    fprintf(arquivo, "%s;%s;%s\n", cpf, nome, senha);
    fclose(arquivo);

    printf("Cadastro Realizado!\n");
}

int logarUsuario(Usuario *u){
    char cpf[13] = "";
    char senha[8] = "";
    char linha [100];
    char Arqcpf[12], Arqnome[50], Arqsenha[7];
    int tentativas = 0;
    FILE *arquivo;

    while(tentativas < 3){
        printf("Informe seu CPF sem pontos e sem tracos: \n");
        fgets(cpf, sizeof(cpf), stdin);
        if(strchr(cpf, '\n') == NULL){
            limparBuffer();
            cpf[0] = '\0';
        } else{
            cpf[strcspn(cpf, "\n")] = '\0';  
        }

        printf("Informe a senha: \n");
        fgets(senha, sizeof(senha), stdin);
        if(strchr(senha, '\n') == NULL){
            limparBuffer();
            senha[0] = '\0';
        } else{
            senha[strcspn(senha, "\n")] = '\0';
        }

        arquivo = fopen("users.txt", "r");
        // if(arquivo == NULL){
        //     printf("Nenhum usuario cadastrado.\n");
        //     return 0;
        // }

        // SERVE PRA TODOS
        while (fgets(linha, sizeof(linha), arquivo) != NULL){
            linha[strcspn(linha, "\n")] = '\0';

            if (sscanf(linha, "%11[^;];%49[^;];%6[^;]", Arqcpf, Arqnome, Arqsenha) != 3){
                continue;
            }
            
            if(strcmp(Arqcpf, cpf) == 0 && strcmp(Arqsenha, senha) == 0){
                strcpy(u->cpf, Arqcpf);
                strcpy(u->nome, Arqnome);
                strcpy(u->senha, Arqsenha);
                fclose(arquivo);
                return 1;
            }
        }

        fclose(arquivo);
        printf("CPF ou senha incorretos\n");
        tentativas++;
    }
    printf("Numero maximo de tentativas atingido. \n");
    return 0;
}