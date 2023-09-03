/*
3) Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e retorne
um ponteiro. 
Crie uma função que receba um ponteiro para um vetor e um valor n e imprima os n
elementos desse vetor. 
Construa também uma função que receba um ponteiro para um vetor e libere esta área de memória. 
Ao final, crie uma função principal que leia um valor n e chame a função criada acima. 

Depois, a função principal deve ler os n elementos desse vetor. Então, a
função principal deve chamar a função de impressão dos n elementos do vetor criado e, finalmente,
liberara memória alocada através da função criada para liberação.
*/
#include <stdio.h>
#include <stdlib.h>

//função de criação dinamica de um vetor, retornar ponterio do vetor;
int *funcConstruction(int nElemVet){
    int *ptrVetor=(int *)malloc(nElemVet*(sizeof(int)));
    return ptrVetor;
}

//funçaõ de saida dps valores dos elementos do vetor
void funcSaidaDados(int *ptrVetor ,int nElemVet){
    int i;
    for (i = 0; i < nElemVet; i++)
    {
        printf("Vetor[%d]=%d\t",i,ptrVetor[i]);
    }
    printf("\n");
}

//Preenchendo o vetor
void funcPreenchendoVetor(int *ptrVetor,int tamanho){
    int i;
    for (i = 0; i < tamanho; i++)
    {
        ptrVetor[i]=i+1;
    }
}

// Chama a função para desalocar o vetor
    void funcDestroyVetor(int **ptrVetor){
        free(ptrVetor);
        *ptrVetor=NULL;
    }


int main()
{
    int nElemVet;
    int *ptrVetor;

    printf("\nNumero de Elemetos do Vetor.:");
    scanf("%d",&nElemVet);

    //Chama a função de criação dinamica de um vetor 
    ptrVetor=funcConstruction(nElemVet);

    //Preenchendo o vetor
    funcPreenchendoVetor(ptrVetor,nElemVet);

    //Chama a funçaõ de saida dps valores dos elementos do vetor
    funcSaidaDados(ptrVetor ,nElemVet);

    // Chama a função para desalocar o vetor
    funcDestroyVetor(&ptrVetor);

    if (ptrVetor==NULL)
    {
        printf("Memoria desalocada com sucesso!!");
    }
    else
    {
        printf("ERRRO na desalocação de memoria.");
    }
    
    return 0;
}
