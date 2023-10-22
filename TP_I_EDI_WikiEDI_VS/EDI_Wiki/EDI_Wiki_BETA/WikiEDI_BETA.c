#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
#define MAX_VARIEVEIS 4

//--------------------------------------fun��es auxiliares de Aloca��o Pagina----------------------

// Fun��o para inicializar uma estrutura TInfoPage
TInfoPage bornInfoPage() {
    TInfoPage info;
    info.idPage = 0;
    info.nomePage = NULL; // Aloca e copia o nome
    info.linkPages = NULL; // Aloca e copia os links

    // Inicialize as informa��es do conte�do (tamanho, posi��o, ponteiros) como necess�rio
    info.infoC.tamanhoColab = 0;
    info.infoC.posicaoCorrenteColab = 0;
    info.infoC.inicioColab = NULL;
    info.infoC.cursorColab = NULL;
    info.infoC.fimColab = NULL;

    return info;
}

TPagina* bornPage()
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

int firstPage(TPagina* wikiPages, TInfoPage infoEnter)
{
    // fazer que a fun��o fullPage retorne -1 se estiver cheia
    if (fullPage(wikiPages) == -1)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);//TA CERTO ISSO JOSE?
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return 0;
    }
    else
    {
        ptrNodoPage->infoP.nomePage = infoEnter.nomePage;
        ptrNodoPage->nextPage = wikiPages->inicio;
        wikiPages->inicio = ptrNodoPage;

        wikiPages->tamanho++;

        //verificando se � a primeira pagina
        if (wikiPages->tamanho == 1)
        {
            wikiPages->cursor = ptrNodoPage;
        }
        return 1;
    }
}

int lastPage(TPagina* wikiPages, TInfoPage infoEnter)
{
    // fazer que a fun��o fullPage retorne -1 se estiver cheia
    if (fullPage(wikiPages) == -1)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages); //TA CERTO ISSO JOSE?
        return 0;
    }
    else
    {
        ptrNodoPage->nextPage = NULL;

        if (wikiPages->inicio == NULL)
        {
            firstPage(wikiPages, infoEnter);
        }
        else
        {
            strncpy_s(ptrNodoPage->infoP.nomePage, ENTRADA_DADOS, infoEnter.nomePage, _TRUNCATE);
            //ptrNodoPage->infoP.nomePage = infoEnter.nomePage;
            wikiPages->fim->nextPage = ptrNodoPage;
            wikiPages->fim = ptrNodoPage;
            wikiPages->tamanho++;
        }
        return 1;
    }
}

int removePage(TPagina* wikiPages, char* nomePage, TInfoPage* infoEnter)
{
    TNodoPage* ptrNodoPage, * ptrBackNodePage;
    ptrNodoPage = wikiPages->inicio;
    ptrBackNodePage = NULL;

    while (wikiPages != NULL)
    {
        if (strcmp(ptrNodoPage->infoP.nomePage, nomePage) == 0)
        {
            //Verifica se � o primeiro
            if (ptrNodoPage == wikiPages->inicio)
            {
                wikiPages->inicio = wikiPages->inicio->nextPage;
            }
            else
                if (ptrNodoPage == wikiPages->fim)//remove o ultimo
                {
                    wikiPages->fim = ptrBackNodePage;
                    wikiPages->fim->nextPage = NULL;
                }
                else
                {
                    ptrBackNodePage->nextPage = ptrNodoPage->nextPage;
                }
            *infoEnter->nomePage = ptrNodoPage->infoP.nomePage;
            free(ptrNodoPage);
            wikiPages->tamanho--;
            return 1;
        }
        else
        {
            ptrBackNodePage = ptrNodoPage;
            ptrNodoPage = ptrNodoPage->nextPage;
        }
    }
    return 0;
}

int finderPage(TPagina* wikiPages, char* nomePage, TInfoPage** infoEnter)
{
    TNodoPage* ptrNodoPage;

    ptrNodoPage = wikiPages->inicio;

    while (ptrNodoPage != NULL)
    {
        if (strcmp(ptrNodoPage->infoP.nomePage, nomePage) == 0)
        {
            infoEnter = ptrNodoPage->infoP.nomePage;
            return 1;
        }
        ptrNodoPage = ptrNodoPage->nextPage;
    }
    return 0;
}

int emptyPage(TPagina* wikiPages)
{
    return !wikiPages->inicio;
}

int fullPage(TPagina* wikiPages)
{
    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return -1;
    }
    free(ptrNodoPage);
    return 0;
}

