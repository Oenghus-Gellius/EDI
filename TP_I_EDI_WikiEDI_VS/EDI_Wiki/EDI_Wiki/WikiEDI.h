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
	//TConteudo insidePage;// Estrutura dentro de cada pagina para registrar colaborações
	//struct Nodo* nextPage, * backPage;//Nova pagina ou proxina e pagina anterior
}TNodoPage;

typedef struct Pagina {
	int quantidade;//quantidade de paginas existentes
	int posicaoCorrente;//marca posição na de pagina
	char teste[MAX_TAM_STR];
	//TNodoPage* inicio, * cursor;//Marca primeira pagina e a pagina atual;
}TPagina;

//Funções usadas na Wiki
// 
//FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS-----------------------

//cria uma pagina (se for um colaborador)
void creatorPage(const char* nomePage);

//FUNÇÕES "FUNCIONAIS"----------------



#endif // WIKIEDI_H_INCLUDED

/*  Metodologia
* Optei desde o inicio em trabalhar com as funções que manipulam arquivos
* 
*/

/* ARDUO CAMINHO ATÉ O FINAL
* Me deparia com a imensa dificuldade de manipular estruturas dentro de estruturas em arquivos
*/

