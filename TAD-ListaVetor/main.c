#include <stdio.h>
#include <stdlib.h>
#include "listaVE.h"

int main(){
    lista li = criaLista();
    TElemento e;
    int tam,i;
    if(li!=NULL){

       for(i=1;i<=100;i++){
           e.chave=i;
           if(insereFinal(li,e)==0)
               printf("\nLista Cheia!!!\n");
       }
       e.chave=10000;
       if(inserePosicao(li,e,3)==0)
           printf("\nLista Cheia!!!\n");

      /* tam = getTamanho(li);
       printf("\nElementos da Lista\n");
       for(i=1;i<=tam;i++){
          getElemento(li,&e,i);
          printf("%d\n",e.chave);
       }*/
       printf("\nElementos da Lista\n");
       setCursor(li,1);
       while(getCorrente(li,&e)==1)
           printf("%d\n",e.chave);

       if(removeElemento(li,5,&e)==1){
          printf("\nO Elemento com a chave %d foi removido\n",e.chave);
          tam = getTamanho(li);
          printf("\nElementos da Lista Após a Remoção\n");
          for(i=1;i<=tam;i++){
             getElemento(li,&e,i);
             printf("%d\n",e.chave);
          }

       }
       else
          printf("\nChave não encontrada!!!\n");



      if(buscaElemento(li,5,&e)==1)
          printf("\nAchou!!\n");
      else
          printf("\nEelemento Não Encontrado!!!\n");
      terminaLista(li);
    }
    else
        printf("\nNão foi possível criar a lista\n");
    return 0;
}

