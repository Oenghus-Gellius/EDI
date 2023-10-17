#ifndef WIKIEDI_BETA_H_INCLUDED
#define WIKIEDI_BETA_H_INCLUDED

/*
 ============================================================================
 Name        : WikiEDI
 Author      : Bolivar A. Dias Jr
 Version     : Version 2.0

 https://github.com/Oenghus-Gellius/EDI/tree/main/TP_I_EDI_WikiEDI_VS/EDI_Wiki
 ============================================================================
 */
#include "testador.h"

//Comandos necessarios.:

/*INSEREPAGINA <nome_pagina><nome_arquivo> : 
 cria uma p�gina WikEDI com o nome e o arquivo especificados(devem ser �nicos).N�o � necess�rio criar o 
 arquivo neste momento(isto ser� feito na	impress�o da p�gina).*/
int criapage(const char* nomePagina, const char* nomeArquivo);

/*RETIRAPAGINA <nome_pagina>: exclui a p�gina da WikED!, excluindo, portanto, a lista de contribui��es
e links. N�o � necess�rio excluir os arquivos de contribui��es (apenas os n�s das listas).*/
int destroyerPage(const char* nomePagina);

/*INSEREEDITOR <nome_editor>: insere um editor com o nome especificado (deve ser �nico).*/
int insereEditor(const char* nomeEditor);

/*INSERECONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: insere uma contribui��o de
um dado editor para uma determinada p�gina. O trecho de texto deve estar editado no arquivo especificado.*/
int insereContribuicao(const char* nomePagina, const char* nomeEditor, const char* nomeArquivo);

/*RETIRACONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: retira uma dada
contribui��o. Apenas o editor respons�vel pela contribui��o pode retir�-la. O hist�rico da contribui��o deve
continuar ativo.*/
int retiraContribuicao(const char* nomePagina, const char* nomeEditor, const char* nomeArquivo);

/*INSERELINK <pagina_origem><pagina_destino>: insere um link (nome do arquivo) para p�gina destino,
na p�gina origem.*/
int insereLink(const char* nomePaginaOrigem, const char* nomePaginaDestino);

/*RETIRALINK <pagina_origem><pagina_destino>: retira um link (nome do arquivo) da p�gina origem
para uma p�gina destino.*/
int retiraLink(const char* nomePaginaOrigem, const char* nomePaginaDestino);

/*CAMINHO <pagina_origem><pagina_destino>: verifica se h� caminho entre duas p�ginas (por meio das
listas de links). Escreve no arquivo de log (HA/NAO HA CAMINHO DA <pagina_origem> PARA <pagina_destino>)*/
int caminhoLinks(const char* nomePaginaOrigem, const char* nomePaginaDestino);

/*IMPRIMEPAGINA <nome_pagina>: gera o arquivo e imprime as informa��es da p�gina especificada.*/
void printPagina(const char* nomePagina);

/*IMPRIMEWIKED: gera os arquivos e imprime todas as informa��es das p�ginas da WikEDI, como
especificado acima.*/
void printWikiFull();

/*FIM: determina a finaliza��o do programa. Toda a mem�ria alocada deve ser liberada.*/
void DestroyerAlloc();


//----------------------------------------Fun��es Auxiliares-----------------
void retiraEnter(char* string);

void separarComandoEArquivo(const char* entrada, char* comando, char* nomeArquivo);







void printTESTE();
#endif // WIKIEDI_BETA_H_INCLUDED