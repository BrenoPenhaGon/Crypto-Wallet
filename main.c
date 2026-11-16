#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "valores.h"

int main() 
{
	setlocale(LC_ALL, "Portuguese");
	int acao;
	Usuario logado;

	while(1){
		printf("----SEJA BEM VINDO AO MERCADO DE CRIPTOMOEDAS----\n");

		printf("1 - Cadastrar\n" 
			"2 - Login\n" 
			"3 - Sair\n");
		scanf("%d", &acao);
		limparBuffer();

		if(acao == 3){
			system("pause");
			return 0;
		}
		else if(acao == 1){
			// aqui vai a função de cadastro 
			cadastrarUsuario();
		}
		else if(acao == 2){
			// aqui vai a função de login
			if(logarUsuario(&logado)){
				printf("Seja bem vindo %s\n", logado.nome);
				//MENU COMPLETO
			}
		} else{
			printf("Opcao invalida, tente novamente!");
		}
	}

	system("pause");

	return 0;
}