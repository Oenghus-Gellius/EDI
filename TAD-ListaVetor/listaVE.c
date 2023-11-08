#include <stdio.h>
#include <stdlib.h>
#include "listaVE.h"

#define MAX 100

typedef struct Lista{
   TElemento elementos[MAX] ;
   int tamanho,cursor;
}TLista;

lista criaLista(){
    lista l =(lista)malloc(sizeof(TLista));
    if(l!=NULL)
        l->tamanho=0;
    return l;
}
void terminaLista(lista l){
    free(l);
}
int listaCheia(lista l){
    return l->tamanho==MAX;
}
//int insereInicio(lista l, TElemento e);
int insereFinal(lista l, TElemento e){
    if(listaCheia(l)==0){
      l->elementos[l->tamanho]=e;
      l->tamanho++;
      return 1;
    }
    else
        return 0;
}
int getTamanho(lista l){
    return l->tamanho;
}

int insereInicio(lista l, TElemento e){
    int i;
    if(listaCheia(l)==0){
        //movendo os elementos um posição para frente
        for(i=l->tamanho;i>0;i--){
           l->elementos[i]=l->elementos[i-1];
        }

        l->elementos[0]=e;
        l->tamanho++;
        return 1;
    }
    else
        return 0;
}

int getElemento(lista l,TElemento *e, int indice){
    if(indice<1 || indice>l->tamanho)
        return 0;
    else{
        *e=l->elementos[indice-1];
        return 1;
    }
}
int removeElemento(lista l,TChave ch,TElemento *e){
    int i,k;
    for(i=0;i<l->tamanho;i++){
        if(l->elementos[i].chave==ch){
            *e=l->elementos[i];
            for(k=i+1;k<l->tamanho;k++)
                l->elementos[k-1]=l->elementos[k];
            l->tamanho--;
            return 1;
        }
    }
    return 0;
}
int buscaElemento(lista l,TChave ch, TElemento *e){
    int i;
    for(i=0;i<l->tamanho;i++)
    if(l->elementos[i].chave==ch){
        *e=l->elementos[i];
        return 1;
    }
    return 0;
}
int setCursor(lista l,int posicao){
    if(posicao<1 || posicao>l->tamanho)
        return 0;
    l->cursor=posicao-1;
}
int getCorrente(lista l, TElemento *e){
    if(l->cursor<l->tamanho){
        *e=l->elementos[l->cursor];
        l->cursor++;
        return 1;
    }
    else
        return 0;
}
int listaVazia(lista l){
    return l->tamanho==0;
}

int inserePosicao(lista l, TElemento e, int indice){
    int i;
    if(listaCheia(l)==1)
        return 0;

    if(indice<1 || indice>l->tamanho+1)
        return 0;

    if(indice==1)
        return insereInicio(l,e);
    else
        if(indice==l->tamanho+1)
            return insereFinal(l,e);
        else{
           for(i=l->tamanho;i>=indice;i--){
               l->elementos[i]=l->elementos[i-1];
           }
           l->elementos[indice-1]=e;
           l->tamanho++;
           return 1;
        }
}
