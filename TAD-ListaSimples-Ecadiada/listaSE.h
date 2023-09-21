#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
typedef int TChave;
typedef struct{
    TChave chave;
    //demais campos
}TElemento;

typedef struct Nodo{
    TElemento info;
    struct Nodo *prox;
}TNodo;


typedef struct {
    TNodo *inicio,*fim,*cursor;
    int tamanho;
}TLista;

typedef TLista *lista;
int *p;
lista l;
/*Se a lista pode ser criada a mesma é vazia e
criaLista retorna a lista; caso contrário retorna NULL.
*/
lista criaLista();
/*A lista l deixa de existir*/
void terminaLista(lista l);
int insereInicio(lista l, TElemento e);
int insereFinal(lista l, TElemento e);
int getTamanho(lista l);

/*Retorna em *e o valor do elemento da posição indice e
getElemento retorna verdadeiro. Se indice for inválido
getElemento retorna falso

*/
int getElemento(lista l,TElemento *e, int indice);
int removeElemento(lista l,TChave ch,TElemento *e);
int buscaElemento(lista l,TChave ch, TElemento *e);

#endif // LISTA_H_INCLUDED