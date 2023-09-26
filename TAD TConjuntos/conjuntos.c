#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"

//Função para alocar dinamicamente uma lista (vetor) entra o tamanho do vetor
TConjunto *criaConjunto(int capacidade){
    TConjunto* conjuntoCriado = (TConjunto*)malloc(sizeof(TConjunto));
    if (conjuntoCriado == NULL)
    {
        printf("\nfalha em criar conjunto!!!");
        return NULL;
    }
    else
    {
        printf("\nConjunto criado!!!\n");
        //alocando o "vetor" de elementos
        conjuntoCriado->elementos = (int*)malloc(capacidade * sizeof(int));
        if (conjuntoCriado->elementos == NULL)
        {
            free(conjuntoCriado);
            printf("\nFalha em alocar elementos do conjunto!!!\n");
            return 0;
        }
    }
    conjuntoCriado->capacidade = capacidade;
    conjuntoCriado->tamanho = 0;
    return conjuntoCriado;
}

//inserir elementos no conjunto 
void setElementos(TConjunto* conjunto, int elemento, int indice){
    if (indice >= 0 && indice < conjunto->capacidade)
    {
        conjunto->elementos[indice] = elemento;
        conjunto->tamanho++;
    }
}

//imprime conjunto
void saidaConjunto(TConjunto* conjunto){
    for (int i = 0; i < conjunto->tamanho; i++)
    {
        printf("%d\t",conjunto->elementos[i]);
    }
    printf("\n");
}

void verificaPertenceimento (TConjunto* conjuntoCheck, int elementoPesquisado){
    int i;
    int achou = -1;
    for (i = 0; i < conjuntoCheck->tamanho; i++)
    {
        if (conjuntoCheck->elementos[i] == elementoPesquisado)
        {
            achou=0;
        }
    }
    if (achou == 0)
    {
        printf("\nElemento %d encontrado no conjunto!!!\n",elementoPesquisado);
    }
    else
    {
        printf("\nElemento %d não encontrado no conjunto!!!\n",elementoPesquisado);
    }
}

//destroi o vetor alocado
void destroyerConjunto(TConjunto* conjuntoDest){
    free(conjuntoDest->elementos);
    free(conjuntoDest);
    }


    int main(){
        int i;
        int nElementos;
        int tamanho;
        int check;
        int elementoPesquisadoA = 2; 
        int elementoPesquisadoB = 2; 

        nElementos = 5;
        tamanho = 5;

    TConjunto* conjuntoA = criaConjunto(tamanho);
    TConjunto* conjuntoB = criaConjunto(tamanho);

    for (i = 0; i < tamanho; i++)
    {
        setElementos(conjuntoA, i, i);
        setElementos(conjuntoB,i+3, i);
    }

    // Verificar o conteúdo dos conjuntos antes de imprimir
    printf("\nConjunto A: \n");
    saidaConjunto(conjuntoA);
    printf("\nConjunto B: \n");
    saidaConjunto(conjuntoB);

    verificaPertenceimento (conjuntoA, elementoPesquisadoA);   
    verificaPertenceimento (conjuntoB, elementoPesquisadoB);   

    destroyerConjunto(conjuntoA);
    destroyerConjunto(conjuntoB);

    return 0;
}