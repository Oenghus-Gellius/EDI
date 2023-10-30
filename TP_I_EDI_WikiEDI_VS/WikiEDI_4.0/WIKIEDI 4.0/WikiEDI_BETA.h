#ifndef WIKIEDI_BETA_H_INCLUDED
#define WIKIEDI_BETA_H_INCLUDED

/*
 ============================================================================
 Name        : WikiEDI
 Author      : Bolivar A. Dias Jr
 Version     : Version 3.0

 https://github.com/Oenghus-Gellius/EDI/tree/main/TP_I_EDI_WikiEDI_VS/EDI_Wiki
 ============================================================================
 */

#include "wikiedi.h"


#include "Links.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

//----------------------------
//Dados da pagina

//Infor colaboradores

typedef char TColaboracion[MAX_CHAR];

/*
typedef struct Links {
	char linkOrigem[MAX_CHAR];
	char linkDestino[MAX_CHAR];
}TLinks;*/

typedef char TNomeEditor[MAX_CHAR];

typedef struct ConteudoEdit {
	char nomePage[MAX_CHAR];
	TNomeEditor nomeEditor;
	TColaboracion colab;//Endereço do texto colaborativo
}TConteudoEdit;

typedef struct NodoEditor {
	TConteudoEdit infoEdit;
	struct NodoEditor* nextEditor;
}TNodoEditor;

typedef struct Editores {
	int tamanho;
	TNodoEditor* inicio, *fim;
}TEditores;

typedef struct InfoPage {
	char nomePage[MAX_CHAR];//nome da pagina da Wiki
	char nomeArqPage[MAX_CHAR];
	//TLinks linkPages;//links entre paginas se houver
}TInfoPage;

 //Estrutura de nodos para encadear as paginas. lista simples
typedef struct Nodo {
	TInfoPage infoP;
	struct Nodo* nextPage;//Nova pagina ou proxina e pagina anterior
}TNodoPage;

typedef struct Pagina {
	int tamanho;//quantidade de paginas existentes
	int posicaoCorrente;//marca posiçao na de pagina
	TNodoPage* inicio, * fim, *cursor;//Marca primeira pagina e a pagina atual;
}TPagina;

							//						./wikiedi TestOENGHUS.txt

//--------------------------------------funções auxiliares de Alocação Pagina----------------------

//Cria a primeira pagina para alocação = construtor
TPagina* bornPage();

//Criar a primeira Pagina da lista ou "posiciona" na primeira colocação
int firstPage(TPagina* wikiPages, TInfoPage infoEnter);

//ciar a proxima pagina da lista encadeada
int lastPage(TPagina* wikiPages, TInfoPage infoEnter);

int removePage(TPagina* wikiPages, char *nomePage, TInfoPage *infoEnter);

// PS. Ver se tem pagina repetida retorna 1 se for igual
int finderPage(TPagina* wikiPages, char *nomePage, TInfoPage *infoEnter);

//Fun��o que retorna que n�otem pagina alocada
int emptyPage(TPagina* wikiPages);

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullPage(TPagina* wikiPages);

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int quantityPages(TPagina* wikiPages);

void freeEditors(TEditores* listaEditores);
//destrutor (desaloca espaço na memoria


								//						./wikiedi TestOENGHUS.txt
//----------------------------------------FunÇões Auxiliares-----------------

void retiraEnter(char* string);

//Separar as palavras/comandos de uma string, recebe a stringFull e os ponterios para guardar
//as palavras separadas para serem usandas pelo programa.
void separarComandoEArquivo(char* entrada, char* comando, char* nomeArquivo);

//Separar as palavras/comandos de uma string, recebe a stringFull e os ponterios para guardar
//as palavras separadas para serem usandas pelo programa.
void separarComandoE4Palavras(const char* entrada, char** palavras);

//Função que vai abrir o arquivo teste para leitura
int openFileTester(char* nomeArquivo);

//Pesquiva função e retorna a posição da função no vetor de funções
//lembrando que a primeira função recebe(index +1) pois estou salvando o 0 para um qualquer
//questão de pesquisa no futuro, sonto que vou precisar.
int pesquisaFuncion(char* comando);

//-------------------------------------------EXECUTER-----------------------
//Função recebe o comando, pesquisar se é valido
// e executar o comando se for valido;
void executer(char* nomeArqTeste);

void printPageWikiArq(TPagina *wikiPages, TEditores* listColab);

//Função serve para fechar os arquivos para evitar que os aquivis fiquem abertos sem motivo
void closeArq(FILE* nomeArq);

#endif // WIKIEDI_BETA_H_INCLUDED

//																./wikiedi TestOENGHUS.txt
//----------------------------------- FUNÇÕES MANUPULA ARQUIVO--------------------
