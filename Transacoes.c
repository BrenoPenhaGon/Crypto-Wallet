#include <stdio.h>
#include "Transacoes.h"
#include "Valores.h"
#include "carteira.h"
#include "saldo.h"
#include "extrato.h"

void depositar(Usuario *u){
    double valor;
    int lido;

    // só funciona com ponto, se usar virgula da ruim
    printf("Informe o valor do deposito: \n");
    lido = scanf("%lf", &valor);
    limparBuffer();
    if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
        printf("Valor invalido.\n");
        return;
    } 

    u->reais += valor;
    salvarCarteira(u);
    registrarExtrato(u, '+', valor, "REAL", 0.0, 0.0);

    printf("Deposito de %lf realizado!\n", valor);
    mostrarSaldo(u);
}

void sacar(Usuario *u){
    double valor;
    int lido;

    printf("Seu saldo e de; R$ %.2f\n", u->reais);
    printf("Infome o valor do saque: \n");
    lido = scanf("%lf", &valor);
    limparBuffer();
    if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
        printf("Valor invalido.\n");
        return;
    } 

    if (valor > u->reais){
        printf("Saldo insuficiente.\n");
        return;
    }

    u->reais -= valor;
    salvarCarteira(u);
    registrarExtrato(u, '-', valor, "REAL", 0.0, 0.0);

    printf("Saque de %lf realizado!\n", valor);
    mostrarSaldo(u);
}

// COMPRA E VENDA

void comprar(Usuario *u){
    int escolha = 0;
    int lido;
    double valor, taxa, cotacao, total;

    if(confirmarSenha(u) == 0){
        return;
    }

    mostrarCotacoes();
    printf("Seu saldo e de: R$ %.2f\n", u->reais);
    printf("\n1 - BITCOIN (2%% de taxa)\n"
        "2 - ETHERUM (1%% de taxa)\n"
        "3 - RIPPLE (1%% de taxa)\n"
        "0 - Cancelar\n");
    printf("Qual criptomoeda deseja comprar? \n");
    scanf("%d", &escolha);
    limparBuffer();

    if (escolha == 0){
        printf("Compra cancelada.\n");
        return;
    } else if (escolha == 1){ //BTC
        taxa = 0.02;
        cotacao = precobitcoin;

        printf("Quanto deseja comprar, em reais? \n");
        lido = scanf("%lf", &valor);
        limparBuffer();
        if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
            printf("Valor invalido.\n");
            return;
        }

        total = valor + valor*taxa;
        if(total > u->reais){
            printf("Saldo insuficiente. Voce precisa de R$ %.2f.\n", total);
            return;
        }

        u->reais -= total;
        u->bitcoin += valor/cotacao;
        salvarCarteira(u);
        registrarExtrato(u, '-', valor, "BTC", cotacao, taxa);

        printf("Compra finalizada! Voce recebeu %.6f BTC (taxa: R$ %.2f).\n", valor / cotacao, valor * taxa);
        mostrarSaldo(u);
    } else if (escolha == 2){ //ETH
        taxa = 0.01;
        cotacao = precoethereum;

        printf("Quanto deseja comprar, em reais? \n");
        lido = scanf("%lf", &valor);
        limparBuffer();
        if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
            printf("Valor invalido.\n");
            return;
        }

        total = valor + valor*taxa;
        if(total > u->reais){
            printf("Saldo insuficiente. Voce precisa de R$ %.2f.\n", total);
            return;
        }

        u->reais -= total;
        u->ethereum += valor/cotacao;
        salvarCarteira(u);
        registrarExtrato(u, '-', valor, "ETH", cotacao, taxa);

        printf("Compra finalizada! Voce recebeu %.6f ETH (taxa: R$ %.2f).\n", valor / cotacao, valor * taxa);
        mostrarSaldo(u);
    } else if (escolha == 3){ //XRP
        taxa = 0.01;
        cotacao = precoripple;

        printf("Quanto deseja comprar, em reais? \n");
        lido = scanf("%lf", &valor);
        limparBuffer();
        if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
            printf("Valor invalido.\n");
            return;
        }

        total = valor + valor*taxa;
        if(total > u->reais){
            printf("Saldo insuficiente. Voce precisa de R$ %.2f.\n", total);
            return;
        }

        u->reais -= total;
        u->ripple += valor/cotacao;
        salvarCarteira(u);
        registrarExtrato(u, '-', valor, "XRP", cotacao, taxa);

        printf("Compra finalizada! Voce recebeu %.6f XRP (taxa: R$ %.2f).\n", valor / cotacao, valor * taxa);
        mostrarSaldo(u);
    } else{
        printf("Opcao invalida.\n");
    }
}

