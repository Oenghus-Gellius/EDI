#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"

//Função para alocar dinamicamente uma lista (vetor) entra o tamanho do vetor
TConjunto *criaConjunto(int capacidade){
    TConjunto* conjuntoCriado = (TConjunto*)malloc(capacidade * sizeof(TConjunto));
    if (conjuntoCriado == NULL)
    {
        printf("\nfalha em criar conjunto!!!");
    }
    else
    {
        printf("\nConjunto criado!!!\n");
        //olocando o "vetor" de elementos
        conjuntoCriado->elementos = (int*)malloc(capacidade * sizeof(int));
        if (conjuntoCriado->elementos == NULL)
        {
            free(conjuntoCriado);
            return 0;
        }
    }
    return conjuntoCriado;
}

//inserir elementos no conjunto <= PAREI AQUI!!!

//destroi o vetor alocado
void destroyerConjunto(conjuntoDecadencia){
    free(conjuntoDecadencia);
    }



    int main(){

    TConjunto* conjuntoA = criaConjunto(5);
    TConjunto* conjuntoB = criaConjunto(5);
    

    return 0;
}