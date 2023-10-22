#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int TChave;
typedef struct{
    TChave chave;
    //demais campos
}TElemento;

typedef struct Lista *lista;
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
int setCursor(lista l,int posicao);
int getCorrente(lista l, TElemento *e);
int listaVazia(lista l);
int listaCheia(lista l);
/*Um novo elemento é iserido na posicao indice(caso indice seja válido)
e inserePosicao retorna verdadeiro; caso contrário inserePosicao
retorna falso.
*/
int inserePosicao(lista l, TElemento e, int indice);

void imprime(lista l);
#endif // LISTA_H_INCLUDED