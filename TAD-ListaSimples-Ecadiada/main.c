#include <stdio.h>
#include <stdlib.h>
#include "listaSE.h"

int main(){
    lista li = criaLista();
    TElemento e;
    int tam,i;
    if(li!=NULL){

       for(i=1;i<=5;i++){
           e.chave=i;
           insereFinal(li,e);
       }

       tam = getTamanho(li);
       printf("\nElementos da Lista\n");
       for(i=1;i<=tam;i++){
          getElemento(li,&e,i);
          printf("%d\n",e.chave);
       }

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
