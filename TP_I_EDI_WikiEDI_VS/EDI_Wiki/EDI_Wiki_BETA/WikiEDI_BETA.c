#include "WikiEDI_BETA.h"
//#include "Links.h"
#include "testador.h"
//#include "Log.h"
#include "Editores.h"

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

    TNodoPage* ptrPageOrigem;

    TNodoPage* ptrPageDestino;

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
        printf("\nErro na alocaao de memoria para o char log - I'm at line %d\n", __LINE__);
        return;
    }

    //------------ABRE ARQUIVOS---------
    errno_t err = fopen_s(&arqOpen, nomeArqTeste, "r");//Abre o arquivo texte
    if (arqOpen == NULL && err != 0) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArqTeste);
        return;
    }

    rewind(arqOpen);


    errno_t err1 = fopen_s(&arqLog, "logWiki.txt", "a+");//Abre o arquivo log
    if (arqLog == NULL && err1 != 0) {
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
        strncpy_s(entrada, MAX_CHAR, lineCommandArq, _TRUNCATE);

        separarComandoE4Palavras(entrada, comandosLinha);

        numFuncion = pesquisaFuncion(comandosLinha[0]);

        logReturn = 0;

        switch (numFuncion)
        {

        case 1://INSEREPAGINA <nome_pagina><nome_arquivo> 
  
            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            strncpy_s(infoEnter.nomeArqPage, MAX_CHAR, comandosLinha[2], _TRUNCATE);

            logReturn = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//Pagina ja existe
            {
                fprintf(arqLog, "PAGINA %s JA EXISTE%s\n", comandosLinha[1]);
            }
            else//Cria pagina
            {
                logReturn = lastPage(wikiPages, infoEnter);

                fprintf(arqLog, "PAGINA %s CRIADA%s\n", comandosLinha[1]);
            }
            break;


        case 2://*RETIRAPAGINA <nome_pagina>: exclui a p�gina da WikED!, 

            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

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
            strncpy_s(nomeEditorEnter.nomeEditor, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            finder = finderEditores(listaEditores, nomeEditorEnter.nomeEditor, &nomeEditorEnter);
            if (finder == 1)//NOME REPETIDO
            {
                fprintf(arqLog, "EDITOR JÁ CADASTRADO - %s\n", comandosLinha[1]);
            }
            else//CADASTRADO EDITOR
            {
                strncpy_s(nomeEditorEnter.nomeEditor, MAX_CHAR, comandosLinha[1], _TRUNCATE);

                logReturn = lastEditores(listaEditores, nomeEditorEnter);//Seta que o nome vai estar aqui

                fprintf(arqLog, "EDITOR CADASTRADO - %s\n", comandosLinha[1]);
            }
            break;

        case 4://RETIRAEDITOR <nome_editor>: 
            //retira um editor com o nome especificado (deve ser único). 
            finder = 0;
            strncpy_s(nomeEditorEnter.nomeEditor, MAX_CHAR, comandosLinha[1], _TRUNCATE);
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

            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (finder == 1)//Pagina Encontrada
            {

                strncpy_s(infosEditEnter.nomeEditor, MAX_CHAR, comandosLinha[2], _TRUNCATE);
                finder = finderEditores(listaEditores, infosEditEnter.nomeEditor, &nomeEditorEnter);
                if (finder == 1)//
                {
                    //Nome da pagina
                    strncpy_s(infosEditEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);
                    //nome editor
                    strncpy_s(infosEditEnter.nomeEditor, MAX_CHAR, comandosLinha[2], _TRUNCATE);
                    //endereço colaboração
                    strncpy_s(infosEditEnter.colab, MAX_CHAR, comandosLinha[3], _TRUNCATE);
                    
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
            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);
            finder = finderPage(wikiPages, infoEnter.nomePage, &infosEditEnter);
            if (finder == 1)//Pagina Encontrada
            {
                finder = 0;
                strncpy_s(infosEditEnter.nomeEditor, MAX_CHAR, comandosLinha[2], _TRUNCATE);
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

                    fprintf(arqLog, "LINK -%s- INSERIDO - PAGINA %s\n", comandosLinha[2],comandosLinha[1]);
                    strcpy_s(logMensagem, MAX_CHAR, "LINK INSERIDO", _TRUNCATE);
                    logReturn = logEdit(arqLog, logMensagem);
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

            //PAREI AQUIs
        case 9:/*CAMINHO <pagina_origem><pagina_destino>: verifica se há caminho entre duas páginas (por meio das
                listas de links). Escreve no arquivo de log (HA/NAO HA CAMINHO DA <pagina_origem> PARA <pagina_destino>)*/
            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

            finder = 0;
            finder = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);//TEORICAMENTE AQUI VAI MUDAR O VALOR DE CURSOR
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

            strncpy_s(infoEnter.nomePage, MAX_CHAR, comandosLinha[1], _TRUNCATE);

            logReturn = finderPage(wikiPages, infoEnter.nomePage, &infoEnter);
            if (logReturn == 1)//Pagina  existe
            {
                TNodoPage* ptrNodoPage = wikiPages->cursor;
                printPageWikiArq(wikiPages, listColab, listaLinks);

            }
            else//PAGINA NO EXISTE
            {
                //NÃO EXISTE PAGINA
                fprintf(arqLog, "PAGINA -%s- No EXISTE\n", comandosLinha[1]);
            }

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


//----------------------------PAREI AQUIIIIIIIIIIIIIIIIIIIIII-------------------------

void printPageWikiArq(TPagina *wikiPages, TEditores* listColab, TListaLinks* listaLinks)
{
    TNodoPage* ptrNodoPage = wikiPages->cursor;

    TNodoEditor* ptrNodoEditor = listColab->inicio;

    TNodoLink* ptrNodoLinks = listaLinks->inicio;
    

    char lineCommandArq[MAX_LINE_LENGTH];

    // Abra o arquivo para adicionar conteúdo
    FILE* arquivo;
    errno_t err = fopen_s(&arquivo, ptrNodoPage->infoP.nomeArqPage, "w+");
    if (err != 0)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreva o texto no arquivo
    fprintf(arquivo, "%s\n", ptrNodoPage->infoP.nomePage);//Nome PAge
    for (int i = 1; i <= listColab->tamanho; i++)//Lista de colaborações e Editores
    {
        if (strcmp(ptrNodoEditor->infoEdit.nomePage, wikiPages->cursor->infoP.nomePage) == 0)
        {
            FILE* arqcolab;
            errno_t err = fopen_s(&arqcolab, ptrNodoEditor->infoEdit.colab, "r");
            if (err != 0)
            {
                printf("Erro ao abrir o arquivo.\n");
                return;
            }
            while (fgets(lineCommandArq, sizeof(lineCommandArq), arqcolab) != NULL){

            fprintf(arquivo, "%s\n", lineCommandArq);//AQUI TEM QUE COPIAR O CONTEUDO DO ARQUIVO 
            fprintf(arquivo, "%s", "Editor.: ");
            fprintf(arquivo, "%s\n", ptrNodoEditor->infoEdit.nomeEditor);
            }
            if (i == listColab->tamanho)
            {
                fclose(arqcolab);
            }
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
}

void closeArq(FILE* nomeArq)
{
    fclose(nomeArq);
}
