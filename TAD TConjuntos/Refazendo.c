#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"

TConjunto *creatorConjunto(int tamanho){
    TConjunto *newConj; 

    newConj = (TConjunto*)malloc(sizeof(TConjunto));
    if (newConj == NULL)
    {
        printf("\nA memoria não Foi alocada!!!\n");
        return 0;
    }
    else
    {
        printf("\nConjunto criado!!!\n");
        newConj->elementos = (int*)malloc(tamanho * sizeof(int));
        if (newConj->elementos == NULL)
        {
            free(newConj);
            printf("\nFalha em alocar elementos do conjunto!!!\n");
            return 0;
        }
        else
        {
            newConj->nElementos = 0;
            newConj->tamanho = tamanho;
            for (int i = 0; i < tamanho; i++)
            {
                newConj->elementos[i] = 0;
            }
            return newConj;
        }
    }
}

void setConjunto(TConjunto *conjunto, int *elementos, int tamanho){
    int contador = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (elementos[i] != 0)
        {
            conjunto->elementos[i] = elementos[i];
            contador++;
        }
    }
    conjunto->tamanho = tamanho;
    conjunto->nElementos = contador;
}

void buscaElemento(TConjunto *conjunto, int buscando){
    int achou = 0;
    for (int i = 0; i < conjunto->tamanho; i++)
    {
        if (buscando == conjunto->elementos[i])
        {
            achou = 1;
            break;
        }
    }

    if (achou == 1)
    {
        printf("\nO numero %d foi encontrado",buscando);
    }
    else
    {
        printf("\nO numero %d não foi encontrado",buscando);
    }
}

TConjunto *conjutoIntersection(TConjunto *conjuntoA, TConjunto *conjuntoB){
    TConjunto *conjuntoInter;

    int tamanhoMaximo = (conjuntoA->tamanho > conjuntoB->tamanho) ? conjuntoA->tamanho : conjuntoB->tamanho;
    
    int k = 0;

    conjuntoInter = creatorConjunto(tamanhoMaximo);
    if (conjuntoInter == NULL)
    {
        printf("\nFalha em alocar conjunto!!!\n");
        return NULL;
    }
    else
    {
        conjuntoInter->elementos = malloc(tamanhoMaximo * sizeof(int));
        if (conjuntoInter->elementos == NULL)
        {
            printf("\nFalha em alocar elementos do conjunto!!!\n");
            free(conjuntoInter);
            return NULL;
        }
        else
        {
            conjuntoInter->nElementos = 0;

            for (int i = 0; i < conjuntoA->tamanho; i++)
            {
                for (int j = 0; j < conjuntoB->tamanho; j++)
                {
                    if (conjuntoA->elementos[i] == conjuntoB->elementos[j])
                    {
                        conjuntoInter->elementos[k] = conjuntoA->elementos[i];
                        conjuntoInter->nElementos++;
                        k++;
                    }
                }
            }
            return conjuntoInter;
        }
    }
}

void SaidaDados(TConjunto *conjunto){
    printf("\nCapacidade Conjunto.:%d\n",conjunto->tamanho);
    printf("\nTotal elementos Conjunto.:%d\n",conjunto->nElementos);

    for (int i = 0; i < conjunto->nElementos; i++)
    {
        printf("%d\t",conjunto->elementos[i]);
    }
    printf("\n");
}

int main(){
    TConjunto *conjuntoA;
    TConjunto *conjuntoB;
    TConjunto *conjutoInter;

    int elementosA[] = {1,2,3,4,5,6};
    int elementosB[] = {2,4,6,8,9};
    int tamanhoA = 6;
    int tamanhoB = 5;

    int buscandoA = 3;
    int buscandoB = 7;



    conjuntoA = creatorConjunto(tamanhoA);
    setConjunto(conjuntoA, elementosA, tamanhoA);
    buscaElemento(conjuntoA, buscandoA);
    SaidaDados(conjuntoA);

    conjuntoB = creatorConjunto(tamanhoB);
    setConjunto(conjuntoB, elementosB, tamanhoB);
    buscaElemento(conjuntoB, buscandoB);
    SaidaDados(conjuntoB);

    conjutoInter = conjutoIntersection(conjuntoA, conjuntoB);

    SaidaDados(conjutoInter);

    return 0;
}