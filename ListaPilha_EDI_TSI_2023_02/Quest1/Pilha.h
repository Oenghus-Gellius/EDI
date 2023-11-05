#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*1) Escrever uma função para verificar se um dado item está presente em uma pilha. Em
caso positivo, o algoritmo deve fornecer também a posição do item na pilha,
considerando o topo como posição 1. A pilha deve permanecer a mesma após a
execução da função.*/

#define MAX_CHAR 30
#define MAX_WORDS 20

typedef char TString;

typedef char TChave [MAX_CHAR];


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
int tamanhoPilha(TPilha* pilha);

//Pesquisar na pilha a existencia de um item. Passando a Pilha(é claro), o iten. 
//Retornando a posução se achouou -1 se não achou
int finderPositionElemento(TPilha* pilha, TChave chave); // TElemento info

#endif // PILHA_H_INCLUDED