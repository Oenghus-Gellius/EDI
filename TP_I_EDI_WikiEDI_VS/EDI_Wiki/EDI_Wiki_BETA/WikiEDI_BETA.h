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
#include <stdio.h>
#include <stdlib.h>

#define ENTRADA_DADOS 100

 //Estrutura de nodos para uma lista encadeada simples de conteudos colaborativos;
typedef struct NodoCont {
	unsigned int idColab;//numero de restreio do colabarador
	char* nomeColab;//nome do colaborador (nome unico) Fezer a verifica��o
	char* contWikiColab;//conteudo do colaborador
	unsigned int sizeofContColab;//contador de caracteres por texto do colaborador
	struct NodoCont* nextColab;//nova colabora��o 
}TNodoCont;

typedef struct Conteudo {
	int tamanhoColab;//ter o numero de colabora��es totais por pagina
	int posicaoCorrenteColab;//marcador da posi��o
	TNodoCont* inicioColab, * cursorColab, * fimColab;//busca colabarador especifico para manipular ssuas colabora��es
}TConteudo;

//----------------------------

typedef struct InfoPage {
	int idPage;
	char* nomePage;//nome da pagina da Wiki
	char* linkPages;//links entre paginas se houver
	TConteudo infoC;// Estrutura dentro de cada pagina para registrar colabora��es
}TInfoPage;

 //Estrutura de nodos para encadear as paginas. lista simples
typedef struct Nodo {
	TInfoPage infoP;
	struct Nodo* nextPage;//Nova pagina ou proxina e pagina anterior
}TNodoPage;

typedef struct Pagina {
	int tamanho;//quantidade de paginas existentes
	int posicaoCorrente;//marca posiçao na de pagina
	// char teste[MAX_TAM_STR];//TESTE PARA VER SE EST�O REALMENTE ESCREVENDO E CONECTANDO
	TNodoPage* inicio, * cursor, * fim;//Marca primeira pagina e a pagina atual;
}TPagina;

typedef struct Log {
	char* logMensagem;
}TLog;

 //--------------------------------------Comandos necessarios----------------------

/*INSEREPAGINA <nome_pagina><nome_arquivo> : 
 cria uma página WikEDI com o nome e o arquivo especificados(devem ser únicos).
 Não é necessário criar o  arquivo neste momento(isto será feito na	impressão da página).*/
int inserePage(const char* nomePagina, const char* nomeArquivo);

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
int finderPage(TPagina* wikiPages, char *nomePage, TInfoPage **infoEnter);

//Fun��o que retorna que n�otem pagina alocada
int emptyPage(TPagina* wikiPages);

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullPage(TPagina* wikiPages);

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int quantityPages(TPagina* wikiPages);

void endPage(TPagina* wikiPagina);
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

//Função serve para fechar os arquivos para evitar que os aquivis fiquem abertos sem motivo
void closeArq(FILE* nomeArq);

void printTESTE();
#endif // WIKIEDI_BETA_H_INCLUDED

//																./wikiedi TestOENGHUS.txt
//----------------------------------- FUNÇÕES MANUPULA ARQUIVO--------------------

/*Como saídas do trabalho, além dos arquivos com as páginas da WikiEDI, será pedido um arquivo de “log”
caminho para possíveis mensagens de erro e para informar se há caminho entre duas páginas (por meio de
links). No caso de mensagens de erro, por exemplo, se um editor tentar excluir uma contribuição que não
tenha sido inserida por ele/ela, uma mensagem de erro deve ser gerada (e.g.: erro: editor não tem direito de
excluir esta contribuição). Verificações similares devem ser feitas caso seja pedido para excluir uma página
inexistente, ou um editor inexistente, etc. No caso de saber se há caminho entre duas páginas, basta navegar
nas listas de links para determinar se há caminho, ou não entre as páginas. No exemplo da figura 1, há
caminhos das páginas da SO para as páginas de EDI e BD, mas não há caminho inverso.*/

//Essa função tem o objetivo de passar por parametro o nome do arquico a ser aberto
//e retornar um ponteiro tipo FILE
//FILE* openFile(char* nomeArquivo);


//Essa função tem o objetivo de abrir o log ao inicio do programa e resgistrar "todas as 
//manipulações do programa, fecha ao se fechar o programa salvado as alterações.
int logEdit(FILE* arqLog, char *logMensagem);