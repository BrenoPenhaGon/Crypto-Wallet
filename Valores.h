#ifndef VALORES_H
#define VALORES_H

extern double precobitcoin;
void rerollbitcoin(void);

extern double precoethereum;
void rerollethereum(void);

extern double precoripple;
void rerollripple(void);

void carrecarCotacoes(void);
void salvarCotacoes(void);
void mostrarCotacoes(void);
void atualizarCotacoes(void);

#endif