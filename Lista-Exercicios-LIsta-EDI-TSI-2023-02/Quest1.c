#include <stdio.h>
#include <stdlib.h>

#include "Quest1.h"

lista funcCriarLista(){
    lista lis = (lista)malloc(sizeof(TLista));
    if (lis != NULL)
    {
        lis->tamanho = 0;
        lis->inicio = NULL;
        lis->fim = NULL;
    }
    return lis;
}

int funcIncereFinal(lista lis,TElemento elemento){
    TNodo *ptr = (TNodo*)malloc(sizeof(TNodo));
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        ptr->info = elemento;
        ptr->next = NULL;
        if (lis->inicio == NULL)
        {
            lis->inicio=ptr;
        }
        else
        {
            lis->fim->next = ptr;
        }
        lis->fim = ptr;
        lis->tamanho++;
        return 1;        
    }
}

void funcInvert(lista lis) {
    // Lista vazia ou com apenas um elemento, nada a fazer.
    if (lis == NULL || lis->inicio == NULL || lis->inicio->next == NULL) {
        return;
    }

    TNodo *prev = NULL;
    TNodo *current = lis->inicio;
    TNodo *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Agora, prev aponta para o novo início e l->inicio deve ser atualizado.
    lis->inicio = prev;
}

int funcOrdenaElem(lista lis){
    if (lis == NULL || lis->inicio == NULL || lis->inicio->next == NULL) {
        // Lista vazia ou com apenas um elemento está considerada ordenada.
        return 1;
    }    
    TNodo *current = lis->inicio;

    while (current->next != NULL) {
        if (current->info > current->next->info) {
            // Se o elemento atual for maior que o próximo, a lista não está ordenada.
            return 0;
        }
        current = current->next;
    }

    // Se chegou até aqui, a lista está ordenada.
    return 1;
}

int main() {
    lista lis = funcCriarLista(); // Cria a lista

    if (lis != NULL) { // Verifica se a lista foi criada com sucesso
        TElemento elementos;
        int i;

        for (i = 0; i <= 5; i++) {
            elementos = i;
            printf("%d\t", elementos);
            funcIncereFinal(lis, elementos);
        }
        printf("\n");

        // Inverte a lista
        funcInvert(lis);

        // Imprime a lista invertida
        TNodo *current = lis->inicio;
        while (current != NULL) {
            printf("%d\t", current->info);
            current = current->next;
        }
        printf("\n");

        while (current != NULL)
        {
            printf("%d\t", current->info);
            current = current->next;
        }
        

        // Verifica se a lista está ordenada
        if (funcOrdenaElem(lis)) {
            printf("A lista está ordenada.\n");
        } else {
            printf("A lista não está ordenada.\n");
        }

        // Libera a memória alocada para a lista
        free(lis);

    } else {
        printf("Falha ao criar a lista.\n");
    }

    return 0;
}

