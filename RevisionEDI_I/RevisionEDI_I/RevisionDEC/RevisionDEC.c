#include "RevisionDEC.h"

#include <stdio.h>
#include <stdlib.h>

TList* bornList() {
	TList *list = (TList*)malloc(sizeof(TList));
    if (list == NULL)
    {
        printf("\nErro ao alocar lista\n");
        return 0;
    }
    else
    {
        list->inicio = NULL;
        list->tamanho = 0;

        list->cursor = NULL;
        return list;
    }
}

int firstInList(TList* list, int cod) {
    TNodoList* ptrNodo = (TList*)malloc(sizeof(TList));
    if (ptrNodo == NULL)
    {
        printf("\nErro ao alocar nodo\n");
        return 0;
    }
    else
    {
        ptrNodo->codList = cod;
        list->tamanho++;

        if (list->tamanho == 1)
        {
            list->cursor = ptrNodo;
            ptrNodo->backList = ptrNodo;
            ptrNodo->nextList = ptrNodo;
        }
        else
        {
            ptrNodo->nextList = list->inicio;
            ptrNodo->backList = list->inicio->backList;
            list->inicio->backList->nextList = ptrNodo;
        }
        list->inicio = ptrNodo;
        return 1;
    }

}

int putEndList(TList* list, int cod) {
    TNodoList* ptrNodo = (TList*)malloc(sizeof(TList));
    
    //if() LSITA CHEIA
    
    if (ptrNodo == NULL)
    {
        printf("\nErro ao alocar nodo\n");
        return 0;
    }
    else
    {
        if (list->inicio == NULL)
        {
            free(ptrNodo);
            return firstInList(list, cod);
        }
        else
        {
            ptrNodo->codList = cod;
            ptrNodo->backList = list->inicio->backList;
            ptrNodo->nextList = list->inicio;
            list->inicio->backList->nextList = ptrNodo;
            list->inicio->backList = ptrNodo;
            list->tamanho++;
            return 1;
        }
    }
}

void setList(TList* list, int* listNumb, int qtd) {
    int num;
    for (int i = 0; i < qtd; i++)
    {
        num = listNumb[i];
        putEndList(list, num);
    }
}

void destroyerlist(TList* list) {
    TNodoList *ptrNodo;
    
    for (int i = 1; i < list->tamanho; i++)
    {
        ptrNodo = list->inicio;
        list->inicio = list->inicio->nextList;
        free(ptrNodo);
    }
    free(list);
}

void saidaList(TList* list) {
    TNodoList* ptrNodo;

    ptrNodo = list->inicio;

    for (int i = 1; i <= list->tamanho; i++)
    {
        printf("%d\t", ptrNodo->codList);
        ptrNodo = ptrNodo->nextList;
    }
    printf("\n");
}