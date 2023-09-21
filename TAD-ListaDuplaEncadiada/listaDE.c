#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

typedef struct Nodo{
    TElemento info;
    struct Nodo *prox,*ant;
}TNodo;

typedef struct Lista{
    TNodo *inicio,*cursor;
    int tamanho,posicaoCorrente;
}TLista;

lista criaLista(){
    lista l =(lista)malloc(sizeof(TLista));
    if(l!=NULL){
       l->tamanho=0;
       l->cursor=NULL;
       l->inicio=NULL;
       l->posicaoCorrente=1;
    }
    return l;
}

void terminaLista(lista l){
    TNodo *p;
    int i;
    for(i=1;i<=l->tamanho;i++){
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
        l->tamanho++;

        //verificando se é o primeiro nodo da lista
        if(l->tamanho==1){
           p->ant=p;
           p->prox=p;
        }
        else{
           p->prox=l->inicio;
           p->ant=l->inicio->ant;
           l->inicio->ant->prox=p;//p->ant->prox=p;
           l->inicio->ant=p;
        }
        l->inicio=p;
        return 1;
    }
}

int insereFinal(lista l, TElemento e){
    TNodo *p;

    if(listaCheia(l)==1)
       return 0;

    if(l->inicio==NULL)
       return insereInicio(l,e);
    else{
        p=(TNodo*)malloc(sizeof(TNodo));
        p->info=e;
        p->ant=l->inicio->ant;
        p->prox=l->inicio;
        l->inicio->ant->prox=p;//p->ant->prox=p;
        l->inicio->ant=p;
        l->tamanho++;
        return 1;
    }
}

int getTamanho(lista l){
    return l->tamanho;
}



int getElemento(lista l,TElemento *e, int indice){
   TNodo *ptr,*ptrAux;
   int i;

   if(indice<1 || indice >l->tamanho)
      return 0;
   if(listaVazia(l)==1)
       return 0;

   //verificando o sentido usado para percorrer a lista
   ptr=l->inicio;
   if(indice<=l->tamanho/2){
      for(i=1;i<indice;i++)
         ptr=ptr->prox;
   }
   else{
      for(i=l->tamanho;i>=indice;i--)
         ptr=ptr->ant;
   }
   *e=ptr->info;
   return 1;

}

int removeElemento(lista l,TChave ch,TElemento *e){
   int i =1;
   TNodo *ptr;
   ptr=l->inicio;
   while(i<=l->tamanho){
      if(ptr->info.chave==ch){
         ptr->prox->ant=ptr->ant;
         ptr->ant->prox = ptr->prox;
         if(ptr==l->inicio)
            l->inicio=l->inicio->prox;
         l->tamanho--;
         *e=ptr->info;
         free(ptr);
         //verificando se a lista ficou vazia
         if(l->tamanho==0)
            l->inicio=NULL;
         return 1;
      }
      else{
         i++;
         ptr=ptr->prox;
      }
   }
   return 0;
}


int buscaElemento(lista l,TChave ch, TElemento *e){
   TNodo *ptr;
   int posicao=1;
   ptr=l=l->inicio;
   while(posicao<=l->tamanho){
       if(ptr->info.chave==ch){
          *e=ptr->info;
          return 1;
       }
       else
           ptr=ptr->prox;
       posicao++;
   }
   return 0;
}




int setCursor(lista l,int indice){
   int i;
   if(indice<1 || indice>l->tamanho)
      return 0;
   l->cursor=l->inicio;
   l->posicaoCorrente=indice;
   if(indice<=l->tamanho/2){
      for(i=1;i<indice;i++)
         l->cursor=l->cursor->prox;
   }
   else{
      for(i=l->tamanho;i>=indice;i--)
         l->cursor=l->cursor->ant;
   }

   return 1;
}

int getCorrente(lista l, TElemento *e){
  if(l->posicaoCorrente>l->tamanho)
      return 0;
  *e=l->cursor->info;
  l->cursor=l->cursor->prox;
  l->posicaoCorrente++;
}

int listaVazia(lista l){
    return l->tamanho==0;
}

int listaCheia(lista l){
    TNodo *ptr = (TNodo*)malloc(sizeof(TNodo));
    if(ptr==NULL)
        return 1;
    else{
        free(ptr);
        return 0;
    }
}
int inserePosicao(lista l, TElemento e, int indice){
   TNodo *ptr,*ptrAux;
   int i;

   if(indice<1 || indice >l->tamanho+1)
      return 0;
   if(listaCheia(l)==1)
       return 0;

   if(indice==1)
      return insereInicio(l,e);
   else
      if(indice==l->tamanho+1)
         return insereFinal(l,e);
      else{
          //verificando o sentido usado para percorrer a lista
          ptr=l->inicio;
          if(indice<=l->tamanho/2){
             for(i=1;i<indice;i++)
                ptr=ptr->prox;
          }
          else{
             for(i=l->tamanho;i>=indice;i--)
                ptr=ptr->ant;
          }
          ptrAux=(TNodo*)malloc(sizeof(TNodo));
          ptrAux->info=e;
          ptrAux->prox=ptr;
          ptrAux->ant=ptr->ant;
          ptr->ant->prox=ptrAux;//ptrAux->ant>prox;
          ptr->ant=ptrAux;//ptrAux->prox->ant=ptrAux;
          l->tamanho++;
          return 1;
      }
}
void imprime(lista l){
    TNodo *ptr;
    int i;
    ptr=l->inicio;
    for(i=1;i<=l->tamanho;i++){
        printf("\n%d",ptr->info.chave);
        ptr=ptr->prox;
    }
}
