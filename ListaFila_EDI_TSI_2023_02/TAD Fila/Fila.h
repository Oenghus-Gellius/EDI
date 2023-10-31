#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave chave;
    //demais componentes
}TElemento;

typedef struct NodoFila {
    TElemento info;
    struct Nodo* prox;
}TNodoFila;

typedef struct Lista {
    TNodoFila* inicio, * fim, * corrente;
    int tamanho;
}TLista;


#endif //FILA_H_INCLUDED