#pragma GCC diagnostic ignored "-Wunused-parameter"

#include "wikiedi.h"
#include "WikiEDI_BETA.h"
#include "Editores.h"


#include "Links.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
#define MAX_VARIEVEIS 4
#define MAX_CHAR 100

//--------------------------------------fun��es auxiliares de Aloca��o Pagina----------------------

TPagina* bornPage()
{
    TPagina* page = (TPagina*)malloc(sizeof(TPagina));
    if (page != NULL)
    {
        page->inicio = NULL;
        page->fim = NULL;
        page->cursor = NULL;
        page->tamanho = 0;
        page->posicaoCorrente = 0;
    }
    return page;
}

int firstPage(TPagina* wikiPages, TInfoPage infoEnter)
{
    // fazer que a fun��o fullPage retorne -1 se estiver cheia
    if (fullPage(wikiPages) == -1)
    {
        printf("\nErro na alocacao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return 0;
    }
    else
    {
        ptrNodoPage->infoP = infoEnter;
        //strncpy_s(ptrNodoPage->infoP.nomePage, MAX_CHAR, infoEnter.nomePage, _TRUNCATE);

        ptrNodoPage->nextPage = NULL;
        wikiPages->inicio = ptrNodoPage;
        wikiPages->tamanho++;
        wikiPages->fim = ptrNodoPage;
        wikiPages->cursor = ptrNodoPage;

        return 1;
    }
}

int lastPage(TPagina* wikiPages, TInfoPage infoEnter)
{
    // fazer que a fun��o fullPage retorne -1 se estiver cheia
    if (fullPage(wikiPages) == -1)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na alocao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);
        return 0;
    }
    else
    {
        ptrNodoPage->nextPage = NULL;

        //verificando se a lista está vazia
        if (wikiPages->inicio == NULL)
        {
            firstPage(wikiPages, infoEnter);
            free(ptrNodoPage);
        }
        else
        {
            ptrNodoPage->infoP = infoEnter;
            //strncpy_s(ptrNodoPage->infoP.nomePage, MAX_CHAR, infoEnter.nomePage, _TRUNCATE);

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
            //*infoEnter->nomePage = ptrNodoPage->infoP.nomePage;
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

int finderPage(TPagina* wikiPages, char* nomePage, TInfoPage* infoEnter)
{
    TNodoPage* ptrNodoPage;

    ptrNodoPage = wikiPages->inicio;

    while (ptrNodoPage != NULL)
    {
        if (strcmp(ptrNodoPage->infoP.nomePage, nomePage) == 0)
        {

            wikiPages->cursor = ptrNodoPage;//QUERO USARO CURSOR PARA TER O ENDEREÇO PESQUISARO PARA EDITAR A PAGINA
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
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return -1;
    }
    free(ptrNodoPage);
    return 0;
}

int quantityPages(TPagina* wikiPages)
{
    return wikiPages->tamanho;
}

void freePages(TPagina* wikiPages) {
    TNodoPage* currentNode = wikiPages->inicio;
    while (currentNode != NULL) {
        TNodoPage* temp = currentNode;
        currentNode = currentNode->nextPage;
        free(temp);
    }
    free(wikiPages);

    // Defina os ponteiros para NULL
    wikiPages->inicio = NULL;
    wikiPages->fim = NULL;
    wikiPages->cursor = NULL;
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
    int comando_len = 0;
    int k = 0;

    while (entrada[k] != '\0') {
        if (entrada[k] == ' ' || entrada[k] == '\n' || entrada[k] == '\r') {
            if (comando_len > 0) {
                if (i < MAX_VARIEVEIS) {
                    if (comando_len < MAX_CHAR) { // Verifique se o comprimento da palavra não excede o tamanho máximo
                        strncpy(comandosLinha[i], entrada + k - comando_len, comando_len);
                        comandosLinha[i][comando_len] = '\0';
                    } else {
                        // Lide com o erro de palavra muito longa
                    }
                }
                i++;
                comando_len = 0;
            }
        } else {
            comando_len++;
        }
        k++;
    }

    // Se houver menos de 4 palavras, inicialize as posições restantes do vetor de palavras
    if (comando_len > 0) {
        if (i < MAX_VARIEVEIS) {
            if (comando_len < MAX_CHAR) {
                strncpy(comandosLinha[i], entrada + k - comando_len, comando_len);
                comandosLinha[i][comando_len] = '\0';
            } else {
                // Lide com o erro de palavra muito longa
            }
        }
    }
}

int openFileTester(char* nomeArquivo)
{
    FILE* arqTest;
    arqTest = fopen(nomeArquivo, "r");
    if (arqTest == NULL)
    {
        return -1;
    }
    return 0;
}

int pesquisaFuncion(char* comando) //<------- PAREI AQUI
{
    char* vetorCommand[] = { "INSEREPAGINA","RETIRAPAGINA","INSEREEDITOR","RETIRAEDITOR", "INSERECONTRIBUICAO","RETIRACONTRIBUICAO","INSERELINK","RETIRALINK","CAMINHO","IMPRIMEPAGINA","IMPRIMEWIKED","FIM" };
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

    char lineCommandArq[MAX_CHAR];
    char entrada[MAX_CHAR];

    TPagina* wikiPages = bornPage();//Inicia virtualmente a wiki
    TInfoPage infoEnter; // = bornInfoPage();

    int numFuncion = 0;

    char* logMensagem;
    int logReturn;

    int finder;

    //<---Cria a lista de edições
    TEditores* listColab = bornListEditores();
    //informações da lista de EDIÇÃO
    TConteudoEdit infosEditEnter;

    //Lista de editores
    TEditores* listaEditores = bornListEditores();
    //informações da lista de EDITORES
    TConteudoEdit nomeEditorEnter;

    //LISTA LINKS
    TListaLinks* listaLinks = bornListLinks();//Cria lista de Links
    TLinksLista linksEnter;

    //TNodoPage* ptrPageOrigem;

    //TNodoPage* ptrPageDestino;

    char** comandosLinha = (char**)malloc(5 * sizeof(char*));//Aloca o vetor de comando
    if (comandosLinha == NULL)
    {
        printf("\nErro na alocaao de memoria para o vetor comandosLinha - I'm at line %d\n", __LINE__);
        return;
    }
    else
    {
        for (int i = 0; i < MAX_VARIEVEIS; i++)
        {
            comandosLinha[i] = (char*)malloc(MAX_CHAR *sizeof(char));
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

    logMensagem = (char*)malloc(MAX_CHAR * sizeof(char));//Aloca o vetor de char da mensagem log
    if (logMensagem == NULL)
    {
        printf("\nErro na alocaao de memoria para o char log - I'm at line %d\n", __LINE__);
        return;
    }

    //------------ABRE ARQUIVOS---------
    arqOpen = fopen(nomeArqTeste, "r");//Abre o arquivo texte
    if (arqOpen == NULL ) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArqTeste);
        return;
    }

    rewind(arqOpen);


    arqLog= fopen("logWiki.txt", "a+");//Abre o arquivo log
    if (arqLog == NULL) {
        printf("Erro ao abrir o arquivo logWiki.txt.- I'm at line %d\n", __LINE__);
        return;
    }

    printf("\nIniciando a execuo, Boa Jornada!!!!\n");

    //-----------------------------------LOOP-------------------------------------
    while (fgets(lineCommandArq, sizeof(lineCommandArq), arqOpen) != NULL)
    {
        // Inicialize o vetor de palavras
        for (int i = 0; i < MAX_VARIEVEIS; i++) {
            comandosLinha[i][0] = '\0';
        }

        // Copie a linha lida para a vari�vel "entrada"

        strncpy(entrada, lineCommandArq, MAX_CHAR);

        separarComandoE4Palavras(entrada, comandosLinha);

        numFuncion = pesquisaFuncion(comandosLinha[0]);

        logReturn = 0;

        TNodoPage* ptrNodoPrintPage = NULL;
        TNodoEditor* ptrNodoPrintEditor = NULL;
        TNodoLink* ptrNodoPrintLinks = NULL;

        switch (numFuncion)
        {

        case 1://INSEREPAGINA <nome_pagina><nome_arquivo>

            strncpy(infoEnter.nomePage, comandosLinha[1], MAX_CHAR);
            strncpy(infoEnter.nomeArqPage, comandosLinha[2], MAX_CHAR);

            logReturn = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//Pagina ja existe
            {
                fprintf(arqLog, "PAGINA %s JA EXISTE\n", comandosLinha[1]);
            }
            else//Cria pagina
            {
                logReturn = lastPage(wikiPages, infoEnter);

                fprintf(arqLog, "PAGINA %s CRIADASs\n", comandosLinha[1]);
            }
            break;


        case 2://*RETIRAPAGINA <nome_pagina>: exclui a p�gina da WikED!,

            strncpy(infoEnter.nomePage, comandosLinha[1],MAX_CHAR);

            numFuncion = pesquisaFuncion(comandosLinha[0]);

            if (numFuncion == 1)//pagina encontrada
            {
                logReturn = removePage(wikiPages, infoEnter.nomePage, &infoEnter);

                fprintf(arqLog, "PAGINA REMOVIDA - %s\n", comandosLinha[1]);
            }
            else
            {
                fprintf(arqLog, "PAGINA NO EXISTE - %s\n", comandosLinha[1]);
            }
            break;


        case 3://INSEREEDITOR <nome_editor>:
                //insere um editor com o nome especificado (deve ser único).
            finder = 0;
            strncpy(nomeEditorEnter.nomeEditor,comandosLinha[1], MAX_CHAR);
            finder = finderEditores(listaEditores, nomeEditorEnter.nomeEditor, &nomeEditorEnter);
            if (finder == 1)//NOME REPETIDO
            {
                fprintf(arqLog, "EDITOR JÁ CADASTRADO - %s\n", comandosLinha[1]);
            }
            else//CADASTRADO EDITOR
            {
                strncpy(nomeEditorEnter.nomeEditor, comandosLinha[1],MAX_CHAR);

                logReturn = lastEditores(listaEditores, nomeEditorEnter);//Seta que o nome vai estar aqui

                fprintf(arqLog, "EDITOR CADASTRADO - %s\n", comandosLinha[1]);
            }
            break;

        case 4://RETIRAEDITOR <nome_editor>:
            //retira um editor com o nome especificado (deve ser único).
            finder = 0;
            strncpy(nomeEditorEnter.nomeEditor, comandosLinha[1],MAX_CHAR);
            finder = finderEditores(listaEditores, nomeEditorEnter.nomeEditor, &nomeEditorEnter);
            if (finder == 1)//EDITOR Encotrado
            {
                //remove TODAS AS COLABORAÇÕES DO EDITOR
                logReturn = removeEditores(listaEditores, nomeEditorEnter.nomeEditor, &nomeEditorEnter);
                TNodoEditor* ptrlistColab = listColab->inicio;
                while (ptrlistColab != NULL)
                {
                    if (strcmp(ptrlistColab->infoEdit.nomeEditor , nomeEditorEnter.nomeEditor) == 0)
                    {
                        logReturn = removeEditores(listColab, nomeEditorEnter.nomeEditor, &infosEditEnter);
                    }
                }
                fprintf(arqLog, "EDITOR REMOVIDO - %s\n", comandosLinha[1]);
            }
            else// EDITOR NÃO EXISTE
            {
                fprintf(arqLog, "EDITOR NO EXISTE - %s\n", comandosLinha[1]);
            }
            break;


        case 5://*INSERECONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: insere uma contribuição de
            //um dado editor para uma determinada página.O trecho de texto deve estar editado no arquivo especificado.* /
            finder = 0;

            strncpy(infoEnter.nomePage, comandosLinha[1],MAX_CHAR);
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (finder == 1)//Pagina Encontrada
            {

                strncpy(infosEditEnter.nomeEditor, comandosLinha[2],MAX_CHAR);
                finder = finderEditores(listaEditores, infosEditEnter.nomeEditor, &nomeEditorEnter);
                if (finder == 1)//
                {
                    //Nome da pagina
                    strncpy(infosEditEnter.nomePage, comandosLinha[1],MAX_CHAR);
                    //nome editor
                    strncpy(infosEditEnter.nomeEditor,comandosLinha[2],MAX_CHAR);
                    //endereço colaboração
                    strncpy(infosEditEnter.colab,comandosLinha[3],MAX_CHAR);

                    logReturn = lastEditores(listColab, infosEditEnter);//CRIAR A CONTRIBUIÇÃO

                    fprintf(arqLog, "CONTRIBUICAO FEITAR COM SUCESSO - PAGINA.: %s - EDITOR.: %s \n",
                        comandosLinha[1], comandosLinha[2]);
                }
                else
                {
                    fprintf(arqLog, "EDITOR NO EXISTE - %s\n", comandosLinha[2]);
                }
                //wikiPages->cursor;//PONTEIRO PARA A PAGINA LOCALIZADA <--FALTA!!!
            }
            else//Pagina não encotrada
            {
                fprintf(arqLog, "PAGINA NO EXISTE - %s\n", comandosLinha[1]);
            }
            break;


        case 6:/*RETIRACONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: retira uma dada
                contribuição. Apenas o editor responsável pela contribuição pode retirá-la. O histórico da contribuição deve
                continuar ativo.*/
            finder = 0;
            strncpy(infoEnter.nomePage, comandosLinha[1],MAX_CHAR);
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (finder == 1)//Pagina Encontrada
            {
                finder = 0;
                strncpy(infosEditEnter.nomeEditor, comandosLinha[2],MAX_CHAR);
                finder = finderEditores(listColab, infosEditEnter.nomeEditor, &infosEditEnter);
                if (finder == 1)//NOME ENCONTRADO
                {
                    //finder = finderEditor(listColab, infosEditEnter.colab);
                    if (finder == 0)//COlab encotrada
                    {
                        logReturn = removeEditores(listColab,infosEditEnter.colab, &nomeEditorEnter);

                        fprintf(arqLog, "CONTRIBUIÇÃO DE %s RETIRADA DA PAGINA %s\n",
                            comandosLinha[2], comandosLinha[1]);

                    }
                    //wikiPages->cursor;//PONTEIRO PARA A PAGINA LOCALIZADA <--FALTA!!!!
                }
                else//EDITOR NÃO ALTORIZADO ALTERAR
                {
                    fprintf(arqLog, "EDITOR -%s- NO ALTORUZADO A EDITAR \n", comandosLinha[2]);
                }
            }
            else//Pagina não encotrada
            {
                fprintf(arqLog, "PAGINA NO EXISTE - %s\n", comandosLinha[1]);
            }
            break;


        case 7:/*INSERELINK <pagina_origem><pagina_destino>: insere um link (nome do arquivo) para página destino,
                na página origem.*/

            strncpy(infoEnter.nomePage, comandosLinha[1],MAX_CHAR);

            finder = 0;
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSOR

            if (finder == 1)//pagina encontrada
            {
                //ptrPageOrigem = wikiPages->cursor;//PEGA O VALOR DO CURSOR ATUAL GERADO NA LINHA DE CIMA

                strncpy(linksEnter.linkOrigem, comandosLinha[1],MAX_CHAR);

                finder = 0;
                strncpy(linksEnter.linkDestino, comandosLinha[2],MAX_CHAR);
                finder = finderPage(wikiPages, linksEnter.linkDestino, &infoEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSO

                if (finder == 1)
                {
                    //ptrPageDestino = wikiPages->cursor;

                    //strncpy(ptrPageOrigem->infoP.linkPages.linkDestino, comandosLinha[2],MAX_CHAR);

                    strncpy(linksEnter.linkOrigem, comandosLinha[1],MAX_CHAR);

                    strncpy(linksEnter.linkDestino, comandosLinha[2],MAX_CHAR);

                    //logReturn = insereLink(ptrPageOrigem, ptrPageDestino);//Coloca os links nas paginas

                    logReturn = lastLinks(listaLinks, linksEnter);//coloca os links na lista de links

                    fprintf(arqLog, "LINK -%s- INSERIDO - PAGINA %s\n", comandosLinha[2],comandosLinha[1]);
                    strcpy(logMensagem,"LINK INSERIDO");
                    //logReturn = logEdit(arqLog, logMensagem);
                }
                else
                {
                    //PAGINA DE DESTINO NÃO EXISTE
                    fprintf(arqLog, "PAGINA -%s- DESTINO No EXISTE\n", comandosLinha[2]);
                }
            }
            else
            {
                //NÃO EXISTE PAGINA
                fprintf(arqLog, "PAGINA -%s- No EXISTE\n", comandosLinha[1]);
            }
            break;


        case 8:/*RETIRALINK <pagina_origem><pagina_destino>: retira um link (nome do arquivo) da página origem
                para uma página destino.*/

            finder = 0;
            strncpy(linksEnter.linkOrigem, comandosLinha[1],MAX_CHAR);
            finder = finderLinksOrig(listaLinks, linksEnter.linkOrigem, &linksEnter);
            if (finder == 1)//pagina encontrada
            {
                //ptrPageOrigem = wikiPages->cursor;//PEGA O VALOR DO CURSOR ATUAL GERADO NA LINHA DE CIMA

                finder = 0;
                strncpy(linksEnter.linkDestino, comandosLinha[2],MAX_CHAR);
                finder = finderLinksDest(listaLinks, linksEnter.linkDestino, &linksEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSO

                if (finder == 1)//CAMINHO Destinho
                {
                    //ptrPageDestino = wikiPages->cursor;

                    logReturn = removeLinks(listaLinks, linksEnter.linkDestino, &linksEnter);

                    fprintf(arqLog, "LINK -%s- REMOVIDO DA PAGINA %s\n", comandosLinha[2], comandosLinha[1]);
                }
                else
                {
                    //PAGINA DE DESTINO NÃO EXISTE
                    fprintf(arqLog, "PAGINA -%s- DE DESTINO NO EXISTE\n", comandosLinha[2]);
                }
            }
            else
            {
                //NÃO EXISTE PAGINA
                fprintf(arqLog, "PAGINA -%s- No EXISTE\n", comandosLinha[1]);
            }
            break;


        case 9:/*CAMINHO <pagina_origem><pagina_destino>: verifica se há caminho entre duas páginas (por meio das
                listas de links). Escreve no arquivo de log (HA/NAO HA CAMINHO DA <pagina_origem> PARA <pagina_destino>)*/
            strncpy(linksEnter.linkOrigem, comandosLinha[1],MAX_CHAR);

            finder = 0;
            finder = finderLinksOrig(listaLinks, linksEnter.linkOrigem, &linksEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSOR
            if (finder == 1)
            {
                finder = finderLinksOrig(listaLinks, comandosLinha[1], &linksEnter);
                if (finder == 1)
                {
                    finder = finderLinksDest(listaLinks, comandosLinha[2], &linksEnter);
                    if (finder == 1)
                    {
                        fprintf(arqLog, "CAMINHO ENTRE %s ORIGEM %s DESTINO\n", comandosLinha[1], comandosLinha[2]);

                    }
                }
            }
            else
            {
                fprintf(arqLog, "SEM CAMINHO ENTRE %s ORIGEM %s DESTINO\n", comandosLinha[1], comandosLinha[2]);

            }


            break;
        case 10:/*IMPRIMEPAGINA <nome_pagina>: gera o arquivo e imprime as informações da página especificada.*/

            strncpy(infoEnter.nomePage, comandosLinha[1],MAX_CHAR);

            logReturn = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//Pagina  existe
            {
                //TNodoPage* ptrNodoPage = wikiPages->cursor;
                //printPageWikiArq(wikiPages, listColab);


              //-------------------------------------------------------
                TNodoPage* ptrNodoPage = wikiPages->cursor;

                TNodoEditor* ptrNodoEditor = listColab->inicio;

                TNodoLink* ptrNodoLinks = listaLinks->inicio;


                char lineCommandArq[MAX_LINE_LENGTH];

                // Abra o arquivo para adicionar conteúdo
                FILE* arquivo;
                arquivo = fopen(ptrNodoPage->infoP.nomeArqPage, "w+");
                if (arquivo == NULL)
                {
                    printf("Erro ao abrir o arquivo.\n");
                    return;
                }

                // Escreva o texto no arquivo
                fprintf(arquivo, "%s\n", ptrNodoPage->infoP.nomePage);//Nome PAge

                for (int i = 1; i < listColab->tamanho; i++)//Lista de colaborações e Editores //while(ptrNodoEditor != NULL)
                {
                    if (strcmp(ptrNodoEditor->infoEdit.nomePage, wikiPages->cursor->infoP.nomePage) == 0)
                    {
                        FILE* arqcolab;
                        arqcolab= fopen(ptrNodoEditor->infoEdit.colab, "r");
                        if (arqcolab == NULL)
                        {
                            printf("Erro ao abrir o arquivo.\n");
                            return;
                        }
                        while (fgets(lineCommandArq, sizeof(lineCommandArq), arqcolab) != NULL){

                        fprintf(arquivo, "%s\n", lineCommandArq);//AQUI TEM QUE COPIAR O CONTEUDO DO ARQUIVO
                        }
                        fprintf(arquivo, "%s", "Editor.: ");
                        fprintf(arquivo, "%s\n", ptrNodoEditor->infoEdit.nomeEditor);
                        fclose(arqcolab);
                    }
                }

                fprintf(arquivo, "%s", "Links.:");
                for (int i = 0; i < listaLinks->tamanho; i++)
                {
                    if (strcmp(ptrNodoLinks->infoLink.linkDestino, wikiPages->cursor->infoP.nomePage))
                    {
                        fprintf(arquivo, "%s\n", ptrNodoLinks->infoLink.linkDestino);
                    }
                }

                // Feche o arquivo
                fclose(arquivo);
              //-------------------------------------------------------

                fprintf(arqLog, "PAGINA %s ImPRESSA\n", infoEnter.nomePage);
            }
            else//PAGINA NO EXISTE
            {
                //NÃO EXISTE PAGINA
                fprintf(arqLog, "PAGINA %s No EXISTE\n", infoEnter.nomePage);
            }
            break;



        case 11:/*IMPRIMEWIKED: gera os arquivos e imprime todas as informações das páginas da WikEDI, como especificado acima.*/

            ptrNodoPrintPage = wikiPages->inicio;
            //ptrNodoPrintEditor = listColab->inicio;
            //ptrNodoPrintLinks = listaLinks->inicio;

            //wikiPages.cursor = wikiPages->inicio;
            while(ptrNodoPrintPage != NULL)
            {
                //----------------------
                //TNodoPage* ptrNodoPage = wikiPages->cursor;

                TNodoEditor* ptrNodoEditor = listColab->inicio;

                TNodoLink* ptrNodoLinks = listaLinks->inicio;

                char lineCommandArq[MAX_LINE_LENGTH];

                // Abra o arquivo para adicionar conteúdo
                FILE* arquivo;
                arquivo = fopen(ptrNodoPrintPage->infoP.nomeArqPage, "w+");
                if (arquivo == NULL)
                {
                    printf("Erro ao abrir o arquivo.\n");
                    return;
                }

                // Escreva o texto no arquivo
                fprintf(arquivo, "\n%s\n\n", ptrNodoPrintPage->infoP.nomePage);//Nome PAge

                for (int i = 1; i < listColab->tamanho; i++)//Lista de colaborações e Editores
                {
                    if (strcmp(ptrNodoEditor->infoEdit.nomePage, wikiPages->cursor->infoP.nomePage) == 0)
                    {
                        FILE* arqcolab;
                        arqcolab= fopen(ptrNodoEditor->infoEdit.colab, "r");
                        if (arqcolab == NULL)
                        {
                            printf("Erro ao abrir o arquivo.\n");
                            return;
                        }
                        while (fgets(lineCommandArq, sizeof(lineCommandArq), arqcolab) != NULL){

                        fprintf(arquivo, "%s\n", lineCommandArq);//AQUI TEM QUE COPIAR O CONTEUDO DO ARQUIVO
                        }
                        fprintf(arquivo, "%s", "Editor.: ");
                        fprintf(arquivo, "%s\n", ptrNodoEditor->infoEdit.nomeEditor);
                        fclose(arqcolab);
                    }
                }

                fprintf(arquivo, "%s", "Links.:");
                for (int i = 0; i < listaLinks->tamanho; i++)
                {
                    if (strcmp(ptrNodoLinks->infoLink.linkDestino, wikiPages->cursor->infoP.nomePage))
                    {
                        fprintf(arquivo, "%s\n", ptrNodoLinks->infoLink.linkDestino);
                    }
                }
                ptrNodoPrintPage = ptrNodoPrintPage->nextPage;    //wikiPages->cursor = wikiPages->cursor->nextPage;
                //fprintf(arqLog, "\n\n%s\t",ptrNodoPrintPage->infoP.nomePage);

                // Feche o arquivo
                fclose(arquivo);
            }
            break;


        case 12:/*FIM: determina a finalização do programa. Toda a memória alocada deve ser liberada.*/
            //DESALOCAR TODO QUE FALTAR;

            fprintf(arqLog, "%s\n", comandosLinha[0]);

            //-----------------------Lista de pagina



            break;

        default:
            printf("\nCOMANDO INEXISTENTE!!!\n");
            break;
        }


    }//Fim While

    //FECHAR OS ARQUIVOS QUE AINDA ESTIVEREM ABERTOS
    fclose(arqLog);
    fclose(arqOpen);

    //DESALOCAR AS MEMORIAS QUE ESTÂO AINDA ABERTAS
    freePages(wikiPages);
    freeLinks(listaLinks);
    free(logMensagem);
    for (int i = 0; i < MAX_VARIEVEIS; i++) {
    free(comandosLinha[i]);
    }
    free(comandosLinha);


}//fim Executer

