#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*1) Escrever uma fun��o para verificar se um dado item est� presente em uma pilha. Em
caso positivo, o algoritmo deve fornecer tamb�m a posi��o do item na pilha,
considerando o topo como posi��o 1. A pilha deve permanecer a mesma ap�s a
execu��o da fun��o.*/

typedef char TChave;

typedef struct {
	TChave chave;
	//demais componentes
}TElemento;

typedef struct NodoPilha {
	TElemento info;
	struct NodoPilha *next;
}TNodoPilha;

typedef struct Pilha {
	TNodoPilha* topo;
	int tamanho;
}TPilha;

TPilha* criaPilha();

void terminaPilha(TPilha* pilha);
int push(TPilha* pilha, TElemento info);
int pop(TPilha* pilha, TElemento* info);
int pilhaCheia(TPilha* pilha);
int pilhaVazia(TPilha* pilha);
int tamanhoPilha(pilha);
#endif // PILHA_H_INCLUDED