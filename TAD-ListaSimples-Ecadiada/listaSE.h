#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED
typedef int TChave;
typedef struct{
    TChave chave;
    //demais componentes
}TElemento;


typedef struct TLista *lista;

lista criaLista();
void terminaLista(lista l);
int pesquisaLista(lista l,TChave ch,TElemento *e);
int insereFinal(lista l,TElemento e);
int getElemento(lista l, int posicao, TElemento *e);//
int removeElemento(lista l,TChave ch,TElemento *e);
int listaVazia(lista l);
int listaCheia(lista l);
int tamanhoLista(lista l);
int insereInicio(lista l, TElemento e);
int inserePosicao(lista l, TElemento e, int indice);
int setCorrente(lista l, int posicao);
int getCorrente(lista l,TElemento *e);

#endif LISTASE_H_INCLUDED