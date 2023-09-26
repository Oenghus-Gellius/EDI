#include <stdio.h>
#include <stdlib.h>

#include "Quest3A.h"

// Aloca espaço de memória para receber os dados
lista criaLista(){
    lista listaCriada = (lista)malloc(sizeof(TLista));
    if (listaCriada != NULL)
    {
        listaCriada->inicio = NULL;
        listaCriada->fim = NULL;
        listaCriada->tamanho = 0;
    }
    return listaCriada; 
}

// Função que insere um novo elemento no final
int insereFinal(lista listaCriada, int infoNew){
    TNodo* prtNewElement = (TNodo*)malloc(sizeof(TNodo));

    if (prtNewElement == NULL)
    {
        return 0;
    }
    else
    {
        prtNewElement->info = infoNew;
        prtNewElement->next = NULL;
        if (listaCriada->inicio == NULL)
        {
            listaCriada->inicio = prtNewElement;
        }
        else
        {
            listaCriada->fim->next = prtNewElement;
        }
        listaCriada->fim = prtNewElement;
        listaCriada->tamanho++;
        return 1;
    }
}

void moveMenor(lista listaDesordenada) {
     // Verifica se a lista está vazia ou contém apenas um elemento
    if (listaDesordenada->inicio == NULL || listaDesordenada->inicio->next == NULL) {
        return; // Nada a fazer
    }

    TNodo *ptrMenorElemento = listaDesordenada->inicio;
    TNodo *ptrAntMenor = NULL;
    TNodo *ptr = listaDesordenada->inicio->next;
    TNodo *ptrAnt = listaDesordenada->inicio;

    while (ptr != NULL) {
        if (ptr->info < ptrMenorElemento->info) {
            ptrMenorElemento = ptr;
            ptrAntMenor = ptrAnt;
        }
        ptrAnt = ptr;
        ptr = ptr->next;
    }
    
    if (ptrMenorElemento != listaDesordenada->inicio) {
        // Conecta o elemento anterior ao menor elemento ao elemento seguinte ao menor elemento
        ptrAntMenor->next = ptrMenorElemento->next;
        // Conecta o menor elemento ao início da lista
        ptrMenorElemento->next = listaDesordenada->inicio;
        listaDesordenada->inicio = ptrMenorElemento;
    }

    // Imprime a lista ordenada
    printf("\nLista ordenada?!?\n");
    ptr = listaDesordenada->inicio;
    while (ptr != NULL) {
        printf("%d -\t ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}



// Destroi o espaço que foi alocado
void destroyAlloc(lista lista){
    TNodo* ptr = lista->inicio;
    while (ptr != NULL) {
        TNodo* proximo = ptr->next;
        free(ptr);
        ptr = proximo;
    }
    free(lista);
}


//função teste
void funTest(){
    lista minhaLista;
    int tamanhoLista = 6;
    int i;
    int InfoNew;

    minhaLista = criaLista();
    if (minhaLista == NULL)
    {
        printf("\nErro na criação da lista");
    }
    else
    {
        printf("\nITEM CRIADO COM SUCESSO!!!\n");
        for (i = tamanhoLista; i > 0; i--)
        {
            InfoNew = i;
            printf("%d -\t",InfoNew);
            insereFinal(minhaLista, InfoNew);
        }
        printf("\n");
    }

    moveMenor(minhaLista);

    destroyAlloc(minhaLista);
}



int main(){
    funTest();

    return 0;
}