#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"

int main() 
{
	int acao;
	printf("----SEJA BEM VINDO AO MERCADO DE CRIPTOMOEDAS----\n");

	printf("1 - Cadastrar\n" 
		"2 - Login\n" 
		"3 - Sair\n");
	scanf("%d", &acao);

	if(acao == 3){
		system("pause");
	}
	else if(acao == 1){
		// aqui vai a função de cadastro 
		cadastrarUsuario();
	}
	else if(acao == 2){
		// aqui vai a função de login
		
	}
	// é pra ele ser jogado aqui dps da função login ser usada
	printf("Seja bem vindo %s");



	system("pause");

	return 0;
}