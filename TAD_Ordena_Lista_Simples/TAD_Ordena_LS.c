#include "TAD_Ordena_LS.h"

#include <stdio.h>
#include <stdlib.h>

#define QTD_ELEMENTS 10

TList *bornList(){
    TList *newList = (TList*)malloc(sizeof(TList));
    if (newList == NULL)
    {
        printf("\nErro ao alocar lista\n");
        return 0;
    }
    else
    {
        newList->inicio = NULL;
        newList->fim = NULL;
        newList->tamanho = 0;

        newList->cursor = NULL;
        return newList;
    }
}

int firstList(TList *firstList, int codListEnter){
    TNodoList *firstNodo = (TNodoList*)malloc(sizeof(TNodoList));
    if (firstNodo == NULL)
    {
        printf("\nErro ao alocar Nodo\n");
        free(firstList);
        return 0;
    }
    else
    {
        firstNodo->codList = codListEnter;
        firstNodo->nextList = firstList->inicio;
        firstList->tamanho++;
        firstList->inicio = firstNodo;
        
        if (firstList->tamanho == 1)
        {
            firstList->cursor = firstNodo;
            firstList->fim = firstNodo;
        }
        return 1;
    }
}

int endList(TList *endlist, int codEnter){
    TNodoList *endNodo = (TNodoList*)malloc(sizeof(TNodoList));
    if (endNodo == NULL)
    {
        printf("\nErro ao alocar Nodo\n");
        free(endlist);
        return 0;
    }
    else
    {
        endNodo->codList = codEnter;
        endNodo->nextList = NULL;

        if (endlist->inicio == NULL)//Se for o primeiro
        {
            endlist->inicio = endNodo;
        }
        else
        {
            endlist->fim->nextList = endNodo;       
        }
        endlist->fim = endNodo;
        endlist->tamanho++;
        return 1;
    }
}

int sizeList(TList *list){
    return list->tamanho;
}

void setList(TList *listBase, int *numb){
    TNodoList *nodoList = (TNodoList*)malloc(sizeof(TNodoList));

    for (int i = 0; i < QTD_ELEMENTS; i++)
    {
        endList(listBase, numb[i]);
    }
}

void removeList(TList *listBase, TNodoList *elemento){
    TNodoList *ptrNodoList = (TNodoList*)malloc(sizeof(TNodoList));
    ptrNodoList = listBase->inicio;

    
}
void saidaList(TList *listPrint){
    TNodoList *nodoPrint = listPrint->inicio;

    while (nodoPrint != NULL)
    {
        printf("%d\t",nodoPrint->codList);
        nodoPrint = nodoPrint->nextList;
    }
}

//Função com o objetivo de ordenar os elementos de uma lista encadeada
//Apenas fazendo mudanças de ponterios e não do conteudo da estruct
void BubbleSortListAscending(TList *listEnter) {
    int swapped;

    TNodoList *ptrNodo;

    TNodoList *ptrNext = NULL;

    TNodoList *ptrAux = NULL;

    //lista vazia
    if (listEnter == NULL)
    {
        printf("\nLista vazia\n");
        return;
    }
    do
    {
        swapped = 0;
        ptrNodo = listEnter->inicio;

        while (ptrNodo->nextList != ptrNext)
        {
            if (ptrNodo->codList > ptrNodo->nextList->codList)
            {
                //troca de nodos
                ptrAux = ptrNodo;
                ptrNodo = ptrNodo->nextList;
                ptrAux->nextList = ptrNodo->nextList;
                ptrNodo->nextList = ptrAux;

                //Update ponteiros
                if (ptrAux == listEnter->inicio)
                {
                    listEnter->inicio = ptrNodo;
                }
                else
                {
                    ptrAux->nextList = ptrNodo;
                }

                // Verifica se ptrAux não é o primeiro nodo da lista
                if (ptrAux != listEnter->inicio) {
                    // Encontra o nodo anterior a ptrAux
                    TNodoList *prevNode = listEnter->inicio;
                    while (prevNode->nextList != ptrAux) {
                        prevNode = prevNode->nextList;
                    }
                    // Atualiza o ponteiro nextList do nodo anterior para apontar para ptrNodo
                    prevNode->nextList = ptrNodo;
                }
                swapped = 1;
            }
            else
            {
                ptrNodo = ptrNodo->nextList;
            }
        }
        ptrNext = ptrNodo;
    } while (swapped);
}

/*
void ascendingSortlogic(int *numbBase){
    int aux;

    for (int i = 0; i < QTD_ELEMENTS-1; i++)
    {
        for (int j = 0; j < QTD_ELEMENTS - i - 1; j++)
        {
            if (numbBase[j]>numbBase[j+1])
            {
                aux = numbBase[j];
                numbBase[j] = numbBase[j+1];
                numbBase[j+1] = aux;
            }
        }
    }   
}

void outTestlogic(int *numbBase){ //Saida da lista

    for (int i = 0; i < QTD_ELEMENTS; i++)
    {
        printf("%d\t",numbBase[i]);
    }
    printf("\n"); 
}
*/

void test(){

    TList *listBase = bornList();

    int numb[] = {9, 12, 7, 13, 21, 55, 14, 90, 1, 88};

    setList(listBase, numb);
    
    printf("\nLista base\t\t.:");

    saidaList(listBase);
    
    //outTestlogic(numb);

    printf("\nLista Ordenada Cresc.:");
    BubbleSortListAscending(listBase);
    saidaList(listBase);

    //ascendingSortlogic(numb);
    //outTestlogic(numb);
}

int main(){
    test();

    return 0;
}