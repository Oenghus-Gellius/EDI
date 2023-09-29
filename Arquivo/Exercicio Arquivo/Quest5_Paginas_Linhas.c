#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Quest5_Paginas_Linhas.h"

/*
//funçaõ para abrir aquivo para Edição
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
*/
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
        page->fim = prtPageNodo;
        page->nPaginas++;

        //se for a primeira pagina
        if (page->inicio == NULL)
        {
            page->inicio = prtPageNodo;
        }
        return page;        
    }
}

//Cria uma vetor dinamico para armazenar os caracteres
TLinha *vectorLines(Tpage *pageAtual){
    TLinha *conjLine;

    int capacidade = MAX_CARACTERS;

    conjLine = (TLinha*)malloc(capacidade * sizeof(TLinha));

    if (conjLine == NULL)
    {
        printf("\nErro ao criar linha!!!\n");
        return 0;
    }
    else
    {
        pageAtual->nLinhas = 1;
        return conjLine;
    }
}

int setCursor(Tpage *pagina, int indice){
    int i;
    if (indice < 1 || indice > pagina->nPaginas)
    {
        return 0;
    }
    if (pagina->nPaginas == 1)
    {
        pagina->curso = pagina->inicio;
    }
    else
    {
        pagina->curso = pagina->inicio;

        for (i = 1; i < indice; i++)
        {
            if (pagina->curso == NULL)
            {
                return 0;
            }
            pagina->curso = pagina->curso->nextPag;
        }
    }
    return 1;
}

//Função para receber o texto digitado e encaixar o texto nas linhas 
//Função para inserir o texto na pagina atual
void editorText(){
    char texto[MAX_CARACTERS];
    int theEnd = 0;

    Tpage *ptrpage;
    TLinha *ptrLine = NULL;
    
    ptrpage = createPage();//cria página
    if (ptrpage == NULL)
    {
        printf("\nErro ao criar página no editor de texto\n");
        return;
    }
    else
    {
        ptrLine = vectorLines(ptrpage);//cria 50 linhas
        if (ptrLine == NULL)
        {
            printf("\nErro ao criar linhas no editor de texto\n");
            return;
        }
        else
        {
            printf("\nDigite uma linha de texto (ou 'FIM' para encerrar): \n");
      
            while (theEnd != 1)
            {
                // percorre uma página até a linha 50
                for (int i = 0; i < MAX_LINHA; i++)
                {
                    // pegar o texto digitado e "encaixar" nas linhas e páginas
                    fgets(texto, sizeof(texto), stdin);
                    
                    // Limpar o buffer de entrada após a leitura
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    // Verificar se o usuário deseja encerrar
                    if (strcmp(texto, "FIM\n") == 0)
                    {
                        theEnd = 1;
                        break;
                    } 

                    // Remover a quebra de linha do texto antes de armazená-lo
                    size_t len = strlen(texto);
                    if (len > 0 && texto[len - 1] == '\n') 
                    {
                        texto[len - 1] = '\0';
                    }
                    // Armazenar o texto na página atual e na linha atual
                    strcpy(ptrLine[i].vetLinhas, texto);
                    ptrpage->nLinhas++;
                }
                if (theEnd == 0)
                {
                    ptrpage = newPage(ptrpage);
                    ptrLine = vectorLines(ptrpage);
                }
            }
        }
    }
}


//O objetivo dessa função é imprimir na tela o texto salvo nas linhas e paginas
void displayPages(Tpage *pageAtual){
    int Numpage = 1;

    TNodo *pageCorrente;
    TLinha *ptrLinhaCorrent = NULL;
    
    pageCorrente = pageAtual->inicio;

    while (pageCorrente != NULL) {

        for (int i = 0; i < MAX_LINHA; i++)
        {
            ptrLinhaCorrent = pageCorrente->linha[i];

            if (ptrLinhaCorrent != NULL)
            {
                printf("%s\n",ptrLinhaCorrent->vetLinhas);
            }
        }
        pageCorrente = pageCorrente->nextPag;
        Numpage++;
    }
}
    
/*
Se der tempo fazer essa função
void getline(Tpage* text){

}


*/


int main(){
    Tpage *pageAtual;

    pageAtual = createPage();

    editorText();

    displayPages(pageAtual);

    return 0;
}