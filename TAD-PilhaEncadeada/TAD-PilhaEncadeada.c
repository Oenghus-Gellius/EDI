#include <stdio.h>
#include <stdlib.h>

#include "TAD-PilhaEncadeada.h"

typedef struct Nodo{
   TElemento info;
   struct Nodo *prox;
}TNodo;

struct TPilha{
   TNodo *topo;
   int tamanho;
};

pilha criaPilha(){
    pilha p = (pilha)malloc(sizeof(struct TPilha));
    if(p){//if(p!=NULL)
        p->topo=NULL;
        p->tamanho=0;
    }
    return p;
}
void terminaPilha(pilha p){
    TNodo *ptr;
    while(p->topo!=NULL){//while(p->topo)
        ptr=p->topo;
        p->topo=p->topo->prox;//p->topo=ptr->prox;//
        free(ptr);
    }
    free(p);
}

int push(pilha p,TElemento e){
    TNodo *ptr = (TNodo*)malloc(sizeof(TNodo));

    if(!ptr)//if(ptr==NULL
       return 0;

    ptr->info=e;
    ptr->prox=p->topo;
    p->topo=ptr;
    p->tamanho++;
    return 1;
}

int pop(pilha p,TElemento*e){
    TNodo *ptr;
    if(pilhaVazia(p)==1)
        return 0;
    ptr=p->topo;
    p->topo=p->topo->prox;
    *e=ptr->info;
    free(ptr);
    p->tamanho--;
    return 1;
}
int pilhaCheia(pilha p){
    TNodo *ptr =(TNodo*)malloc(sizeof(TNodo));
    if(ptr==NULL)//if(!ptr)
        return 1;

    free(ptr);
    return 0;
}
int pilhaVazia(pilha p){
    return p->tamanho==0;//return !p->tamanho
}
int tamanhoPilha(pilha p){
    return p->tamanho;
}
