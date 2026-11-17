#include <stdio.h>
#include "carteira.h"
#include "saldo.h"

void consultarSaldo(const Usuario *u){
    if (confirmarSenha(u) == 0){
        return;
    }

    printf("\nNome %s\n", u->nome);
    printf("CPF: %.3s.%.3s.%.3s-%.2s\n", u->cpf, u->cpf + 3, u->cpf + 6, u->cpf + 9);

    printf("Reais: %.2f\n", u->reais);
    printf("Bitcoin: %.6f\n", u->bitcoin);
    printf("Ethereum: %.6f\n", u->ethereum);
    printf("Ripple: %.6f\n", u->ripple);
}