#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct{
    char cpf[12];
    char nome[50];
    char senha[7];
    // Futuramente adicionar reais, btc, eth, xrp 
    double reais;
    double bitcoin;
    double ethereum;
    double ripple;
} Usuario;

// 1 se logar, 0 se der red
int logarUsuario(Usuario *u);
void cadastrarUsuario(void);

void limparBuffer(void);

#endif