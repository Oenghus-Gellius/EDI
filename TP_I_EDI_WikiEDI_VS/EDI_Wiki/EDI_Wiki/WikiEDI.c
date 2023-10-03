#include "WikiEDI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <ctype.h>

#define MAX_TAM_STR 100

//FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS--------------------------------------------------

//cria uma pagina/arquivo <---Incompleta
void creatorFilePage(const char* nomePage) {
    FILE* arqPage;
    TPagina pagina;
    TNodoPage nodoPagina;

    //Preciso descobrir uma forma de não criar um arquivo ja existente; <--ATENÇÃO

    fopen_s(&arqPage, nomePage, "wb");

    if (arqPage == NULL)
    {
        printf("\nErro ao CRIAR Pagina!!!\n");
        return;
    }

    printf("\nCriada Pagina - %s!!!\n", nomePage);

    // Inicialize a estrutura Tpagina como necessário
    pagina.quantidade = 1;//Controle de quantas paginas existem na Wiki
    pagina.posicaoCorrente = 0;//posiciona a pagina na lista de paginas
    //pagina.inicio = NULL;
    //pagina.cursor = NULL;
    pagina.teste[0] = '\0';
    strcpy_s(pagina.teste, 50,"TEXTO TESTE DA DESGRAÇA!!!!");

    // Escreva a estrutura no arquivo
    fwrite(&pagina, sizeof(TPagina), 1, arqPage);

    if (pagina.quantidade > 0)
    {
        //Inicializando a estrutura TNodopage como necessario
        nodoPagina.nomePage[0] = '\0';
        strcpy_s(nodoPagina.nomePage, 5, nomePage);
        fwrite(&nodoPagina, sizeof(TNodoPage), 1, arqPage);
    }

    printf("\nPagina.:%s!!!\n", nodoPagina.nomePage);
    printf("\nTexto de Criação.:\n%s!!!\n", pagina.teste);

    // Feche o arquivo
    fclose(arqPage);
}

//abre uma pagina existente para leitura e escrita, a partir do inicio<---
void openFilePage(const char* nomePage) {
    FILE* arqOpen;
    TPagina page;
    TNodoPage nodoPage;

    fopen_s(&arqOpen, nomePage, "rb+");

    if (arqOpen == NULL)
    {
        printf("\nErro ao ABRIR Pagina!!!\n");
        return;
    }
    else
    {
        rewind(arqOpen);

        fread(&page, sizeof(TPagina), 1, arqOpen);

        if (page.quantidade > 0)
        {
            fread(&nodoPage, sizeof(TNodoPage), 1, arqOpen);
        }

         printf("\nPagina de %s aberta Função OPEN!!!\n",nodoPage.nomePage);
    }
}

//ler o conteudo de um arquivo/pagina ja criado. Somente LEITURA
void readFilePage(const char* nomePage) {
    FILE* arqOpen;
    TPagina page;
    TNodoPage nodoPage;

    fopen_s(&arqOpen, nomePage, "rb+");

    if (arqOpen == NULL)
    {
        printf("\nErro ao LER Pagina!!!\n");
        return;
    }
    else
    {
        rewind(arqOpen);

        fread(&page, sizeof(TPagina), 1, arqOpen);

        if (page.quantidade > 0)
        {
            fread(&nodoPage, sizeof(TNodoPage), 1, arqOpen);
        }

        printf("\nPagina de %s aberta pela funçaõ LER!!!\n", nodoPage.nomePage);
    }
}

//função que vai pegar todas as alterações feitas na memoria 
// alocada e reescrever no arquivo Pagina                         <=NÃO TERMINADO
void writeFilePage(FILE *arqPage, TPagina *pageUpdate) { //<---- Função onde planejo conectar arquivo e meloria alocada
    TPagina page;
    TNodoPage nodoPage;


}



//Remove uma pagina, essa função vai ser compelxa pq não é só apagar, mas tem que conectar 
//a sequencias das outras paginas.
void DestroyerFilePage(const char* nomePage) {

}

//FUNÇÕES DE ALOCAÇÃO----------------------------------------------------------------

//Função para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
//NÂO SEI PQ NÂO PODE SER DIRETO EM POR NO FIM OU NO INICIO
TPagina* firstPageAlloc() {

    TPagina *pageAlloc = (TPagina*)malloc(sizeof(TPagina));

    if (pageAlloc == NULL)
    {
        printf("\nMemoria não Alocada para A Pagina\n");
        return 0;
    }
    else
    {
        pageAlloc->inicio = NULL;
        pageAlloc->cursor = NULL;

        pageAlloc->quantidade = 0;
        pageAlloc->posicaoCorrente = 0;
        pageAlloc->teste[0] = "\0";//Remover apos finalizar programa
        return pageAlloc;
    }
}

