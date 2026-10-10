#include <stdio.h>
#include <stdlib.h>
double bitcoin;
double ethereum;
double ripple;
double saldo;

int comprabitcoin(){
    double valorcompra = 0
    printf("Você possui R$%lf \nQuantos bitcoins deseja comprar? \n", saldo);
    scanf("%lf" &valorcompra);
    if (valorcompra>0 && valorcompra<saldo){
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
    if (valorcompra>0 && valorcompra<saldo){
        ethereum += valorcompra / precoethereum;
    } else {
        printf("Valor inválido!");
        return; 
    }
}

int compraripple(void){
    double valorcompra = 0
    printf("Você possui R$%lf \nQuantos bitcoins deseja comprar? \n", saldo);
    scanf("%lf" &valorcompra);
    if (valorcompra>0 && valorcompra<saldo){
        ripple += valorcompra / precoripple;
    } else {
        printf("Valor inválido!");
        return; 
    }
}