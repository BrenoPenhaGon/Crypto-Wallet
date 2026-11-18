#ifndef CARTEIRA_H
#define CARTEIRA_H

#include "cadastro.h"

void carregarCarteira(Usuario *u);
void salvarCarteira(const Usuario *u);
int confirmarSenha(const Usuario *u);


#endif