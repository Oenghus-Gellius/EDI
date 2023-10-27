#include "WikiEDI_BETA.h"
//#include "Links.h"
#include "testador.h"
#include "Log.h"

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
        strncpy_s(ptrNodoPage->infoP.nomePage, MAX_CHAR, infoEnter.nomePage, _TRUNCATE);

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
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(wikiPages);
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrNodoPage == NULL)
    {
        printf("\nErro na aloca�ao de memoria para a pagina - I'm at line %d\n", __LINE__);
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
            strncpy_s(ptrNodoPage->infoP.nomePage, MAX_CHAR, infoEnter.nomePage, _TRUNCATE);

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
            *infoEnter = &(ptrNodoPage->infoP);
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
    char comando[MAX_CHAR];
    int comando_len = 0;

    int k = 0;

    while (entrada[k] != '\0') {
        if (entrada[k] == ' ' || entrada[k] == '\n' || entrada[k] == '\r') {
            if (comando_len > 0) {
                if (i < MAX_VARIEVEIS) { // Verifique se i est� dentro dos limites do vetor comandosLinha
                    strncpy_s(comandosLinha[i], MAX_CHAR, entrada + k - comando_len, comando_len);
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
            strncpy_s(comandosLinha[i], MAX_CHAR, entrada + k - comando_len, comando_len);
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
    char* lineCommand;
    char entrada[MAX_CHAR];

    TPagina* wikiPages = bornPage();//Inicia virtualmente a wiki
    TInfoPage infoEnter; // = bornInfoPage();

    int numFuncion = 0;

    char lineLog[MAX_CHAR];
    char* logMensagem;
    int logReturn;

    int finder;

    //<---Cria a lista de editores
    TEditores* listEditores = bornListEditores();
    TNodoEditor infosEditEnter;

    //LISTA LINKS
    TListaLinks* listaLinks = bornListLinks();//Cria lista de Links
    TLinks linksEnter;

    TNodoPage* ptrPageOrigem;

    TNodoPage* ptrPageDestino;

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
            comandosLinha[i] = (char*)malloc(sizeof(MAX_CHAR));
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
    logMensagem = (char*)malloc(MAX_CHAR * sizeof(char));//Aloca o vetor de char da mensagem log
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
        strncpy_s(entrada, MAX_CHAR, lineCommandArq, _TRUNCATE);

        separarComandoE4Palavras(entrada, comandosLinha);

        numFuncion = pesquisaFuncion(comandosLinha[0]);

        logReturn = 0;

        switch (numFuncion)
        {

        case 1://INSEREPAGINA <nome_pagina><nome_arquivo> 
  
            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

            logReturn = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//Pagina ja existe
            {
                strcpy_s(logMensagem, MAX_CHAR, "ERRO: PAGINA J� EXISTE", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            else//Cria pagina
            {
                logReturn = lastPage(wikiPages, infoEnter);

                strcpy_s(logMensagem, MAX_CHAR, "PAGINA CRIADA", _TRUNCATE);

                logReturn = logEdit(arqLog, logMensagem);
            }

            printf("\n %s - %s \n", comandosLinha[1], comandosLinha[2]);//RETIRAR

            break;


        case 2://*RETIRAPAGINA <nome_pagina>: exclui a p�gina da WikED!, 

            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

            numFuncion = pesquisaFuncion(comandosLinha[0]);

            if (numFuncion == 1)//pagina encontrada
            {
                logReturn = removePage(wikiPages, infoEnter.nomePage, &infoEnter);
                strcpy_s(logMensagem, MAX_CHAR, "PAGINA REMOVIDA", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            else
            {
                strcpy_s(logMensagem, MAX_CHAR, "PAGINA N�O EXISTE", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            break;


        case 3://INSEREEDITOR <nome_editor>: 
                //insere um editor com o nome especificado (deve ser único). 
            finder = 0;
            strncpy_s(infosEditEnter.nomeEditor, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            finder = finderEditores(listEditores, infosEditEnter.nomeEditor, &infosEditEnter);
            if (finder == 1)//NOME REPETIDO
            {
                strcpy_s(logMensagem, MAX_CHAR, "EDITOR JÁ CADASTRADO", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            else//CADASTRADO EDITOR
            {
                logReturn = lastEditores(listEditores, infosEditEnter);//Seta que o nome vai estar aqui?

                //FAZER O CADASTRO NA LISTA E EDITORES E INSERIR AS COLABORAÇÔES

                //PAREI AQUI!!!!!!!!!!!!!!!!!!#########################


                strcpy_s(logMensagem, MAX_CHAR, "EDITOR CADASTRADO", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            break;

        case 4://RETIRAEDITOR <nome_editor>: 
            //retira um editor com o nome especificado (deve ser único). 
            finder = 0;
            strncpy_s(infosEditEnter.nomeEditor, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            finder = finderEditores(listEditores, infosEditEnter.nomeEditor, &infosEditEnter);
            if (finder == 1)//NOME REPETIDO
            {

                //BRABO RETIRAR TODAS AS CONTRIBUIÇões


                strcpy_s(logMensagem, MAX_CHAR, "EDITOR REMOVIDOS", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            else// EDITOR NÃO EXISTE
            {
                strcpy_s(logMensagem, MAX_CHAR, "EDITOR NO EXISTE", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            break;


        case 5://*INSERECONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: insere uma contribuição de
            //um dado editor para uma determinada página.O trecho de texto deve estar editado no arquivo especificado.* /
            finder = 0;
            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (finder == 1)//Pagina Encontrada
            {
                strncpy_s(infosEditEnter.nomeEditor, MAX_CHAR, comandosLinha[2], _TRUNCATE);
                finder = finderPage(wikiPages, infosEditEnter.nomeEditor, &infosEditEnter);
                if (finder == 1)
                {
                    //Nome da pagina
                    strncpy_s(infosEditEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);
                    //nome editor
                    strncpy_s(infosEditEnter.nomeEditor, MAX_CHAR, comandosLinha[2], _TRUNCATE);
                    //endereço colaboração
                    strncpy_s(infosEditEnter.colab, MAX_CHAR, comandosLinha[3], _TRUNCATE);


                    logReturn = lastEditores(listEditores, infosEditEnter);                    );//CRIAR A CONTRIBUIÇÃO
                }
                else
                {
                    strcpy_s(logMensagem, MAX_CHAR, "EDITOR NO CADASTRADO", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
                }
                //wikiPages->cursor;//PONTEIRO PARA A PAGINA LOCALIZADA <--FALTA!!!
            }
            else//Pagina não encotrada
            {
                strcpy_s(logMensagem, MAX_CHAR, "PAGINA NÃO LOCALIZADA", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            break;


        case 6:/*RETIRACONTRIBUICAO <nome_pagina><nome_editor><nome_arquivo>: retira uma dada
                contribuição. Apenas o editor responsável pela contribuição pode retirá-la. O histórico da contribuição deve
                continuar ativo.*/
            finder = 0;
            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (finder == 1)//Pagina Encontrada
            {
                finder = 0;
                strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[2], _TRUNCATE);
                //finder = finderEditor(editores, infoEnter.nomePage);
                if (finder == 1)//NOME ENCONTRADO
                {

                    wikiPages->cursor;//PONTEIRO PARA A PAGINA LOCALIZADA <--FALTA!!!!

                    strcpy_s(logMensagem, MAX_CHAR, "CONTRIBUIÇÃO RETIRADA", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
                }
                else//EDITOR NÃO ALTORIZADO ALTERAR
                {
                    strcpy_s(logMensagem, MAX_CHAR, "EDITOR NÃO ALTORIZADO", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
                }
            }
            else//Pagina não encotrada
            {
                strcpy_s(logMensagem, MAX_CHAR, "PAGINA NÃO LOCALIZADA", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            break;


        case 7:/*INSERELINK <pagina_origem><pagina_destino>: insere um link (nome do arquivo) para página destino,
                na página origem.*/

            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

            finder = 0;
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSOR

            if (finder == 1)//pagina encontrada
            {           
                ptrPageOrigem = wikiPages->cursor;//PEGA O VALOR DO CURSOR ATUAL GERADO NA LINHA DE CIMA

                strncpy_s(ptrPageOrigem->infoP.linkPages.linkOrigem, MAX_CHAR, comandosLinha[1], _TRUNCATE);

                finder = 0;
                strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[2], _TRUNCATE);
                finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSO

                if (finder == 1)
                {
                    ptrPageDestino = wikiPages->cursor;

                    strncpy_s(ptrPageOrigem->infoP.linkPages.linkDestino, MAX_CHAR, comandosLinha[2], _TRUNCATE);

                    strncpy_s(linksEnter.linkOrigem, MAX_CHAR, comandosLinha[1], _TRUNCATE);

                    strncpy_s(linksEnter.linkDestino, MAX_CHAR, comandosLinha[2], _TRUNCATE);

                    logReturn = insereLink(ptrPageOrigem, ptrPageDestino);//Coloca os links nas paginas

                    logReturn = lastLinks(listaLinks, linksEnter);//coloca os links na lista de links

                    strcpy_s(logMensagem, MAX_CHAR, "LINK INSERIDO", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
                }
                else
                {
                    //PAGINA DE DESTINO NÃO EXISTE
                    strcpy_s(logMensagem, MAX_CHAR, "PAGINA DE DESTINO No EXISTE", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
                }
            }
            else
            {
                //NÃO EXISTE PAGINA
                strcpy_s(logMensagem, MAX_CHAR, "PAGINA NO EXISTE", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            break;


        case 8:/*RETIRALINK <pagina_origem><pagina_destino>: retira um link (nome do arquivo) da página origem
                para uma página destino.*/

            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

            finder = 0;
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSOR

            if (finder == 1)//pagina encontrada
            {
                ptrPageOrigem = wikiPages->cursor;//PEGA O VALOR DO CURSOR ATUAL GERADO NA LINHA DE CIMA

                strncpy_s(ptrPageOrigem->infoP.linkPages.linkOrigem, MAX_CHAR, comandosLinha[1], _TRUNCATE);

                finder = 0;
                strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[2], _TRUNCATE);
                finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSO

                if (finder == 1)//CAMINHO Destinho
                {
                    ptrPageDestino = wikiPages->cursor;





                    strcpy_s(logMensagem, MAX_CHAR, "LINK INSERIDO", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
                }
                else
                {
                    //PAGINA DE DESTINO NÃO EXISTE
                    strcpy_s(logMensagem, MAX_CHAR, "PAGINA DE DESTINO No EXISTE", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
                }
            }
            else
            {
                //NÃO EXISTE PAGINA
                strcpy_s(logMensagem, MAX_CHAR, "PAGINA NO EXISTE", _TRUNCATE);
                logReturn = logEdit(arqLog, logMensagem);
            }
            break;
        case 9:/*CAMINHO <pagina_origem><pagina_destino>: verifica se há caminho entre duas páginas (por meio das
                listas de links). Escreve no arquivo de log (HA/NAO HA CAMINHO DA <pagina_origem> PARA <pagina_destino>)*/
            

            break;
        case 10:/*IMPRIMEPAGINA <nome_pagina>: gera o arquivo e imprime as informações da página especificada.*/

            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

            logReturn = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//Pagina  existe
            {
                TInfoPage* ptrNodoPage = wikiPages->cursor;


            }
            else//PAGINA NO EXISTE
            {

                strcpy_s(logMensagem, MAX_CHAR, "PAGINA NO EXISTE", _TRUNCATE);

                logReturn = logEdit(arqLog, logMensagem);
            }

            printf("\n %s - %s \n", comandosLinha[1], comandosLinha[2]);//RETIRAR

            break;
        case 11:/*IMPRIMEWIKED: gera os arquivos e imprime todas as informações das páginas da WikEDI, como
especificado acima.*/

            break;
        case 12:/*FIM: determina a finalização do programa. Toda a memória alocada deve ser liberada.*/
            //DESALOCAR TODO QUE FALTAR;

            break;

        default:
            printf("\nCOMANDO INEXISTENTE!!!\n");
            break;
        }
        //limpa o buff de lineCommand?

    }//Fim While

    //FECHAR OS ARQUIVOS QUE AINDA ESTIVEREM ABERTOS
    fclose(arqLog);
    fclose(arqOpen);

    //DESALOCAR AS MEMORIAS QUE ESTÂO AINDA ABERTAS
    //1-FREE NA LISTA DE EDITORES
}//fim Executer

void printPageWikiArq(TPagina *wikiPages, TNodoEditor* infosEdit)
{
    TInfoPage infoEnter;

    int finder = 0;

    if (finder == 1)
    {
        // Abra o arquivo para adicionar conteúdo
        FILE* arquivo;
        errno_t err = fopen_s(&arquivo, "nomePage", "w");
        if (err != 0)
        {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }
    }
    else//PAGINA NÃO EXISTE
    {

    }


    

}

void closeArq(FILE* nomeArq)
{
    fclose(nomeArq);
}


//---------------------------------- FUN��ES MANUPULA ARQUIVO--------------------

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