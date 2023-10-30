#ifndef WIKIEDI_EDITORES_H_INCLUDED
#define WIKIEDI_EDITORES_H_INCLUDED

#include "Links.h"
#include "WikiEDI_BETA.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------Lista de Colaborações

//Cria a primeira pagina para alocação = construtor
TEditores* bornListEditores();

//Criar a primeira Pagina da lista ou "posiciona" na primeira colocação
int firstEditores(TEditores* listColab, TConteudoEdit infosEdit);

//ciar a proxima pagina da lista encadeada
int lastEditores(TEditores* listColab, TConteudoEdit infosEdit);

int removeEditores(TEditores* listColab, char* nomeEditor, TConteudoEdit* infosEdit);

// Pesquisa na lista
int finderEditores(TEditores* listColab, char* nomeEditor, TConteudoEdit* infosEdit);

//Fun��o que retorna que n�otem pagina alocada
int emptyEditores(TEditores* listColab);

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullEditores(TEditores* listColab);

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int quantityEditores(TEditores* listColab);

void freeEditores(TEditores* listColab);


#endif
