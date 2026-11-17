#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "valores.h"
#include "saldo.h"
#include "extrato.h"
#include "carteira.h"

void menuUsuario(Usuario *u){
	int opcao = 0;

	while (opcao != 8){
		printf("\n--------------MENU--------------\n");
		printf("1 - Consultar Saldo\n"
			"2 - Consultar Extrato\n"
			"3 - Depositar\n"
			"4 - Sacar\n"
			"5 - Comprar Criptomoedas\n"
			"6 - Vender Criptomoedas\n"
			"7 - Atualizar Cotacaoo\n"
			"8 - Voltar\n");
		scanf("%d", &opcao);
		limparBuffer();

		if (opcao == 1){
			consultarSaldo(u);
		} else if(opcao == 2){
			consultarExtrato(u);
		} else if(opcao == 3){
			
		} else if(opcao == 4){
			
		} else if(opcao == 5){
			
		} else if(opcao == 6){
			
		} else if(opcao == 7){
			atualizarCotacoes();
			mostrarCotacoes();

		} else if(opcao == 8){
			printf("\nAte logo, %s!\n", u->nome);
		} else{
			printf("\nOpcao invalida, tente novamente\n");
		}
	}
}

int main(){
	int acao;
	Usuario logado;
	carrecarCotacoes();

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
				carregarCarteira(&logado);
				printf("\n----Seja bem vindo %s----", logado.nome);
				menuUsuario(&logado);
				//MENU COMPLETO
			}
		} else{
			printf("Opcao invalida, tente novamente!");
		}
	}
}