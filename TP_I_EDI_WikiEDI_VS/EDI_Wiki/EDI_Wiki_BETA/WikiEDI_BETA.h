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
 cria uma página WikEDI com o nome e o arquivo especificados(devem ser únicos).Não é necessário criar o 
 arquivo neste momento(isto será feito na	impressão da página).*/
int criapage(const char* nomePagina, const char* nomeArquivo);

/*RETIRAPAGINA <nome_pagina>: exclui a página da WikED!, excluindo, portanto, a lista de contribuições
e links. Não é necessário excluir os arquivos de contribuições (apenas os nós das listas).*/
int destroyerPage(const char* nomePagina);

/*INSEREEDITOR <nome_editor>: insere um editor com o nome especificado (deve ser único).*/
int insereEditor(const char* nomeEditor);

/*INSERECONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: insere uma contribuição de
um dado editor para uma determinada página. O trecho de texto deve estar editado no arquivo especificado.*/
int insereContribuicao(const char* nomePagina, const char* nomeEditor, const char* nomeArquivo);

/*RETIRACONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: retira uma dada
contribuição. Apenas o editor responsável pela contribuição pode retirá-la. O histórico da contribuição deve
continuar ativo.*/
int retiraContribuicao(const char* nomePagina, const char* nomeEditor, const char* nomeArquivo);

/*INSERELINK <pagina_origem><pagina_destino>: insere um link (nome do arquivo) para página destino,
na página origem.*/
int insereLink(const char* nomePaginaOrigem, const char* nomePaginaDestino);

/*RETIRALINK <pagina_origem><pagina_destino>: retira um link (nome do arquivo) da página origem
para uma página destino.*/
int retiraLink(const char* nomePaginaOrigem, const char* nomePaginaDestino);

/*CAMINHO <pagina_origem><pagina_destino>: verifica se há caminho entre duas páginas (por meio das
listas de links). Escreve no arquivo de log (HA/NAO HA CAMINHO DA <pagina_origem> PARA <pagina_destino>)*/
int caminhoLinks(const char* nomePaginaOrigem, const char* nomePaginaDestino);

/*IMPRIMEPAGINA <nome_pagina>: gera o arquivo e imprime as informações da página especificada.*/
void printPagina(const char* nomePagina);

/*IMPRIMEWIKED: gera os arquivos e imprime todas as informações das páginas da WikEDI, como
especificado acima.*/
void printWikiFull();

/*FIM: determina a finalização do programa. Toda a memória alocada deve ser liberada.*/
void DestroyerAlloc();


//----------------------------------------FunÇões Auxiliares-----------------
void retiraEnter(char* string);

void separarComandoEArquivo(const char* entrada, char* comando, char* nomeArquivo);







void printTESTE();
#endif // WIKIEDI_BETA_H_INCLUDED