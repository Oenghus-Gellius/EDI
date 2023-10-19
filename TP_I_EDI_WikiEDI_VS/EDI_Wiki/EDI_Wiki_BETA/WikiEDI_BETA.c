#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
#define MAX_VARIEVEIS 4

//--------------------------------------funções auxiliares de Alocação Pagina----------------------

TPagina* bormPage()
{
    TPagina* page = (TPagina*)malloc(sizeof(TPagina));
    if (page != NULL)
    {
        page->inicio = NULL;
        page->fim = NULL;
        page->tamanho = 0;
        page->cursor = NULL;
        page->posicaoCorrente = 0;
    }
    return page;
}

int firstPage(TPagina* wikiPages)
{
    // fazer que a função fullPage retorne -1 se estiver cheia
    if (fullPage(wikiPages) == -1)
    {
        printf("\nErro na alocaçao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);//TA CERTO ISSO JOSE?
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na alocaçao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return 0;
    }
    else
    {
        ptrNodoPage->nextPage = wikiPages->inicio;
        wikiPages->inicio = ptrNodoPage;

        wikiPages->tamanho++;

        //verificando se é a primeira pagina
        if (wikiPages->tamanho == 1)
        {
            wikiPages->cursor = ptrNodoPage;
        }
        return 1;
    }
}

int lastPage(TPagina* wikiPages)
{
    // fazer que a função fullPage retorne -1 se estiver cheia
    if (fullPage(wikiPages) == -1)
    {
        printf("\nErro na alocaçao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na alocaçao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages); //TA CERTO ISSO JOSE?
        return 0;
    }
    else
    {
        ptrNodoPage->nextPage = NULL;

        if (wikiPages->inicio == NULL)
        {
            firstPage(wikiPages);
        }
        else
        {
            
            wikiPages->fim->nextPage = ptrNodoPage;
            wikiPages->fim = ptrNodoPage;
            wikiPages->tamanho++;
        }
        return 1;
    }
}

int emptyPage(TPagina* wikiPages)
{
    return !wikiPages->inicio;
}

int fullPage(TPagina* wikiPages)
{
    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage != NULL)
    {
        printf("\nErro na alocaçao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(ptrNodoPage);
        return 0;
    }
    return -1;
}

int quantityPages(TPagina* wikiPages)
{
    return wikiPages->tamanho;

}

//----------------------------------------FunÇões Auxiliares-----------------

//Funçao que retira o enter das strings
void retiraEnter(char* string) {
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}

void separarComandoEArquivo(char* entrada, char* comando, char* nomeArquivo) {
    int i, j = 0;

    // Inicializa as strings de comando e nome do arquivo
    comando[0] = '\0';
    nomeArquivo[0] = '\0';

    // Procura o primeiro espaço em branco na entrada
    for (i = 0; entrada[i] != ' ' && entrada[i] != '\0'; i++) {
        comando[i] = entrada[i];
    }
    comando[i] = '\0';

    // Se a entrada ainda contiver caracteres, copie o restante como nome do arquivo
    if (entrada[i] != '\0') {
        i++; // Pula o espaço em branco
        while (entrada[i] != '\0') {
            nomeArquivo[j] = entrada[i];
            i++;
            j++;
        }
        nomeArquivo[j] = '\0';
    }
}

void separarComandoE4Palavras(const char* entrada, char** comandosLinha) {
    int i = 0;
    char comando[ENTRADA_DADOS];
    int comando_len = 0;

    int k = 0;

    while (entrada[k] != '\0') {
        if (entrada[k] == ' ' || entrada[k] == '\n' || entrada[k] == '\r') {
            if (comando_len > 0) {
                if (i < MAX_VARIEVEIS) { // Verifique se i está dentro dos limites do vetor comandosLinha
                    strncpy_s(comandosLinha[i], ENTRADA_DADOS, entrada + k - comando_len, comando_len);
                    comandosLinha[i][comando_len] = '\0';
                }
                i++;
                comando_len = 0;
            }
        }
        else {
            comando_len++;
        }
        k++;
    }

    // Se houver menos de 4 palavras, inicialize as posições restantes do vetor de palavras
    if (comando_len > 0) {
        if (i < MAX_VARIEVEIS) {
            strncpy_s(comandosLinha[i], ENTRADA_DADOS, entrada + k - comando_len, comando_len);
            comandosLinha[i][comando_len] = '\0';
        }
    }

    //printf("\nEntrada:%s - Comando:%s - palavra1:%s - palavra2:%s - palavra3:%s - palavra4:%s - I'm at line %d\n", entrada, comando, comandosLinha[0], comandosLinha[1], comandosLinha[2], comandosLinha[3], __LINE__);
}

int openFileTester(char* nomeArquivo)
{
    FILE* arqTest;
    errno_t err = fopen_s(&arqTest, nomeArquivo, "r");
    if (err != 0) 
    {
        return -1;
    }
    return 0;
}

//REVER ESSA FUNÇÃO <-------------------------------
FILE* openFile(char* nomeArquivo)
{
    FILE* arqOpen;
    errno_t err = fopen_s(&arqOpen, nomeArquivo, "r+");

    if (err != 0) {
        printf("\nERRO AO ABRIR ARQUIVO!!!\n");
        return NULL;
    }
    return arqOpen;
}

int pesquisaFuncion(char* comando) //<------- PAREI AQUI
{
    char* vetorCommand[] = {"INSEREPAGINA","RETIRAPAGINA","INSEREEDITOR","INSERECONTRIBUICAO","RETIRACONTRIBUICAO","INSERELINK","RETIRALINK","CAMINHO","IMPRIMEPAGINA","IMPRIMEWIKED","FIM"};
    int TotalCommand = sizeof(vetorCommand) / sizeof(vetorCommand[0]);
    for (int index = 0; index < TotalCommand; index++)
    {
        if (strcmp(vetorCommand[index], comando) == 0)
        {
            return index + 1;
        }
    }
    return -1;
}

void executer(char* nomeArqTeste)
{
    FILE* arqOpen;
    char lineCommand[MAX_LINE_LENGTH];

    TPagina *wikiPages = bormPage();//Inicia virtualmente a wiki

    int numFuncion = 0;

    errno_t err = fopen_s(&arqOpen, nomeArqTeste, "r");

    if (arqOpen == NULL && err != 0) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArqTeste);
        return;
    }
    
    rewind(arqOpen);

    printf("\nIniciando a execução, Boa Jornada!!!!\n");

    char** comandosLinha = (char**)malloc(5 * sizeof(char*));

    for (int i = 0; i < MAX_VARIEVEIS; i++)
    {
        comandosLinha[i] = (char*)malloc(sizeof(ENTRADA_DADOS));
        // Lidar com a falha na alocação de memória, se necessário
        if (!comandosLinha[i]) {
            // Lidar com a falha na alocação de memória, se necessário
            for (int j = 0; j < i; j++) {
                free(comandosLinha[j]);
            }
            free(comandosLinha);
            // Encerrar ou retornar em caso de erro
        }
    }

    while (fgets(lineCommand, sizeof(lineCommand), arqOpen) != NULL)
    {
        char entrada[ENTRADA_DADOS];

        retiraEnter(lineCommand);

        // Inicialize o vetor de palavras
        for (int i = 0; i < MAX_VARIEVEIS; i++) {
            comandosLinha[i][0] = '\0';
        }

        // Copie a linha lida para a variável "entrada"
        strncpy_s(entrada, ENTRADA_DADOS, lineCommand, _TRUNCATE);

        separarComandoE4Palavras(entrada, comandosLinha);

        numFuncion = pesquisaFuncion(comandosLinha[0]); 

        switch (numFuncion)
        {
        case 1://INSEREPAGINA <nome_pagina><nome_arquivo> <------------PAREI AQUI
            int logReturn;



            printTESTE();
           
            break;
        default:
            printf("\nCOMANDO INEXISTENTE!!!\n");
            break;
        }
       
    }

}

void closeArq(FILE* nomeArq)
{
    fclose(nomeArq);
}

void printTESTE()
{
	printf("\nTESTE DESGRAÇA - I'm at line %d\n", __LINE__);
}

