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
Introdução.:

Ideias.:

Fazer um arquivo só com o nome dos colaboradores
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
	char *nomeColab;//nome do colaborador (nome unico) Fezer a verificação
	char *contWikiColab;//conteudo do colaborador
	unsigned int sizeofContColab;//contador de caracteres por texto do colaborador
	//struct NodoCont* nextColab;//nova colaboração 
}TNodoCont;

typedef struct Conteudo {
	int tamanhoColab;//ter o numero de colaborações totais por pagina
	int posicaoCorrenteColab;//marcador da posição
	//TNodoCont* inicioColab, * cursorColab;//busca colabarador especifico para manipular ssuas colaborações
}TConteudo;

//----------------------------

//Estrutura de nodos para encadear as paginas. Pretendo manter uma lista duplamente encadeada
typedef struct Nodo {
	int idPage;
	char *nomePage;//nome da pagina da Wiki
	//char *linkPages;//links entre paginas se houver
	TConteudo info;// Estrutura dentro de cada pagina para registrar colaborações
	struct Nodo* nextPage;//Nova pagina ou proxina e pagina anterior
}TNodoPage;

typedef struct Pagina {
	int quantidade;//quantidade de paginas existentes
	int posicaoCorrente;//marca posição na de pagina
	// char teste[MAX_TAM_STR];//TESTE PARA VER SE ESTÂO REALMENTE ESCREVENDO E CONECTANDO
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

//Funções usadas na Wiki
// 
//FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS-----------------------

//cria uma pagina/arquivo 
void creatorFilePage(const char* nomePage, const char* colabName);

//abre uma pagina existente <---
void openFilePage(const char* nomePage);

//ler o conteudo de um arquivo/pagina ja criado
void readFilePage(const char* nomePage);

//Função que criar/atualiza o ARQUIVO de log de alterações  na Wiki<=====FAZER
void writeFilePage(FILE* arqPage, TPagina* pageUpdate, const char* colabName);

//Função para manipular o arquivo de log
void openLogFile();



//FUNÇÕES DE ALOCAÇÃO----------------------------------------------------------------

//Função para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
//NÂO SEI PQ NÂO PODE SER DIRETO EM POR NO FIM OU NO INICIO
TPagina* bornPageAlloc();

//Criar a primeira Pagina da lista;
int startPageAlloc(TPagina* page, TNodoPage* info);

//ciar a proxima pagina da lista duplamente encadeada
int endPageAlloc(TPagina* page);

//Função que retorna que nãotem pagina alocada
int noPageAlloc(TPagina* page, TNodoPage* info);

//Função com o objetivo de testar se ha espaço para a proxima pagina
int fullPageAlloc(TPagina* page);

//Função que retorna o tamanho/quantidade de Paginas na Wiki
int sizePageAlloc(TPagina* page);

//Função que atualiza atravez de memoria alocada o log de alterações  na Wiki<=====FAZER

//FUNÇÕES "FUNCIONAIS"----------------

void menuApp1();

#endif // WIKIEDI_H_INCLUDED

/*  Metodologia
* Dessenvilvi minha logica estruturando os dados em dois grandes grupos, as paginas da Wiki e 
* o bloco das colaborações e o objetivo é manipula-los em memoria alocada que vai ser carregada
* dos arquivos, apos o uso na memoria alocada, esses dados serão coiados/deletados do arquivo
* 
* Optei desde o inicio em trabalhar com as funções que manipulam arquivos;
* 
* Depois que criar as funções basicas para manipular aquivo, me debrucei nas funções para
* Alocar memoria e armazenar temporariamente os dados dos arquivos para atualização e navegação
*/

/* ARDUO CAMINHO ATÉ O FINAL
* Me deparia com a imensa dificuldade de manipular estruturas dentro de estruturas em arquivos
* 
* Tenho muita dificuldade em entender pq tem que ter uma função para criar uma alocação de memoria
* se for a primeira, depois da primeira é só acrecentar. Acho estranho rs
*/

