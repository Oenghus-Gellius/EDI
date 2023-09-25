#include <stdio.h>
#include <stdlib.h>

#include "Quest3Prova.h"

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

void moveMenor(lista listaDesordenada){
    int menorElemento = NULL;//recebe o primeiro elemto da lista entadeada
    TNodo *ptr;
    TNodo *ptrAnt;
    while (ptr != NULL)
    {
        if (menorElemento == NULL)
        {
            menorElemento = ptr->info;
        }
        if (ptr->info < menorElemento)
        {
            /* code */
        }
        
    }
    
    
    

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
    lista lista;
    int tamanhoLista = 6;
    int i;
    int InfoNew;

    lista = criaLista();
    if (lista == NULL)
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
            insereFinal(lista,InfoNew);
        }
        printf("\n");
    }


    destroyAlloc(lista);
}


int main(){
    funTest();

    return 0;
}