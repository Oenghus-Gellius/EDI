#include "RevisionSE.h"

#include <stdio.h>
#include <stdlib.h>

TList* bornList() {
    TList* newList = (TList*)malloc(sizeof(TList));
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

int firstInList(TList* firstList, int codListEnter) {
    TNodoList* firstNodo = (TNodoList*)malloc(sizeof(TNodoList));
    if (firstNodo == NULL)
    {
        printf("\nErro ao alocar Nodo\n");
        return 0;
    }
    else
    {
        firstNodo->codList = codListEnter;
        firstNodo->nextList = NULL;

        if (firstList->inicio == NULL)
        {
            firstList->inicio = firstNodo;
            firstList->fim = firstNodo;
        }
        else
        {
            firstNodo->nextList = firstList->inicio;
            firstList->inicio = firstNodo;
        }

        firstList->tamanho++;

        if (firstList->tamanho == 1)
        {
            firstList->cursor = firstNodo;
            firstList->fim = firstNodo;
        }
        return 1;
    }
}

int putEndList(TList* endlist, int codEnter) {
    TNodoList* endNodo = (TNodoList*)malloc(sizeof(TNodoList));
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

int sizeList(TList* list) {
    return list->tamanho;
}

void setList(TList* listBase, int* numb, int quantidade) {
    TNodoList* nodoList = (TNodoList*)malloc(sizeof(TNodoList));

    for (int i = 0; i < quantidade; i++)
    {
        putEndList(listBase, numb[i]);
    }
}

int finderElement(TList* listaBase, int numb) {
    TNodoList* ptrNodo = listaBase->inicio;

    while (ptrNodo != NULL)
    {
        if (ptrNodo->codList == numb)
        {
            return 1;
        }
        ptrNodo = ptrNodo->nextList;
    }
    return 0;
}

int setCursor(TList* list, int index) {

    if (index > 0 && index <= list->tamanho)
    {
        list->cursor = list->inicio;
        list->corrent = index;
        for (int i = 0; i < index; i++)
        {
            list->cursor = list->cursor->nextList;
        }
    }
    else
    {
        printf("\Fora do escopo de busca\n");
        return 0;
    }
    return 1;
}

int getCorrent(TList* list, int elemet) {
    if (list->corrent > list->tamanho)
    {
        return 0;
    }
    elemet = list->cursor->codList;
    list->cursor = list->cursor->nextList;
    list->corrent++;
    if (list->corrent == list->tamanho)
    {
        list->corrent = list->inicio;
    }
    return elemet;
}

TList* removeList(TList* listBase, int numFinder) {
    TNodoList* ptrNodoList = listBase->inicio;
    TNodoList* ptrPrev = NULL;

    int find = 0;

    while (ptrNodoList != NULL)
    {
        if (ptrNodoList->codList == numFinder)
        {
            if (ptrNodoList == listBase->inicio)//se for o primeiro
            {
                ptrPrev = listBase->inicio;
                ptrPrev->nextList = ptrNodoList->nextList;
            }
            else
            {
                if (ptrNodoList == listBase->fim)//Se for o ultimo
                {
                    listBase->fim = ptrPrev;
                }
                else
                {
                    ptrPrev->nextList = ptrNodoList->nextList;//lista conectada
                }
            }
            free(ptrNodoList);
            listBase->tamanho--;
            return listBase;
        }
        else
        {
            ptrPrev = ptrNodoList;
            ptrNodoList = ptrNodoList->nextList;
        }
    }
    if (find == 0)
    {
        printf("\nCodigo %d não encontrado\n", numFinder);
    }
    return listBase;
}

TList* putInPositionList(TList* listBase, int indice, int numPut) {
    TNodoList* ptrNodo = (TNodoList*)malloc(sizeof(TNodoList));

    TNodoList* ptrPrev;

    ptrPrev = listBase->inicio;

    if (listFull(listBase))
    {
        return 0;
    }

    if (ptrNodo == NULL)
    {
        printf("\nErro ao alocar Nodo\n");
        free(listBase);
        return 0;
    }

    if (indice > 0 && indice < listBase->tamanho + 1)
    {
        while (ptrNodo != NULL)
        {
            if (indice == 1)
            {
                listBase = firstInList(listBase, numPut);
                return listBase;
            }
            else
            {
                if (listBase->tamanho == indice)
                {
                    listBase = putEndList(listBase, numPut);
                    return listBase;
                }
                else
                {
                    ptrNodo->codList = numPut;
                    ptrPrev = listBase->inicio;
                    for (int i = 1; i < indice - 1; i++)
                    {
                        ptrPrev = ptrPrev->nextList;
                    }
                    ptrNodo->nextList = ptrPrev->nextList;
                    ptrPrev->nextList = ptrNodo;
                    listBase->tamanho++;
                    return listBase;
                }
            }
        }
    }
    else
    {
        printf("\nValor de indice Errado\n");
    }
}

int listFull(TList* list) {
    TNodoList* ptrNode = (TNodoList*)malloc(sizeof(TNodoList));
    if (ptrNode == NULL)
    {
        return 1;
    }
    else
    {
        free(ptrNode);
        return 0;
    }
}

int emptList(TList* list) {
    return list->tamanho == 0;
}

void saidaList(TList* listPrint) {
    TNodoList* nodoPrint = listPrint->inicio;

    while (nodoPrint != NULL)
    {
        printf("%d\t", nodoPrint->codList);
        nodoPrint = nodoPrint->nextList;
    }
}

void destroyerlist(TList* list) {
    TNodoList* ptrNode = list->inicio;
    while (list->inicio != NULL)
    {
        list->inicio = list->inicio->nextList;
        free(ptrNode);
        ptrNode = list->inicio;
    }
    free(list);
}





/*
//Função com o objetivo de ordenar os elementos de uma lista encadeada
//Apenas fazendo mudanças de ponterios e não do conteudo da estruct
void bubbleSortListAscending(TList* listEnter) {
    int swapped;

    TNodoList* ptrNodo;

    TNodoList* ptrNext = NULL;

    TNodoList* ptrAux = NULL;

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
                    TNodoList* prevNode = listEnter->inicio;
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
        printf("%d\t",ptrNodo->codList);
        ptrNext = ptrNodo;
    } while (swapped);
}

void bubbleSortListDescending(int *numbBase){
    int aux;

    for (int i = 0; i < 10-1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
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

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t",numbBase[i]);
    }
    printf("\n");
}
*/
