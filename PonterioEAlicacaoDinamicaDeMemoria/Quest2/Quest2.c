//arquivo de implementação

#include "Quest2.h"

// Implementação da função para gerar aleatoriamente o vetor
void lerVetor(int *vetor,int tamVet){
    int i;
    for (i = 0; i < tamVet; i++)
    {
        vetor[i]=rand()%100;
    }  
}

// Implementação da função para imprimir o vetor
void printVetor(int *vetor, int tamVet){
    int i;
    for (i = 0; i < tamVet; i++)
    {
    printf(" vetor[%d]=%d,",i,vetor[i]);
    }
    printf("\n");
}