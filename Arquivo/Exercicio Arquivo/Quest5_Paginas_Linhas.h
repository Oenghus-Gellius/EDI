#ifndef QUEST5_PAGINASaginas_Linhas.h_H_INCLUDED
#define QUEST5_H_INCLUDED

#define MAX_CARACTERS 1000

//A alocação de de dados sera a pagina salva em uma lista encadeada dinamica
//Já as linhas serão armazenadas em um vetor dinamico
// Definição da estrutura Nodo
// A variavel linha na verdade é um ponteiro para as 50 linhas que serão geradas
typedef struct Nodo{
    char* linha[MAX_CARACTERS];
    TNodo *nextPag;
}TNodo;

//O objetivo dessa estrutura e simular uma folha, onde
typedef struct pagina{
    int nLinhas;
    int nPaginas;
    TNodo *inicio, *fim, *curso;
}Tpage;

#endif // QUEST5_H_INCLUDED