void vender(Usuario *u){
    int escolha = 0;
    int lido;
    double valor, taxa, cotacao, quantidade;

    if(confirmarSenha(u) == 0){
        return;
    }

    mostrarCotacoes();
    printf("\n1 - BITCOIN (2%% de taxa)\n"
        "2 - ETHERUM (1%% de taxa)\n"
        "3 - RIPPLE (1%% de taxa)\n"
        "0 - Cancelar\n");
    printf("Qual criptomoeda deseja vender? \n");
    scanf("%d", &escolha);
    limparBuffer();

    if (escolha == 0){
        printf("Venda cancelada.\n");
        return;
    } else if(escolha == 1){ //BTC
        taxa = 0.03;
        cotacao = precobitcoin;

        if(u->bitcoin <= 0){
            printf("Voce nao possui bitcoin.\n");
            return;
        }

        printf("Voce possui %.6f BTC (R$ %.2f).\n", u->bitcoin, u->bitcoin * cotacao);
        printf("Quanto deseja vender, em reais? \n");
        lido = scanf("%lf", &valor);
        limparBuffer();
        if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
            printf("Valor invalido.\n");
            return;
        }

        quantidade = valor/cotacao;
        if(quantidade > u->bitcoin){
            printf("Saldo insuficiente de BTC.\n");
            return;
        }

        u->bitcoin -=quantidade;
        u->reais += valor - valor * taxa;
        salvarCarteira(u);
        registrarExtrato(u, '-', valor, "BTC", cotacao, taxa);

        printf("Venda finalizada! Voce vendeu %.6f BTC e recebeu R$ %.2f (taxa: R$ %.2f).\n", quantidade, valor - valor*taxa, valor*taxa);
        mostrarSaldo(u);


    } else if(escolha == 2){ //ETH
        taxa = 0.02;
        cotacao = precoethereum;

        if(u->ethereum <= 0){
            printf("Voce nao possui etherum.\n");
            return;
        }

        printf("Voce possui %.6f ETH (R$ %.2f).\n", u->ethereum, u->ethereum * cotacao);
        printf("Quanto deseja vender, em reais? \n");
        lido = scanf("%lf", &valor);
        limparBuffer();
        if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
            printf("Valor invalido.\n");
            return;
        }

        quantidade = valor/cotacao;
        if(quantidade > u->ethereum){
            printf("Saldo insuficiente de ETH.\n");
            return;
        }

        u->ethereum -=quantidade;
        u->reais += valor - valor * taxa;
        salvarCarteira(u);
        registrarExtrato(u, '-', valor, "ETH", cotacao, taxa);

        printf("Venda finalizada! Voce vendeu %.6f ETH e recebeu R$ %.2f (taxa: R$ %.2f).\n", quantidade, valor - valor*taxa, valor*taxa);
        mostrarSaldo(u);


    } else if(escolha == 3){ //XRP
        taxa = 0.01;
        cotacao = precoripple;

        if(u->ripple <= 0){
            printf("Voce nao possui ripple.\n");
            return;
        }

        printf("Voce possui %.6f XRP (R$ %.2f).\n", u->ripple, u->ripple * cotacao);
        printf("Quanto deseja vender, em reais? \n");
        lido = scanf("%lf", &valor);
        limparBuffer();
        if(lido != 1 || !(valor > 0) || valor > 1000000000){ // 1 bi de limite
            printf("Valor invalido.\n");
            return;
        }

        quantidade = valor/cotacao;
        if(quantidade > u->ripple){
            printf("Saldo insuficiente de XRP.\n");
            return;
        }

        u->ripple -=quantidade;
        u->reais += valor - valor * taxa;
        salvarCarteira(u);
        registrarExtrato(u, '-', valor, "XRP", cotacao, taxa);

        printf("Venda finalizada! Voce vendeu %.6f ETH e recebeu R$ %.2f (taxa: R$ %.2f).\n", quantidade, valor - valor*taxa, valor*taxa);
        mostrarSaldo(u);
    } else{
        printf("Opcao invalida.\n");
    }
}