#include <stdio.h>
#include <stdlib.h>

#include "listaSE.h"

int main(){
    lista l;
    TElemento e;
    int i;
    l= criaLista();
    if(l!=NULL){
       for(i=1;i<10;i++){
           e.chave=i;
           insereFinal(l,e);
       }
       e.chave=300;
       inserePosicao(l,e,3);
       setCorrente(l,1);
       printf("\nElementos da Lista\n");
       while(getCorrente(l,&e)==1){
          printf("%d\n",e.chave);
          i++;
       }
       terminaLista(l);
    }
    else
       printf("\nErro!!!!!\n");
    return 0;
}
