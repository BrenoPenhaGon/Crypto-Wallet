#ifndef EXTRATO_H
#define EXTRATO_H
 
#include "cadastro.h"
 
void consultarExtrato(const Usuario *u);
void registrarExtrato(const Usuario *u, char sinal, double valor, const char *moeda, double cotacao, double taxa);
 
#endif