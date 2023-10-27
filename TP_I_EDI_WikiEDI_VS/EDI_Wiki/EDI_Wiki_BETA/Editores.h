#ifndef WIKIEDI_EDITORES_H_INCLUDED
#define WIKIEDI_EDITORES_H_INCLUDED

#include "Links.h"
#include "WikiEDI_BETA.h"
#include "testador.h"
#include "Log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------Lista de links

//Cria a primeira pagina para alocação = construtor
TEditores* bornListEditores();

//Criar a primeira Pagina da lista ou "posiciona" na primeira colocação
int firstEditores(TEditores* listColab, TNodoEditor infosEdit);

//ciar a proxima pagina da lista encadeada
int lastEditores(TEditores* listColab, TNodoEditor infosEdit);

int removeEditores(TEditores* listColab, char* nomeEditor, TNodoEditor* infosEdit);

// Pesquisa na lista de Links
int finderEditores(TEditores* listColab, char* nomeEditor, TInfoPage** infosEdit);

//Fun��o que retorna que n�otem pagina alocada
int emptyEditores(TEditores* listColab);

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullEditores(TEditores* listColab);

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int quantityEditores(TEditores* listColab);


//LISTA QUE ARMAZENA OS NOMES DOS COLABORADORES
int listaEditores(TNomeEditor** listaEditores, char* nomeEditor);

void destroyer(TEditores* listColab);
//destrutor (desaloca espaço na memoria


//------------------------------

#endif 