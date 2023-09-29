/*
5. Faça um programa que imite um editor de textos. Inicialmente você irá ler os dados digitados pelo
usuário (linhas de texto) e criar um vetor em memória onde serão armazenados os textos fornecidos
pelo usuário (texto de 1 até no máximo 50 linhas). O usuário vai escrever o seu texto, terminando por
uma linha onde ele irá escrever apenas a palavra ‘FIM’, o que determina que ele não deseja mais
digitar linhas de texto. Sendo assim, o texto final pode ter um número variável de linhas, entre 1 e 50.
Salvar o conteúdo armazenado na memória neste vetor, em um arquivo texto em disco. Sugestão: use o
comando “gets” ou “fgets” para ler as linhas de texto digitadas pelo usuário. 

Pretendo fazer da seguinte forma:
O texto que está sendo digitado va ser armazenado dinamicamente em um vetor, sendo um vetor para cada linha
e ao chegar a MAX_CATACTERS ele vai alocar a proxima linha até chegar a 50 linhas. Ai vamos alocar uma nova pagina
*/



//#ifndef QUEST5_PAGINA_LINHAS_H_INCLUDED
//#define QUEST5_PAGINA_LINHAS_H_INCLUDED

#define MAX_CARACTERS 1000
#define MAX_LINHA 50

//A alocação de de dados sera a pagina salva em uma lista encadeada dinamica
//Já as linhas serão armazenadas em um vetor dinamico
// Definição da estrutura Nodo
// A variavel linha na verdade é um ponteiro para as 50 linhas que serão geradas

//Struct para o vetor de linhas
typedef struct Linha{
    char* vetLinhas;
    int tamanho;//poderia ter um cursor pra linha
}TLinha;

//-------

//As duas structs abaixo são para as paginas e seus nodos
typedef struct Nodo{
    TLinha *linha[MAX_LINHA];
    struct Nodo *nextPag;
}TNodo;

//O objetivo dessa estrutura e simular uma folha, onde
typedef struct pagina{
    int nLinhas;
    int nPaginas;
    TNodo *inicio, *fim, *curso;
}Tpage;

Tpage* createPage();

Tpage *newPage(Tpage* page);

TLinha *vectorLines(Tpage *pageAtual);

int setCursor(Tpage *pagina, int indice);

void editorText();

void displayPages(Tpage *pageAtual);


//#endif QUEST5_PAGINAS_LINHAS_H_INCLUDED// QUEST5_H_INCLUDED