//Criar a primeira Pagina da lista;
int startPageAlloc(TPagina* page, TNodoPage* info) {

    TNodoPage* nodoPageAlloc = (TNodoPage*)malloc(sizeof(TNodoPage));

    if (page == NULL)
    {
        printf("\nErro na alocação de memoria para o Nodo da pagina\n");
        free(page);
        return 0;
    }
    else
    {
        page->quantidade++;//É AQUI QUE A MAGICA ACONTECE!!!!! transfor a "first" em "start"

        //nodoPageAlloc->nomePage[0] = '\0';//Como colocar o nome no arquivo?

        page->teste[0] = "\0";//SÒ PARA TESTER AS FUNÇÔES 

        if (page->quantidade == 1)
        {
            nodoPageAlloc->backPage = nodoPageAlloc;
            nodoPageAlloc->nextPage = nodoPageAlloc;
        }
        else
        {
            page->inicio->backPage->nextPage = nodoPageAlloc;
            page->inicio->backPage = nodoPageAlloc;

            nodoPageAlloc->nextPage = page->inicio->nextPage;//Acho que está errado!!!!
            nodoPageAlloc->backPage = page->inicio->backPage;
        }
        page->inicio = nodoPageAlloc;

        return 1;
    }
}

//ciar a proxima pagina da lista duplamente encadeada
int headPageAlloc(TPagina* page, TNodoPage* info) {
    TNodoPage* nodoPageAlloc;

    char nomePage[5] = "EDI";

    if (fullPageAlloc(page))//checa se tem espaço para alocar
    {
        return 0;
    }

    if (page->inicio == NULL)//Inicia a wiki por ser a primeira pagina
    {
        return startPageAlloc(page, info);
    }
    else
    {
        nodoPageAlloc = (TNodoPage*)malloc(sizeof(TNodoPage));

        nodoPageAlloc->nomePage[4] = nomePage[4];
        nodoPageAlloc->backPage = page->inicio->backPage;
        nodoPageAlloc->nextPage = page->inicio;
        page->inicio->backPage->nextPage = nodoPageAlloc;
        page->inicio->backPage = nodoPageAlloc;
        page->quantidade++;
        return 1;
    }
}

//Função que retorna que nãotem pagina alocada
int noPageAlloc(TPagina *page) {
    return page->quantidade == 0;
}

//Função com o objetivo de testar se ha espaço para a proxima pagina
int fullPageAlloc(TPagina* page) {
    TNodoPage* ptrTNodoPageAlloc = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (ptrTNodoPageAlloc == NULL)
    {
        printf("\nSem espaço na memoria para Alocar mais uma pagina\n");
        return 1;
    }
    else
    {
        free(ptrTNodoPageAlloc);
        return 0;
    }

}

//Função que retorna o tamanho/quantidade de Paginas na Wiki
int sizePageAlloc(TPagina* page) {
    return page->quantidade;
}

//FUNÇÕES "FUNCIONAIS"----------------------------------------------------------------

//Menu teste para as funções que manipula o Arquivo
void menuApp1() {
    const char nomePage[] = "EDI";
    const char texto[] = "Teste da Desgraça!!!!";

    int menu;

    printf_s("\nOpção menu\n 1-Criar Pagina\n2-Abrir Arquivo\n3-Ler");
    scanf_s("%d", &menu);
    switch (menu)
    {
    case 1: //Criar um arquivo/Pagina da Wiki
        creatorFilePage(nomePage);
        break;

    case 2: //Abrir um arquivo/Pagina da Wiki
        openFilePage(nomePage);
        break;

    case 3: //Ler uma arquivo/Pagina da wiki
        readFilePage(nomePage);
        break;

    default:
        break;
    }
}

//Menu teste para as funções bases que manipulam os dados alocados
void menuApp2() {
    const char nomePage[] = "EDI";
    const char texto[] = "Teste da Desgraça!!!!";

    TPagina *EDI = firstPageAlloc();

    TNodoPage* info = 7;


    int menu;

    printf_s("\nOpção menu\n 1-Criar um Pagina da Wiki");
    scanf_s("%d", &menu);
    switch (menu)
    {
    case 1: //Criar um Pagina da Wiki
        //Insira o nome da pagina
        headPageAlloc(EDI, info);

        //srtcpy(EDI->teste, texto);

        //srtcpy(info->nomePage, nomePage);


        printf("\nNome da Pagina.: %s\n",info->nomePage);


        printf("\nTexto  em Pagina teste.: %s\n", EDI->teste);






        break;

    case 2: //Abrir um arquivo/Pagina da Wiki

        break;

    case 3: //Ler uma arquivo/Pagina da wiki

        break;

    default:
        break;
    }

}

//Testa o funcionamento das funções e as interações entre elas
void APPTest() {
    FILE* file;
    TPagina pagina;

    //menuApp1();

    menuApp2();
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    APPTest();

    return 0;
}