int quantityPages(TPagina* wikiPages)
{
    return wikiPages->tamanho;

}

//----------------------------------------Fun��es Auxiliares-----------------

//Fun�ao que retira o enter das strings
void retiraEnter(char* string) {
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}

void separarComandoEArquivo(char* entrada, char* comando, char* nomeArquivo) {
    int i, j = 0;

    // Inicializa as strings de comando e nome do arquivo
    comando[0] = '\0';
    nomeArquivo[0] = '\0';

    // Procura o primeiro espa�o em branco na entrada
    for (i = 0; entrada[i] != ' ' && entrada[i] != '\0'; i++) {
        comando[i] = entrada[i];
    }
    comando[i] = '\0';

    // Se a entrada ainda contiver caracteres, copie o restante como nome do arquivo
    if (entrada[i] != '\0') {
        i++; // Pula o espa�o em branco
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
                if (i < MAX_VARIEVEIS) { // Verifique se i est� dentro dos limites do vetor comandosLinha
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

    // Se houver menos de 4 palavras, inicialize as posi��es restantes do vetor de palavras
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

int pesquisaFuncion(char* comando) //<------- PAREI AQUI
{
    char* vetorCommand[] = { "INSEREPAGINA","RETIRAPAGINA","INSEREEDITOR","INSERECONTRIBUICAO","RETIRACONTRIBUICAO","INSERELINK","RETIRALINK","CAMINHO","IMPRIMEPAGINA","IMPRIMEWIKED","FIM" };
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

//----------------------------PRINCIPAL----------------------------
void executer(char* nomeArqTeste)
{
    FILE* arqOpen;
    FILE* arqLog;

    char lineCommandArq[ENTRADA_DADOS];
    char* lineCommand;
    char entrada[ENTRADA_DADOS];

    TPagina* wikiPages = bornPage();//Inicia virtualmente a wiki
    TInfoPage infoEnter = bornInfoPage();

    int numFuncion = 0;

    char lineLog[ENTRADA_DADOS];
    char* logMensagem;
    int logReturn;

    char** comandosLinha = (char**)malloc(5 * sizeof(char*));//Aloca o vetor de comando 
    if (comandosLinha == NULL)
    {
        printf("\nErro na aloca�ao de memoria para o vetor comandosLinha - I'm at line %d\n", __LINE__);
        return;
    }
    else
    {
        for (int i = 0; i < MAX_VARIEVEIS; i++)
        {
            comandosLinha[i] = (char*)malloc(sizeof(ENTRADA_DADOS));
            // Lidar com a falha na aloca��o de mem�ria, se necess�rio
            if (comandosLinha[i] == NULL)
            {
                // Lidar com a falha na aloca��o de mem�ria, se necess�rio
                for (int j = 0; j < i; j++)
                {
                    free(comandosLinha[j]);
                }
                free(comandosLinha);
                // Encerrar ou retornar em caso de erro
                printf("\nErro na aloca�ao de memoria para o vetor comandosLinha - I'm at line %d\n", __LINE__);
                return;
            }
        }
    }

    /*
    //------------PODE VIRAR FUN��O----------------------
    lineCommand = (char*)malloc(ENTRADA_DADOS * sizeof(char));//Aloca o vetor de char da mensagem log
    if (lineCommand == NULL)
    {
        printf("\nErro na aloca�ao de memoria para o linha comando - I'm at line %d\n", __LINE__);
        return;
    }
    */
    logMensagem = (char*)malloc(ENTRADA_DADOS * sizeof(char));//Aloca o vetor de char da mensagem log
    if (logMensagem == NULL)
    {
        printf("\nErro na aloca�ao de memoria para o char log - I'm at line %d\n", __LINE__);
        return;
    }

    //------------MEU SOUNHO ERA CONSGUIR FAZER DISSO UMA FUN�AO---------
    errno_t err = fopen_s(&arqOpen, nomeArqTeste, "r");//Abre o arquivo texte
    if (arqOpen == NULL && err != 0) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArqTeste);
        return;
    }

    rewind(arqOpen);

    //------------MEU SOUNHO ERA CONSGUIR FAZER DISSO UMA FUN�AO---------
    errno_t err1 = fopen_s(&arqLog, "logWiki.txt", "a+");//Abre o arquivo log
    if (arqLog == NULL && err1 != 0) {
        printf("Erro ao abrir o arquivo logWiki.txt.- I'm at line %d\n", __LINE__);
        return;
    }

    printf("\nIniciando a execu��o, Boa Jornada!!!!\n");

    //-----------------------------------LOOP-------------------------------------
    while (fgets(lineCommandArq, sizeof(lineCommandArq), arqOpen) != NULL)
    {
        // Inicialize o vetor de palavras
        for (int i = 0; i < MAX_VARIEVEIS; i++) {
            comandosLinha[i][0] = '\0';
        }

        // Copie a linha lida para a vari�vel "entrada"
        strncpy_s(entrada, ENTRADA_DADOS, lineCommandArq, _TRUNCATE);

        separarComandoE4Palavras(entrada, comandosLinha);

        numFuncion = pesquisaFuncion(comandosLinha[0]);

        logReturn = 0;

        switch (numFuncion)
        {
        case 1://INSEREPAGINA <nome_pagina><nome_arquivo> 
            infoEnter.nomePage = comandosLinha[1];
            //strncpy_s(infoEnter.nomePage, ENTRADA_DADOS, comandosLinha[1], _TRUNCATE);

            logReturn = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//Pagina ja existe
            {
                strcpy_s(logMensagem, ENTRADA_DADOS, "ERRO: PAGINA J� EXISTE", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            else//Cria pagina
            {
                logReturn = lastPage(wikiPages, infoEnter);

                strcpy_s(logMensagem, ENTRADA_DADOS, "PAGINA CRIADA", _TRUNCATE);

                logReturn = logEdit(arqLog, logMensagem);
            }

            printf("\n %s - %s \n", comandosLinha[1], comandosLinha[2]);//RETIRAR

            break;
        case 2://*RETIRAPAGINA <nome_pagina>: exclui a p�gina da WikED!, 
            infoEnter.nomePage = comandosLinha[1];
            //strncpy_s(infoEnter.nomePage, ENTRADA_DADOS, comandosLinha[1], _TRUNCATE);

            logReturn = removePage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//SUCESSO
            {
                strcpy_s(logMensagem, ENTRADA_DADOS, "PAGINA REMOVIDA", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            else
            {
                strcpy_s(logMensagem, ENTRADA_DADOS, "PAGINA N�O EXISTE", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }

            printTESTE();
            break;
        default:
            printf("\nCOMANDO INEXISTENTE!!!\n");
            break;
        }
        //limpa o buff de lineCommand?

    }//Fim While
    fclose(arqLog);
    fclose(arqOpen);
}//fim Executer

void closeArq(FILE* nomeArq)
{
    fclose(nomeArq);
}

void printTESTE()
{
    printf("\nTESTE DESGRA�A - I'm at line %d\n", __LINE__);
}


//---------------------------------- FUN��ES MANUPULA ARQUIVO--------------------

int logEdit(FILE* arqLog, char* logMensagem) //<----------------PAREI AQUI
{
    if (arqLog == NULL) {
        printf("Erro: o arquivo de log n�o foi aberto corretamente.\n");
        return -1;  // ou algum outro valor de erro apropriado
    }

    // Certifica-se de que logMensagem caiba no buffer de lineLog
    if (strlen(logMensagem) >= ENTRADA_DADOS - 1) {
        printf("Erro: a mensagem de log � muito longa para caber no buffer.\n");
        return -1;
    }

    char lineInArq[ENTRADA_DADOS];
    char lineLog[ENTRADA_DADOS];

    //strncpy_s(lineInArq, ENTRADA_DADOS, logMensagem, _TRUNCATE);

    //fseek(arqLog, 0, SEEK_END);

    //size_t elementosEscritos = fwrite(&lineInArq, strlen(lineInArq), 1, arqLog);

    // Escreva a mensagem no arquivo, seguida por uma quebra de linha
    fprintf(arqLog, "%s\n", logMensagem);

    printf("\nlogMsg - %s\n", logMensagem);

    return 1;
}






/*
FILE* openFile(char* nomeArquivo)
{
    FILE* arqOpen;
    errno_t err = fopen_s(&arqOpen, nomeArquivo, "a+");

    if (err != 0) {

        return NULL;
    }
    return arqOpen;
}



int openFile(const char* nomeArquivo, FILE** arquivo) {
    if (fopen_s(arquivo, nomeArquivo, "a+") != 0) {
        perror("Erro ao abrir o arquivo");
        printf("\nERRO AO ABRIR ARQUIVO %s!!! I'm at line %d\n", nomeArquivo, __LINE__);
        return -1;
    }
    return 0;
}
*/