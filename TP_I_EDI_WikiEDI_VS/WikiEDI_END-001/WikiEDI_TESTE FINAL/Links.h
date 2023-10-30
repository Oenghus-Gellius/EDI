#ifndef WIKIEDI_LINKS_H_INCLUDED
#define WIKIEDI_LINKS_H_INCLUDED

#include "wikiedi.h"
#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 100

//Dados da pagina 
typedef struct LinksLista {
	char linkOrigem[MAX_CHAR];//Pagina a ser prcurada
	char linkDestino[MAX_CHAR];
}TLinksLista;

typedef struct NodoLink {
	TLinksLista infoLink;
	struct NodoLink* nexNodo;
}TNodoLink;

typedef struct ListaLinks {
	int tamanho;
	TNodoLink* inicio, * fim;
}TListaLinks;


//---------------------Lista de links
//Cria a primeira pagina para alocação = construtor
TListaLinks* bornListLinks();

//Criar a primeira Pagina da lista ou "posiciona" na primeira colocação
int firstLinks(TListaLinks* listaLinks, TLinksLista links);

//ciar a proxima pagina da lista encadeada
int lastLinks(TListaLinks* listaLinks, TLinksLista links);

int removeLinks(TListaLinks* listaLinks, char* nomeLink, TLinksLista* links);

// Pesquisa na lista de Links
int finderLinksOrig(TListaLinks* listaLinks, char* nomeLink, TLinksLista* links);

// Pesquisa na lista de Links
int finderLinksDest(TListaLinks* listaLinks, char* nomeLink, TLinksLista* links);

//Fun��o que retorna que n�otem pagina alocada
int emptyLinks(TListaLinks* listaLinks);

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullLinks(TListaLinks* listaLinks);

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int quantityLinks(TListaLinks* listaLinks);

void freeLinks(TListaLinks* listaLinks);

// 
//------------------------------

//Inseri link na pagina do wiki
int insereLink(TListaLinks* wikiOrigem, TListaLinks* wikiDestino);
	
int retiraLink(TListaLinks* wikiOrigem, TListaLinks* wikiDestino);

int finderLink(TListaLinks* wikiOrigem, TListaLinks* wikiDestino);

int haCaminhoLinks(TListaLinks* listLinks, TListaLinks* wikiOrigem, TListaLinks* wikiDestino);


#endif 
