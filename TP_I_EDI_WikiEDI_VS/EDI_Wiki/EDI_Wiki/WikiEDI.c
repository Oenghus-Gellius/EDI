#include "WikiEDI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <ctype.h>


//FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS--------------------------------------------------

//cria uma pagina/arquivo
void creatorFilePage(const char nomePage, const char colabName) {
    FILE* arqPage;
    TPageArq page;

    //Preciso descobrir uma forma de não criar um arquivo ja existente; <--ATENÇÃO
    fopen_s(&arqPage, nomePage, "r+");
    
    if (arqPage == NULL)
    {
        printf("\nCriada Pagina - %s!!!\n", nomePage);
        fopen_s(&arqPage, nomePage, "r");
        if (arqPage == NULL)
        {
            printf("\nErro ao CRIAR Pagina!!!\n");
            return 0;
        }
    }
    else
    {
        printf("\nPagina já existente!!!\n");
        return;
    }

    // Inicialize a estrutura TPageArq como necessário
    page.colabName = colabName;
    page.nomePage = nomePage;
    
    // Escreva a estrutura no arquivo
    fwrite(&page, sizeof(TPageArq), 1, arqPage);

    // Feche o arquivo
    fclose(arqPage);
}

//abre uma pagina existente para leitura e escrita, a partir do inicio<---
void openFilePage(const char* nomePage) {
    FILE* arqOpen;
    TPageArq page;

    fopen_s(&arqOpen, nomePage, "r+");

    if (arqOpen == NULL)
    {
        printf("\nErro ao ABRIR Pagina!!!\n");
        return;
    }
    else
    {
        rewind(arqOpen);

        fread(&page, sizeof(TPagina), 1, arqOpen);


         printf("\nPagina %s aberta Função OPEN!!!\n",page.nomePage);
    }
}

//ler o conteudo de um arquivo/pagina ja criado. Somente LEITURA
void readFilePage(const char* nomePage) {
    FILE* arqOpen;
    TPageArq page;


    fopen_s(&arqOpen, nomePage, "r");

    if (arqOpen == NULL)
    {
        printf("\nErro ao LER Pagina!!!\n");
        return;
    }
    else
    {
        rewind(arqOpen);

        fread(&page, sizeof(TPagina), 1, arqOpen);


        printf("\nPagina de %s aberta pela funçaõ LER!!!\n", page.nomePage);
    }
}

//função que vai pegar todas as alterações feitas na memoria 
// alocada e reescrever no arquivo Pagina                         <=NÃO TERMINADO
void writeFilePage(FILE *arqPage, TPagina *pageUpdate, TNodoPage *nodoPageUpdate) { //<---- Função onde planejo conectar arquivo e meloria alocada
    TPagina page;


    rewind(arqPage);                                    //SERA?

    fwrite(&pageUpdate, sizeof(TPagina), 1, arqPage);

    fwrite(&nodoPageUpdate, sizeof(TNodoPage), 1, arqPage);

}


//Remove uma pagina, essa função vai ser compelxa pq não é só apagar, mas tem que conectar 
//a sequencias das outras paginas.
void DestroyerFilePage(const char* nomePage) {

}

//FUNÇÕES DE ALOCAÇÃO----------------------------------------------------------------

//Função para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
TPagina* bornPageAlloc() {

    TPagina *pageAlloc = (TPagina*)malloc(sizeof(TPagina));

    if (pageAlloc == NULL)
    {
        printf("\nMemoria não Alocada para A Pagina\n");
        return 0;
    }
    else
    {
        pageAlloc->quantidade = 0;
        pageAlloc->inicio = NULL;
        pageAlloc->cursor = NULL;
        pageAlloc->fim = NULL;
        pageAlloc->posicaoCorrente = 0;

        return pageAlloc;
    }
}

//Criar a primeira Pagina da lista;
int startPageAlloc(TPagina* page, char* nomePage, TNodoPage infoEnter) {

    //Se não tem espaço apra alocar memorio
    if (fullPageAlloc(page) == 0)
    {
        printf("\nErro na alocação de memoria para o Nodo da pagina\n");
        free(page);
        return 0;
    }

    TNodoPage* ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));
    if (page == NULL)
    {
        printf("\nErro na alocação de memoria para o Nodo da pagina\n");
        free(page);
        return 0;
    }

    page->quantidade++;//É AQUI QUE A MAGICA ACONTECE!!!!! transfor a "born" em "start"
    page->inicio = ptrNodoPage;

    // Aloque memoria para o campo 'nome' e copie o nome
    ptrNodoPage->nomePage = (char*)malloc(strlen(nomePage) + 1);
    if (ptrNodoPage->nomePage == NULL) {
        printf("\nErro na alocação de memória para o nome da página\n");
        free(ptrNodoPage);
        return 0;
    }

    strcpy_s(ptrNodoPage->nomePage, strlen(nomePage) + 1, nomePage); //Nome page

    //ptrNodoPage->info = infoEnter;//É ESSE O CAMINHO, mas ainda não está certo

    if (page->quantidade == 1)
    {
        page->fim = ptrNodoPage;
        page->cursor = ptrNodoPage;
        ptrNodoPage->nextPage = ptrNodoPage;        
    }
    else
    {
        ptrNodoPage->nextPage = page->inicio;
        page->fim = ptrNodoPage;
    }
    return 1;
}

//ciar a proxima pagina da lista duplamente encadeada
int endPageAlloc(TPagina* page, char* nomePage, TNodoPage infoEnter) {
    TNodoPage* ptrNodoPage;

    //Se não tem espaço apra alocar memorio
    if (fullPageAlloc(page) == 0)
    {
        printf("\nErro na alocação de memoria para o Nodo da pagina\n");
        free(page);
        return 0;
    }

    if (page->inicio == NULL)
    {
        startPageAlloc(page, nomePage, infoEnter);
    }
    else
    {
        ptrNodoPage = (TNodoPage*)malloc(sizeof(TNodoPage));

        // Aloque memoria para o campo 'nome' e copie o nome
        ptrNodoPage->nomePage = (char*)malloc(strlen(nomePage) + 1);
        if (ptrNodoPage->nomePage == NULL) {
            printf("\nErro na alocação de memória para o nome da página\n");
            free(ptrNodoPage);
            return 0;
        }

        strcpy_s(ptrNodoPage->nomePage, strlen(nomePage) + 1, nomePage); //Nome page

        //ptrNodoPage->info = infoEnter;//É ESSE O CAMINHO, mas ainda não está certo
        ptrNodoPage->nextPage = page->inicio;
        page->fim->nextPage = ptrNodoPage;
        page->fim = ptrNodoPage;
        page->quantidade++;
    }
    return 1;
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
        return 0;
    }
    else
    {
        free(ptrTNodoPageAlloc);
        return 1;
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
    const char colabA[] = "Oenghus";
    const char colabtextoA[] = "Teste da Desgraça!!!!";

    creatorFilePage(nomePage, colabA);

    // readFilePage(nomePage);

    openFilePage(nomePage);






    
    
    /*
    int menu;

    printf_s("\nOpção menu\n 1-Criar Pagina\n2-Abrir Arquivo\n3-Ler");
    scanf_s("%d", &menu);
    switch (menu)
    {
    case 1: //Criar um arquivo/Pagina da Wiki
        ;
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
    */
}

//Menu teste para as funções bases que manipulam os dados alocados
void menuApp2() {
    const char nomePage[] = "EDI";
    const char texto[] = "Teste da Desgraça!!!!";

    TPagina *EDI = bornPageAlloc();

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
