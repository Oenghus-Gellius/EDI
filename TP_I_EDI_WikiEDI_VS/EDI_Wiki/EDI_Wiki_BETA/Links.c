#include "Links.h"
#include "WikiEDI_BETA.h"
#include "testador.h"
//#include "Log.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//--------------------------------------fun��es auxiliares de Aloca��o Pagina----------------------

TListaLinks* bornListLinks()
{
    TListaLinks* listLinks = (TListaLinks*)malloc(sizeof(TListaLinks));
    if (listLinks != NULL)
    {
        listLinks->inicio = NULL;
        listLinks->fim = NULL;
        listLinks->tamanho = 0;
    }
    return listLinks;
}

firstLinks(TListaLinks* listaLinks, TLinksLista links)
{
    // fazer que a fun��o fullLinks retorne -1 se estiver cheia
    if (fullLinks(listaLinks) == -1)
    {
        printf("\nErro na alocacao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(listaLinks);
        return 0;
    }

    TNodoLink* ptrTNodoLinks = (TNodoLink*)malloc(sizeof(TNodoLink));
    if (ptrTNodoLinks == NULL)
    {
        printf("\nErro na alocao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return 0;
    }
    else
    {
        strncpy_s(ptrTNodoLinks->infoLink.linkOrigem, MAX_CHAR, links.linkOrigem, _TRUNCATE);
        strncpy_s(ptrTNodoLinks->infoLink.linkDestino, MAX_CHAR, links.linkDestino, _TRUNCATE);

        ptrTNodoLinks->nexNodo = NULL;
        listaLinks->inicio = ptrTNodoLinks;
        listaLinks->tamanho++;

        listaLinks->fim = ptrTNodoLinks;
        return 1;
    }
}

int lastLinks(TListaLinks* listaLinks, TLinksLista links)
{
    // fazer que a fun��o fullLinks retorne -1 se estiver cheia
    if (fullLinks(listaLinks) == -1)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(listaLinks);
        return 0;
    }

    TNodoLink* ptrTNodoLinks = (TNodoLink*)malloc(sizeof(TNodoLink));
    if (ptrTNodoLinks == NULL)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(listaLinks);
        return 0;
    }
    else
    {
        ptrTNodoLinks->nexNodo = NULL;

        //verificando se a lista está vazia
        if (listaLinks->inicio == NULL)
        {
            firstLinks(listaLinks, links);
            free(ptrTNodoLinks);
        }
        else
        {
            strncpy_s(ptrTNodoLinks->infoLink.linkOrigem, MAX_CHAR, links.linkOrigem, _TRUNCATE);
            strncpy_s(ptrTNodoLinks->infoLink.linkDestino, MAX_CHAR, links.linkDestino, _TRUNCATE);

            listaLinks->fim->nexNodo = ptrTNodoLinks;
            listaLinks->fim = ptrTNodoLinks;
            listaLinks->tamanho++;
        }
        return 1;
    }
}

int removeLinks(TListaLinks* listaLinks, char* nomeLink, TLinksLista* links)
{
    TNodoLink* ptrTNodoLinks, * ptrBackLinks;
    ptrTNodoLinks = listaLinks->inicio;
    ptrBackLinks = NULL;

    while (listaLinks != NULL)
    {
        if (strcmp(ptrTNodoLinks->infoLink.linkOrigem, nomeLink) == 0)
        {
            //Verifica se � o primeiro
            if (ptrTNodoLinks == listaLinks->inicio)
            {
                listaLinks->inicio = listaLinks->inicio->nexNodo;
            }
            else
                if (ptrTNodoLinks == listaLinks->fim)//remove o ultimo
                {
                    listaLinks->fim = ptrBackLinks;
                    listaLinks->fim->nexNodo = NULL;
                }
                else
                {
                    ptrBackLinks->nexNodo = ptrTNodoLinks->nexNodo;
                }
            listaLinks->tamanho--;
            return 1;
        }
        else
        {
            ptrBackLinks = ptrTNodoLinks;
            ptrTNodoLinks = ptrTNodoLinks->nexNodo;
        }
    }
    return 0;
}

int finderLinksOrig(TListaLinks* listaLinks, char* nomeLink, TLinksLista** links)
{
    TNodoLink* ptrTNodoLinks;
    ptrTNodoLinks = listaLinks->inicio;

    while (ptrTNodoLinks != NULL)
    {
        if (strcmp(ptrTNodoLinks->infoLink.linkOrigem, nomeLink) == 0)
        {
            //links = ptrTLinks->infoP.nomePage;
            //TListaLinks->cursor = ptrTLinks;//QUERO USARO CURSOR PARA TER O ENDEREÇO PESQUISARO PARA EDITAR A PAGINA
            return 1;
        }
        ptrTNodoLinks = ptrTNodoLinks->nexNodo;
    }
    return 0;
}

int finderLinksDest(TListaLinks* listaLinks, char* nomeLink, TLinksLista** links)
{
    TNodoLink* ptrTNodoLinks;
    ptrTNodoLinks = listaLinks->inicio;

    while (ptrTNodoLinks != NULL)
    {
        if (strcmp(ptrTNodoLinks->infoLink.linkDestino, nomeLink) == 0)
        {
            //links = ptrTLinks->infoP.nomePage;
            //TListaLinks->cursor = ptrTLinks;//QUERO USARO CURSOR PARA TER O ENDEREÇO PESQUISARO PARA EDITAR A PAGINA
            return 1;
        }
        ptrTNodoLinks = ptrTNodoLinks->nexNodo;
    }
    return 0;
}

int emptyLinks(TListaLinks* TListaLinks)
{
    return !TListaLinks->inicio;
}

int fullLinks(TListaLinks* TListaLinks)
{
    TNodoLink* ptrTNodoLinks = (TNodoLink*)malloc(sizeof(TNodoLink));
    if (ptrTNodoLinks == NULL)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return -1;
    }
    free(ptrTNodoLinks);
    return 0;
}

int quantityLinks(TListaLinks* TListaLinks)
{
    return TListaLinks->tamanho;

}

//----------------------------------------Fun��es Auxiliares-----------------


int insereLink(TListaLinks* wikiOrigem, TListaLinks* wikiDestino)
{
	TNodoLink* ptrOrigem = wikiOrigem;
	TNodoLink* ptrDestino = wikiDestino;
	strncpy_s(ptrOrigem->infoLink.linkOrigem, MAX_CHAR, ptrDestino->infoLink.linkOrigem, _TRUNCATE);
	return 1;
}

int retiraLink(TListaLinks* wikiOrigem, TListaLinks* wikiDestino)
{
    TNodoLink* ptrOrigem = wikiOrigem;
    TNodoLink* ptrDestino = wikiDestino;

	int finder = 0;
	finder = finderLink(ptrOrigem,ptrDestino);
	if (finder == 1)//link encontrado
	{
		//REMOVER O LINK DA PAGInAdd
	}
	else//link não encontrado
	{
		return 0;
	}
	return 1;
}

int finderLink(TListaLinks* wikiOrigem, TListaLinks* wikiDestino)
{
    TNodoLink* ptrOrigem = wikiOrigem;
    TNodoLink* ptrDestino = wikiDestino;

	//Encontrou o link
	if (strcmp(ptrOrigem->infoLink.linkOrigem, ptrDestino->infoLink.linkOrigem) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int haCaminhoLinks(TListaLinks* listLinks, TListaLinks* wikiOrigem, TListaLinks* wikiDestino)
{
	TListaLinks* ptrlistLinks = listLinks; //<----FAZER
	return 0;
}

