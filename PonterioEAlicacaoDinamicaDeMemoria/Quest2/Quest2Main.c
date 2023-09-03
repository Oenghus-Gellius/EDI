/*
2) Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos e passe esse
vetor para uma função que vai ler os elementos desse vetor. Depois, no programa principal, o vetor
preenchido deve ser impresso. Além disso, antes de finalizar o programa, deve-se liberar a área de
memória alocada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Quest2.h"

int main(){
    int tamVet;
    int *vetor;

    //definindo o tamanho do ventor
    printf("\nInsira o tamanho do vetor.:");
    scanf("%d",&tamVet);

    //void criandoVetor(tamVet);
    vetor=(int*)calloc(tamVet,sizeof(int));

    //gerando aleatoriamento o ventor
    lerVetor(vetor,tamVet);

    //void printVetor();
    printVetor(vetor,tamVet);

    //limpando 
    free(vetor);
    
    return 0;
}