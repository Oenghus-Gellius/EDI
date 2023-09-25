/*
O printeiro aponta ára o primeiro nodo da lista e o fim para o ultimo. 
O campo proximo do ultimo nodo aponta para NUll. Caso a lista esteja vazia inicio aponta para NULL.
Escreva uma função int moveMenor(lista 1) que, dada uma lista com um numeto qualquer de elementos,
acha o menor elemento da lista e o move para o começo da lista.

Obs. Não vale trocar apenas os campos info ou usar uma lista / fila/ pilha auxiliar! Voce deverá fazer
a manipulação de apontadores para trocar as celulas de posição. A lista deve ser percorrida uma unica vez.
*/

typedef struct Nodo{
    int info;
    struct Nodo *next;  
}TNodo;

typedef struct{
    TNodo *inicio, *fim;
    int tamanho;
}TLista;

typedef TLista *lista;

