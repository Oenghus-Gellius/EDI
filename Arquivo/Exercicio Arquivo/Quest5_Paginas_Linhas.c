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

#include <stdio.h>
#include <stdlib.h>

#include "Quest5_Paginas_Linhas.h"

#define MAX_LINHA 50

//funçaõ para abrir aquivo para Ediçaõ
FILE* openArquivoEdition(const char* nomeArquivo){
    FILE* arquivo;

    arquivo = fopen(nomeArquivo, "r+");

    // Se o arquivo não existe, crie-o no modo leitura e escrita (w+)
    if (arquivo == NULL) {
        arquivo = fopen(nomeArquivo, "w+");
    }

    if (arquivo == NULL) {
        printf("\nFalha ao abrir o arquivo!\n");
    }
    return arquivo;
}

//funçaõ para abrir aquivo para leitura
FILE* openArquivoLeitura(const char* nomeArquivo){
    FILE* arquivo;

    arquivo = fopen(nomeArquivo, "r");

    // Se o arquivo não existe, crie-o no modo leitura e escrita (w+)
    if (arquivo == NULL) 
    {
        printf("\nFalha ao abrir o arquivo!\n");
    }
    return arquivo;
}

//alocando memoria para criar uma pagina usando lista encadeada Simples
Tpage* createPage(){
    Tpage* firstPage = (Tpage*)malloc(sizeof(Tpage));
    if (firstPage != NULL)
    {
        firstPage->nLinhas = 0;
        firstPage->nPaginas = 1;
        firstPage->inicio = NULL;
        firstPage->fim = NULL;
        firstPage->curso = NULL;
    }
    else
    {
        printf("\nFalha na alocação da pagina\n");
        return 0;
    }
    printf("\nPágina %d\n", firstPage->nPaginas);
    return firstPage;
}

// Função para criar uma nova página a partir da página atual
//incerindo no final da lista encadeada
Tpage *newPage(Tpage* page){
    TNodo* prtPageNodo = (TNodo*)malloc(sizeof(TNodo));
    if (prtPageNodo == NULL)
    {
        return 0;
    }
    else
    {
        prtPageNodo->nextPag = NULL;
        //Cria as linhas <===ATENÇÃO
        //se for a primeira pagina
        if (page->inicio == NULL)
        {
            page->inicio = prtPageNodo;
        }
        else
        {
            page->fim->nextPag = prtPageNodo;
        }
        page->fim = prtPageNodo;
        page->nPaginas++;
        return 1;        
    }
}

//Cria uma vetor dinamico para armazenar os caracteres
TNodo* newLine(Tpage *pageAtual){
    int capacidade = MAX_CARACTERS;
    TNodo *newLine;
    if (newLine == NULL)
    {
        printf("\nErro ao criar linha!!!\n");
        return 0;
    }
    else
    {
        newLine = (TNodo*)malloc(capacidade * sizeof(TNodo));
        pageAtual->nLinhas++;
        
    }
    return newLine;
}

//Função para receber o texto digitado e encaixar o texto nas linhas 
//Função para inserir o texto na pagina atual
void** editorText(){
    unsigned char *texto;
    Tpage *page;
    TNodo *line;

    page = createPage();
    if (page == NULL)
    {
        printf("\nErro ao abrir pagina no editor de texto\n");
        return 0;
    }
    else
    {

        while (texto != "FIM")
        {
            page


            

            //pegar o texto digitado e "encaixar" nas linhas e paginas
            printf("\nDigite uma linha de texto (ou 'FIM' para encerrar): \n");
            fgets(texto, sizeof(texto),stdin);
            setbuf(stdin,NULL);  

            while (/* condition */)
            {
                // Verificar se o usuário deseja encerrar
                if (strcmp(texto, "FIM\n" == 0))
                {
                    break;
                }
            }
            

                      
        }
        
        
    }
}
    

    





/*
void getline(Tpage* text){

}

void getFim(Tpage* text){

}


Tpage copyAllocForArq(Tpage* text, FILE* nomeArquivo){

}
*/

//criar uma função para testar o editor de texto


int main(){
    FILE* arqEditor;

    const char* nomeDoArquivo = "EditorTexto.txt";

    arqEditor = openArquivo();


    fclose(arqEditor);

    return 0;
    

}