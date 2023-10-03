#ifndef WIKIEDI_H_INCLUDED
#define WIKIEDI_H_INCLUDED

#define MAX_TAM_STR 100


/*
Introdu��o.:


*/

//Estrutura de nodos para uma lista encadeada simples de conteudos colaborativos;
typedef struct NodoCont {
	unsigned int nColab;//numero de restreio do colabarador
	char nomeColab[MAX_TAM_STR];//nome do colaborador (nome unico) Fezer a verifica��o
	char contWikiColab[MAX_TAM_STR];//conteudo do colaborador
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
	char nomePage[MAX_TAM_STR];//nome da pagina da Wiki
	//char linkPages[MAX_TAM_STR];//links entre paginas se houver
	//TConteudo info;// Estrutura dentro de cada pagina para registrar colabora��es
	struct Nodo* nextPage, * backPage;//Nova pagina ou proxina e pagina anterior
}TNodoPage;

typedef struct Pagina {
	int quantidade;//quantidade de paginas existentes
	int posicaoCorrente;//marca posi��o na de pagina
	char teste[MAX_TAM_STR];
	TNodoPage* inicio, * cursor;//Marca primeira pagina e a pagina atual;
}TPagina;

//Fun��es usadas na Wiki
// 
//FUN��ES DE MANIPULA��O DE ARQUIVOS-----------------------

//cria uma pagina/arquivo <---Incompleta
void creatorFilePage(const char* nomePage);

//abre uma pagina existente <---
void openFilePage(const char* nomePage);

//ler o conteudo de um arquivo/pagina ja criado
void readFilePage(const char* nomePage);


//FUN��ES DE ALOCA��O----------------------------------------------------------------

//Fun��o para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
//N�O SEI PQ N�O PODE SER DIRETO EM POR NO FIM OU NO INICIO
TPagina* firstPageAlloc();

//Criar a primeira Pagina da lista;
int startPageAlloc(TPagina* page, TNodoPage* info);

//ciar a proxima pagina da lista duplamente encadeada
int headPageAlloc(TPagina* page);

//Fun��o que retorna que n�otem pagina alocada
int noPageAlloc(TPagina* page, TNodoPage* info);

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullPageAlloc(TPagina* page);

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int sizePageAlloc(TPagina* page);


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

