#include <stdio.h>
#include <stdlib.h>

#include "listaSE.h"

typedef struct Nodo{
    TElemento info;
    struct Nodo *prox;
}TNodo;

typedef struct TLista{
    TNodo *inicio,*fim,*corrente;
    int tamanho;
};

lista criaLista(){
    lista l = (lista)malloc(sizeof(struct TLista));
    if(l!=NULL){
        l->inicio=NULL;
        l->fim=NULL;
        l->tamanho=0;
    }
    return l;
}

void terminaLista(lista l){
    TNodo *p;
    while(l->inicio!=NULL){
        p=l->inicio;
        l->inicio = l->inicio->prox;//l->inicio = p->prox;
        free(p);
    }
    free(l);
}

int pesquisaLista(lista l,TChave ch,TElemento *e){
    TNodo *p;
    p=l->inicio;
    while(p!=NULL){
        if(p->info.chave==ch){
            *e=p->info;
            return 1;
        }
    }
    return 0;
}

int insereFinal(lista l,TElemento e){
    TNodo *p= (TNodo*)malloc(sizeof(TNodo));
    if(p==NULL)
       return 0;
    p->info=e;
    p->prox = NULL;
    //verificando se a lista está vazia
    if(l->inicio==NULL)
      l->inicio = p;
    else
      l->fim->prox = p;
    l->fim=p;
    l->tamanho++;
    return 1;
}

int getElemento(lista l, int posicao, TElemento *e){
    TNodo *p;
    int i;
    if(posicao<1 || posicao>l->tamanho)
       return 0;
    p=l->inicio;
    for(i=1;i<posicao;i++)
       p=p->prox;
    *e = p->info;
    return 1;
}

int removeElemento(lista l,TChave ch,TElemento *e){
    TNodo *p,*ant;
    p=l->inicio;
    while(p!=NULL){
        if(p->info.chave==ch){
           //verificando se é o primeiro nodo
           if(p==l->inicio)
              l->inicio=l->inicio->prox;//l->inicio=p->prox;
           else
              if(p==l->fim){
                 l->fim=ant;
                 l->fim->prox=NULL;
              }
              else
                 ant->prox=p->prox;
           *e=p->info;
           free(p);
           l->tamanho--;
           return 1;
        }
        else{
            ant=p;
            p=p->prox;
        }

    }
    return 0;
}

int listaVazia(lista l){
    /*if(l->inicio==NULL)
        return 1;
    else
        return 0;*/
    return !l->inicio;    //return !l->inicio==NULL;
    //return !l->tamanho;
}
int listaCheia(lista l){
    TNodo *p = (TNodo*)malloc(sizeof(TNodo));
    if(p!=NULL){//if(p)
       free(p);
       return 0;
    }
    else
       return 1;
}
int tamanhoLista(lista l){
    return l->tamanho;
}


int insereInicio(lista l, TElemento e){
    TNodo *p = (TNodo*)malloc(sizeof(TNodo));
    if(p==NULL)
        return 0;
    else{
        p->info=e;
        p->prox=l->inicio;
        l->inicio=p;
        l->tamanho++;
        if(l->tamanho==1)
            l->fim=p;
        return 1;
    }
}

int inserePosicao(lista l, TElemento e, int indice){
    TNodo *p,*aux;
    int i;
    //verificando se é uma posição válida
    if(indice<1 || indice >l->tamanho+1)
        return 0;
    else{
        if(indice==1)
            return insereInicio(l,e);
        else
            if(indice == l->tamanho+1)
                return insereFinal(l,e);
            else{
               p=(TNodo*)malloc(sizeof(TNodo));
               if(p==NULL)
                  return 0;
               else{
                    p->info=e;
                  aux=l->inicio;
                  for(i=1;i<indice-1;i++)
                     aux=aux->prox;
                  p->prox=aux->prox;
                  aux->prox=p;
                  l->tamanho++;
                  return 1;
               }
            }
    }
}
int setCorrente(lista l, int posicao){
    int i;

    if(posicao<1 || posicao>l->tamanho)
        return 0;
    else{
        l->corrente = l->inicio;
        for(i=1;i<posicao;i++)
           l->corrente=l->corrente->prox;
        return 1;
    }

}

int getCorrente(lista l,TElemento *e){
    if(l->corrente==NULL)
        return 0;
    else{
        *e=l->corrente->info;
        l->corrente=l->corrente->prox;
        return 1;
    }
}
