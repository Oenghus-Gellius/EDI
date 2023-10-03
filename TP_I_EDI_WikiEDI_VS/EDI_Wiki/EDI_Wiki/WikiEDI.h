#ifndef WIKIEDI_H_INCLUDED
#define WIKIEDI_H_INCLUDED

#define MAX_TAM_STR 100


/*
Introdução.:


*/

//Estrutura de nodos para uma lista encadeada simples de conteudos colaborativos;
typedef struct NodoCont {
	unsigned int nColab;//numero de restreio do colabarador
	char nomeColab[MAX_TAM_STR];//nome do colaborador (nome unico) Fezer a verificação
	char contWikiColab[MAX_TAM_STR];//conteudo do colaborador
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
	char nomePage[MAX_TAM_STR];//nome da pagina da Wiki
	//char linkPages[MAX_TAM_STR];//links entre paginas se houver
	//TConteudo info;// Estrutura dentro de cada pagina para registrar colaborações
	struct Nodo* nextPage, * backPage;//Nova pagina ou proxina e pagina anterior
}TNodoPage;

typedef struct Pagina {
	int quantidade;//quantidade de paginas existentes
	int posicaoCorrente;//marca posição na de pagina
	char teste[MAX_TAM_STR];
	TNodoPage* inicio, * cursor;//Marca primeira pagina e a pagina atual;
}TPagina;

//Funções usadas na Wiki
// 
//FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS-----------------------

//cria uma pagina/arquivo <---Incompleta
void creatorFilePage(const char* nomePage);

//abre uma pagina existente <---
void openFilePage(const char* nomePage);

//ler o conteudo de um arquivo/pagina ja criado
void readFilePage(const char* nomePage);


//FUNÇÕES DE ALOCAÇÃO----------------------------------------------------------------

//Função para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
//NÂO SEI PQ NÂO PODE SER DIRETO EM POR NO FIM OU NO INICIO
TPagina* firstPageAlloc();

//Criar a primeira Pagina da lista;
int startPageAlloc(TPagina* page, TNodoPage* info);

//ciar a proxima pagina da lista duplamente encadeada
int headPageAlloc(TPagina* page);

//Função que retorna que nãotem pagina alocada
int noPageAlloc(TPagina* page, TNodoPage* info);

//Função com o objetivo de testar se ha espaço para a proxima pagina
int fullPageAlloc(TPagina* page);

//Função que retorna o tamanho/quantidade de Paginas na Wiki
int sizePageAlloc(TPagina* page);


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

