#include <stdio.h>
#include <stdlib.h>
#include "listaSE.h"

/*
typedef struct Lista{
    TNodo *inicio,*fim,*cursor;
    int tamanho;
}TLista;

*/

lista criaLista(){
    lista l =(lista)malloc(sizeof(TLista));
    if(l!=NULL){
       l->tamanho=0;
       l->fim=NULL;
       l->inicio=NULL;
    }
    return l;
}


void terminaLista(lista l){
    TNodo *p;
    while(l->inicio!=NULL){
        p=l->inicio;
        l->inicio = l->inicio->prox;
        //l->inicio=p->prox;
        free(p);
    }
    free(l);
}

int insereInicio(lista l, TElemento e){
    TNodo *p=(TNodo*)malloc(sizeof(TNodo));
    if(p==NULL)
        return 0;
    else{
        p->info=e;
        p->prox=l->inicio;
        l->inicio = p;
        l->tamanho++;
        //verificando se é o primeiro nodo da lista
        if(l->tamanho==1)
            l->fim = p;
        return 1;
    }
}

int insereFinal(lista l, TElemento e){
    TNodo *p=(TNodo*)malloc(sizeof(TNodo));
    if(p==NULL)
        return 0;
    else{
        p->info=e;
        p->prox=NULL;
        if(l->inicio==NULL)
            l->inicio=p;
        else
            l->fim->prox =p;
        l->fim = p;
        l->tamanho++;
        return 1;
    }
}

int getTamanho(lista l){
    return l->tamanho;
}

int getElemento(lista l,TElemento *e, int indice){
    int i;
    TNodo *p;
    //verificando se o índice é válido
    if(indice<1 ||indice >l->tamanho )
        return 0;
    p=l->inicio;
    for(i=1;i<indice;i++){
        p=p->prox;
    }
    *e=p->info;
    return 1;
}

int removeElemento(lista l,TChave ch,TElemento *e){
    TNodo *ptr,*ptrAnt;
    ptr=l->inicio;

    while(ptr!=NULL){
        if(ptr->info.chave==ch){
            //verificando se o nodo a ser removido é o primeiro da lista
            if(l->inicio ==ptr){
                l->inicio = l->inicio->prox;//l->inicio = ptr->prox;
            }
            else
                if(l->fim==ptr){
                   l->fim=ptrAnt;
                   ptrAnt->prox=NULL;//l->fim->prox=NULL;
                }
                else
                    ptrAnt->prox=ptr->prox;

            *e=ptr->info;
            free(ptr);
            l->tamanho--;
            return 1;
        }
        else{
            ptrAnt = ptr;
            ptr=ptr->prox;
        }
    }
    return 0;
}

int buscaElemento(lista l,TChave ch, TElemento *e){
    TNodo *ptr;
    ptr=l->inicio;

    while(ptr!=NULL){
        if(ptr->info.chave==ch){
            *e=ptr->info;
            return 1;
        }
        else
            ptr = ptr->prox;
    }

    return 0;
}
