#include <stdio.h>
#include <stdlib.h>

// Definição de tipos e estruturas necessárias
typedef int TElemento; // Tipo dos elementos na lista
typedef struct TNodo {
    TElemento info;
    struct TNodo* next;
} TNodo;

typedef struct TLista {
    int tamanho;
    TNodo* inicio;
    TNodo* fim;
} TLista;

typedef TLista* lista; // Definindo lista como um ponteiro para TLista

// Funções para manipulação da lista

// Aloca espaço de memória para receber os dados
lista funcCriarLista() {
    lista lis = (lista)malloc(sizeof(TLista));
    if (lis != NULL) {
        lis->tamanho = 0;
        lis->inicio = NULL;
        lis->fim = NULL;
    }
    return lis;
}

// Destroi o espaço que foi alocado
void funcDestroy(lista lis) {
    TNodo* ptr;
    while (lis->inicio != NULL) {
        ptr = lis->inicio;
        lis->inicio = lis->inicio->next;
        free(ptr);
    }
    free(lis);
}

// Função que insere um elemento no início da lista
int funcInsereInicio(lista lis, TElemento elemento) {
    TNodo* ptr = (TNodo*)malloc(sizeof(TNodo));
    if (ptr == NULL) {
        return 0;
    } else {
        ptr->info = elemento;
        ptr->next = lis->inicio;
        lis->inicio = ptr;
        lis->tamanho++;

        if (lis->tamanho == 1) {
            lis->fim = ptr;
        }
        return 1; // Indica sucesso na inserção
    }
}

// Função que insere um novo elemento no final
int funcInsereFinal(lista lis, TElemento elemento) {
    TNodo* ptr = (TNodo*)malloc(sizeof(TNodo));
    if (ptr == NULL) {
        return 0;
    } else {
        ptr->info = elemento;
        ptr->next = NULL;
        if (lis->inicio == NULL) {
            lis->inicio = ptr;
        } else {
            lis->fim->next = ptr;
        }
        lis->fim = ptr;
        lis->tamanho++;
        return 1;
    }
}

// Retorna o tamanho da lista
int funcGetTamanho(lista lis) {
    if (lis == NULL) {
        return 0;
    }
    return lis->tamanho;
}

/* Retorna em *elementoPesq o valor do elemento da posição posicaoElemento e
   retorna verdadeiro. Se índice for inválido, retorna falso */
int funcGetElemento(lista lis, TElemento* elementoPesq, int posicaoElemento) {
    int i;
    TNodo* ptr;

    if (posicaoElemento < 1 || posicaoElemento > lis->tamanho) {
        return 0;
    }
    ptr = lis->inicio;
    for (i = 1; i < posicaoElemento; i++) {
        ptr = ptr->next;
    }
    *elementoPesq = ptr->info;
    return 1; // Indica que o elemento foi encontrado
}

// Remove um elemento específico da lista, passado
int funcRemoveElemento(lista lis, TElemento elementoPesq, TElemento* elemento) {
    TNodo* ptr;
    TNodo* ptrAnt = NULL;
    if (lis == NULL) {
        return 0;
    }
    ptr = lis->inicio;

    while (ptr != NULL) {
        if (ptr->info == elementoPesq) {
            if (ptr == lis->inicio) {
                lis->inicio = lis->inicio->next;
            } else if (lis->fim == ptr) {
                lis->fim = ptrAnt;
                ptrAnt->next = NULL;
            } else {
                ptrAnt->next = ptr->next;
            }
            *elemento = ptr->info;
            free(ptr);
            lis->tamanho--;
            return 1;
        } else {
            ptrAnt = ptr;
            ptr = ptr->next;
        }
    }
    return 0;
}

// Inverte a ordem da cadeia, apenas mexendo nos ponteiros
void funcInvert(lista lis) {
    if (lis == NULL || lis->inicio == NULL || lis->inicio->next == NULL) {
        return;
    }

    TNodo* prev = NULL;
    TNodo* current = lis->inicio;
    TNodo* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    lis->inicio = prev;
}

// Função para Ordenar se a lista está ordenada
void funcSelectionSort(lista lis) {
    if (lis == NULL || lis->inicio == NULL || lis->inicio->next == NULL) {
        // Lista vazia ou com apenas um elemento já está ordenada.
        return;
    }

    TNodo* i, *j, *minNode;
    TElemento temp;

    for (i = lis->inicio; i->next != NULL; i = i->next) {
        minNode = i;

        for (j = i->next; j != NULL; j = j->next) {
            if (j->info < minNode->info) {
                minNode = j;
            }
        }

        // Troca os elementos
        if (minNode != i) {
            temp = i->info;
            i->info = minNode->info;
            minNode->info = temp;
        }
    }
}

// Função para imprimir os elementos da lista
void funcSaidaDados(lista lis) {
    TNodo* ptr = lis->inicio;

    while (ptr != NULL) {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    lista lis = funcCriarLista(); // Cria a lista

    if (lis != NULL) { // Verifica se a lista foi criada com sucesso
        TElemento elementos;
        int i;

        // Cria e imprime a lista de elementos
        for (i = 0; i <= 5; i++) {
            elementos = i;
            printf("%d\t", elementos);
            funcInsereFinal(lis, elementos);
        }
        printf("\n");

        // Inverte a lista
        funcInvert(lis);

        // Imprime a lista invertida
        funcSaidaDados(lis);

        // Ordena a lista usando o Selection Sort
        funcSelectionSort(lis);

        // Imprime a lista ordenada
        funcSaidaDados(lis);

        // Libera a memória alocada para a lista
        funcDestroy(lis);

    } else {
        printf("Falha ao criar a lista.\n");
    }

    return 0;
}
