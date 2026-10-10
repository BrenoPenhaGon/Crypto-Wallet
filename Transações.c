#include <stdio.h>
#include <stdlib.h>
#include "Transações.h"
#include "Valores.h"
double bitcoin;
double ethereum;
double ripple;
double saldo;
float precobitcoin, precoethereum, precoripple;

// COMPRAS

int comprabitcoin(){
    double valorcompra = 0
    printf("Você possui R$%lf \nQuantos BTC deseja comprar? \n", saldo);
    scanf("%lf" &valorcompra);
    if (valorcompra>0 && valorcompra<=saldo){
        bitcoin += valorcompra / precobitcoin;
    } else {
        printf("Valor inválido!");
        return; // Jogar o user de volta ao local onde a função tinha sido chamado inicialmente (nesse caso vai ser o menu)
    }
}

int comprarethereum(void){
    double valorcompra = 0
    printf("Você possui R$%lf \nQuantos ethereum deseja comprar? \n", saldo);
    scanf("%lf" &valorcompra);
    if (valorcompra>0 && valorcompra<=saldo){
        ethereum += valorcompra / precoethereum;
    } else {
        printf("Valor inválido!");
        return; 
    }
}

int compraripple(void){
    double valorcompra = 0
    printf("Você possui R$%lf \nQuantos ripple deseja comprar? \n", saldo);
    scanf("%lf" &valorcompra);
    if (valorcompra>0 && valorcompra<=saldo){
        ripple += valorcompra / precoripple;
    } else {
        printf("Valor inválido!");
        return; 
    }
}

// VENDAS

int vendabitcoin(void){
    double valorvenda = 0
    printf("Você possui %lf bitcoins \nQuantos bitcoins deseja vender? \n", bitcoin);
    scanf("lf" &valorvenda);
    if (valorvenda>0 && valorvenda<=bitcoin){
        saldo += valorvenda * precobitcoin
    }
}