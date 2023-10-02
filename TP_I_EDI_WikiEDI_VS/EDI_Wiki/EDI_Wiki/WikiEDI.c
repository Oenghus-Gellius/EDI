#include "WikiEDI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <ctype.h>

#define MAX_TAM_STR 100

//FUN��ES DE MANIPULA��O DE ARQUIVOS-----------------------

//cria uma pagina/arquivo <---Incompleta
void creatorFilePage(const char* nomePage) {
    FILE* arqPage;
    TPagina pagina;
    TNodoPage nodoPagina;

    //Preciso descobrir uma forma de n�o criar um arquivo ja existente; <--ATEN��O

    fopen_s(&arqPage, nomePage, "wb");

    if (arqPage == NULL)
    {
        printf("\nErro ao CRIAR Pagina!!!\n");
        return;
    }

    printf("\nCriada Pagina - %s!!!\n", nomePage);

    // Inicialize a estrutura Tpagina como necess�rio
    pagina.quantidade = 1;//Controle de quantas paginas existem na Wiki
    pagina.posicaoCorrente = 0;//posiciona a pagina na lista de paginas
    //pagina.inicio = NULL;
    //pagina.cursor = NULL;
    pagina.teste[0] = '\0';
    strcpy_s(pagina.teste, 50,"TEXTO TESTE DA DESGRA�A!!!!");

    // Escreva a estrutura no arquivo
    fwrite(&pagina, sizeof(TPagina), 1, arqPage);

    if (pagina.quantidade > 0)
    {
        //Inicializando a estrutura TNodopage como necessario
        nodoPagina.nomePage[0] = '\0';
        strcpy_s(nodoPagina.nomePage, 10, "PAGENOME");
        fwrite(&nodoPagina, sizeof(TNodoPage), 1, arqPage);
    }

    printf("\nPagina.:%s!!!\n", nodoPagina.nomePage);
    printf("\nTexto de Cria��o.:\n%s!!!\n", pagina.teste);

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

         printf("\nPagina de %s aberta Fun��o OPEN!!!\n",nodoPage.nomePage);
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

        printf("\nPagina de %s aberta fun�a� LER!!!\n", nodoPage.nomePage);
    }
}

//fun��o que vai pegar todas as altera��es feitas e reescrever no arquivo
void writeFilePage(FILE *arqPage) {
    


}
//Remove uma pagina, essa fun��o vai ser compelxa pq n�o � s� apagar, mas tem que conectar 
//a sequencias das outras paginas.
void DestroyerFilePage(const char* nomePage) {

}

//FUN��ES "FUNCIONAIS"----------------

//Testa o funcionamento das fun��es e as intera��es entre elas
void APPTest() {
    const char nomePage[] = "EDI";
    const char texto[] = "Teste da Desgra�a!!!!";
    int menu;//Fazer uma fun��o para o menu

    FILE* file;
    TPagina pagina;

    printf_s("\nOp��o menu\n 1-Criar Pagina\n2-Abrir Arquivo\n3-Ler");
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

int main() {
    setlocale(LC_ALL, "Portuguese");
    APPTest();

    return 0;
}
