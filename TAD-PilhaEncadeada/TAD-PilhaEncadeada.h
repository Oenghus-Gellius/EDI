#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
typedef char TChave;
typedef struct{
   TChave chave;
   //demais componentes
}TElemento;

typedef struct TPilha *pilha;

pilha criaPilha();
void terminaPilha(pilha);
int push(pilha,TElemento);
int pop(pilha,TElemento*);
int pilhaCheia(pilha);
int pilhaVazia(pilha);
int tamanhoPilha(pilha);
#endif // PILHA_H_INCLUDED