#include "Links.h"
#include "WikiEDI_BETA.h"
#include "testador.h"
#include "Log.h"

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

int firstLinks(TListaLinks* TListaLinks, TLinks links)
{
    // fazer que a fun��o fullLinks retorne -1 se estiver cheia
    if (fullLinks(TListaLinks) == -1)
    {
        printf("\nErro na alocacao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(TListaLinks);
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
        TListaLinks->inicio = ptrTNodoLinks;
        TListaLinks->tamanho++;

        TListaLinks->fim = ptrTNodoLinks;
        return 1;
    }
}

int lastLinks(TListaLinks* TListaLinks, TLinks links)
{
    // fazer que a fun��o fullLinks retorne -1 se estiver cheia
    if (fullLinks(TListaLinks) == -1)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(TListaLinks);
        return 0;
    }

    TNodoLink* ptrTNodoLinks = (TNodoLink*)malloc(sizeof(TNodoLink));
    if (ptrTNodoLinks == NULL)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(TListaLinks);
        return 0;
    }
    else
    {
        ptrTNodoLinks->nexNodo = NULL;

        //verificando se a lista está vazia
        if (TListaLinks->inicio == NULL)
        {
            firstLinks(TListaLinks, links);
            free(ptrTNodoLinks);
        }
        else
        {
            strncpy_s(ptrTNodoLinks->infoLink.linkOrigem, MAX_CHAR, links.linkOrigem, _TRUNCATE);
            strncpy_s(ptrTNodoLinks->infoLink.linkDestino, MAX_CHAR, links.linkDestino, _TRUNCATE);

            TListaLinks->fim->nexNodo = ptrTNodoLinks;
            TListaLinks->fim = ptrTNodoLinks;
            TListaLinks->tamanho++;
        }
        return 1;
    }
}

int removeLinks(TListaLinks* TListaLinks, char* nomePage, TLinks* links)
{
    TNodoLink* ptrTNodoLinks, * ptrBackLinks;
    ptrTNodoLinks = TListaLinks->inicio;
    ptrBackLinks = NULL;

    while (TListaLinks != NULL)
    {
        if (strcmp(ptrTNodoLinks->infoLink.linkOrigem, nomePage) == 0)
        {
            //Verifica se � o primeiro
            if (ptrTNodoLinks == TListaLinks->inicio)
            {
                TListaLinks->inicio = TListaLinks->inicio->nexNodo;
            }
            else
                if (ptrTNodoLinks == TListaLinks->fim)//remove o ultimo
                {
                    TListaLinks->fim = ptrBackLinks;
                    TListaLinks->fim->nexNodo = NULL;
                }
                else
                {
                    ptrBackLinks->nexNodo = ptrTNodoLinks->nexNodo;
                }
            TListaLinks->tamanho--;
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

int finderLinks(TListaLinks* TListaLinks, char* nomePage, TInfoPage** links)
{
    TNodoLink* ptrTNodoLinks;
    ptrTNodoLinks = TListaLinks->inicio;

    while (ptrTNodoLinks != NULL)
    {
        if (strcmp(ptrTNodoLinks->infoLink.linkOrigem, nomePage) == 0)
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
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
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
		//REMOVER O LINK DA PAGInA
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

