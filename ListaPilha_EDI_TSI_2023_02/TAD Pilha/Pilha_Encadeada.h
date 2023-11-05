#ifndef PILHA_H_ENCADEADA_INCLUDED
#define PILHA_H_ENCADEADA_INCLUDED

typedef char TChave;

typedef struct {
	TChave chave;
	//demais componentes
}TElemento;

typedef struct NodoPilha {
	TElemento info;
	struct NodoPilha* next;
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
