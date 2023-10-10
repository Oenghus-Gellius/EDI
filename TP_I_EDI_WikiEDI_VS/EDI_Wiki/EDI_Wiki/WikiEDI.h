#ifndef WIKIEDI_H_INCLUDED
#define WIKIEDI_H_INCLUDED

#define MAX_TAM_STR 100

/*
 ============================================================================
 Name        : WikiEDI
 Author      : Bolivar A. Dias Jr
 Version     : Version 1.1
 ============================================================================
 */




/*
Introdu��o.:

Ideias.:

Fazer um arquivo s� com o nome dos colaboradores
Fazer um arquivc com o log do que foi feito na Wiki
*/

//Estrutura para manipular os dados no Arquivo
typedef struct PageArq{
	char *nomePage;
	int codColab;
	int qtdColab;
	char *colabName;
	char *colabWiki;
	int qtdLinks;
	struct PageArq* links;
}TPageArq;


//Estrutura de nodos para uma lista encadeada simples de conteudos colaborativos;
typedef struct NodoCont {
	unsigned int idColab;//numero de restreio do colabarador
	char *nomeColab;//nome do colaborador (nome unico) Fezer a verifica��o
	char *contWikiColab;//conteudo do colaborador
	unsigned int sizeofContColab;//contador de caracteres por texto do colaborador
	//struct NodoCont* nextColab;//nova colabora��o 
}TNodoCont;

typedef struct Conteudo {
	int tamanhoColab;//ter o numero de colabora��es totais por pagina
	int posicaoCorrenteColab;//marcador da posi��o
	//TNodoCont* inicioColab, * cursorColab;//busca colabarador especifico para manipular ssuas colabora��es
}TConteudo;

//----------------------------

//Estrutura de nodos para encadear as paginas. Pretendo manter uma lista duplamente encadeada
typedef struct Nodo {
	int idPage;
	char *nomePage;//nome da pagina da Wiki
	//char *linkPages;//links entre paginas se houver
	TConteudo info;// Estrutura dentro de cada pagina para registrar colabora��es
	struct Nodo* nextPage;//Nova pagina ou proxina e pagina anterior
}TNodoPage;

typedef struct Pagina {
	int quantidade;//quantidade de paginas existentes
	int posicaoCorrente;//marca posi��o na de pagina
	// char teste[MAX_TAM_STR];//TESTE PARA VER SE EST�O REALMENTE ESCREVENDO E CONECTANDO
	TNodoPage* inicio, * cursor, *fim;//Marca primeira pagina e a pagina atual;
}TPagina;

//Estrutura para organizar o arquivo de log da wiki
typedef struct Log {
	const int codError;
	char* TipError;
}Tlog;

//Estrutura para organizar a lista de colaboradores
typedef struct ColabList {
	const int idColab;
	char* nameColab;
}TColabList;

//Fun��es usadas na Wiki
// 
//FUN��ES DE MANIPULA��O DE ARQUIVOS-----------------------

//cria uma pagina/arquivo 
void creatorFilePage(const char* nomePage, const char* colabName);

//abre uma pagina existente <---
void openFilePage(const char* nomePage);

//ler o conteudo de um arquivo/pagina ja criado
void readFilePage(const char* nomePage);

//Fun��o que criar/atualiza o ARQUIVO de log de altera��es  na Wiki<=====FAZER
void writeFilePage(FILE* arqPage, TPagina* pageUpdate, const char* colabName);

//Fun��o para manipular o arquivo de log
void openLogFile();



//FUN��ES DE ALOCA��O----------------------------------------------------------------

//Fun��o para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
//N�O SEI PQ N�O PODE SER DIRETO EM POR NO FIM OU NO INICIO
TPagina* bornPageAlloc();

//Criar a primeira Pagina da lista;
int startPageAlloc(TPagina* page, TNodoPage* info);

//ciar a proxima pagina da lista duplamente encadeada
int endPageAlloc(TPagina* page);

//Fun��o que retorna que n�otem pagina alocada
int noPageAlloc(TPagina* page, TNodoPage* info);

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullPageAlloc(TPagina* page);

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int sizePageAlloc(TPagina* page);

//Fun��o que atualiza atravez de memoria alocada o log de altera��es  na Wiki<=====FAZER

//FUN��ES "FUNCIONAIS"----------------

void menuApp1();

#endif // WIKIEDI_H_INCLUDED

/*  Metodologia
* Dessenvilvi minha logica estruturando os dados em dois grandes grupos, as paginas da Wiki e 
* o bloco das colabora��es e o objetivo � manipula-los em memoria alocada que vai ser carregada
* dos arquivos, apos o uso na memoria alocada, esses dados ser�o coiados/deletados do arquivo
* 
* Optei desde o inicio em trabalhar com as fun��es que manipulam arquivos;
* 
* Depois que criar as fun��es basicas para manipular aquivo, me debrucei nas fun��es para
* Alocar memoria e armazenar temporariamente os dados dos arquivos para atualiza��o e navega��o
*/

/* ARDUO CAMINHO AT� O FINAL
* Me deparia com a imensa dificuldade de manipular estruturas dentro de estruturas em arquivos
* 
* Tenho muita dificuldade em entender pq tem que ter uma fun��o para criar uma aloca��o de memoria
* se for a primeira, depois da primeira � s� acrecentar. Acho estranho rs
*/

