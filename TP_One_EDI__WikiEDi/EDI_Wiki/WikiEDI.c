#include "WikiEDI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <ctype.h>


//FUN��ES DE MANIPULA��O DE ARQUIVOS--------------------------------------------------

//cria uma pagina/arquivo
void creatorFilePage(const char *nomePage, const char *colabName) {
    FILE* arqPage;
    TPageArq page;

    //Preciso descobrir uma forma de n�o criar um arquivo ja existente; <--ATEN��O
    fopen_s(&arqPage, nomePage, "r+");
    
    if (arqPage == NULL)
    {
        fopen_s(&arqPage, nomePage, "r");
        if (arqPage == NULL)
        {
            printf("\nErro ao CRIAR Pagina!!!\n");
            return 0;
        }
    }
    else
    {
        printf("\nPagina j� existente!!!\n");
        return;
    }

    // Alocar espa�o para as strings e copiar os valores
    page.colabName = strlen(colabName) + 1;
    page.nomePage = strlen(nomePage) + 1;

    // Inicialize a estrutura TPageArq como necess�rio
    page.colabName = colabName;
    page.nomePage = nomePage;
    page.links = NULL;

    printf("\nCriada Pagina - %s!!!\n", page.nomePage);
    printf("\nCriado por.: %s!!!\n", page.colabName);

    
    // Escreva a estrutura no arquivo
    fwrite(&page, sizeof(TPageArq), 1, arqPage);

    // Feche o arquivo
    fclose(arqPage);

    // Liberar a mem�ria alocada
    free(page.colabName);
    free(page.nomePage);

}

//abre uma pagina existente para leitura e escrita, a partir do inicio<---
int *openFilePage(const char* nomePage) {
    FILE* arqOpen;
    TPageArq page;

    fopen_s(&arqOpen, nomePage, "r+");

    if (arqOpen == NULL)
    {
        printf("\nErro ao ABRIR Pagina!!!\n");
        return 0;
    }
    else
    {
        rewind(arqOpen);

        fread(&page, sizeof(TPagina), 1, arqOpen);
        return 1;
    }
}

//ler o conteudo de um arquivo/pagina ja criado. Somente LEITURA
int *readFilePage(const char* nomePage) {
    FILE* arqOpen;
    TPageArq page;

    fopen_s(&arqOpen, nomePage, "r");

    if (arqOpen == NULL)
    {
        printf("\nErro ao LER Pagina!!!\n");
        return 0;
    }
    else
    {
        rewind(arqOpen);
        printf("Pagina de %s!!!\n", page.nomePage);
        printf("Criada por %s!!!\n", page.colabName);
        printf("\nColabora��o .:!!!\n");

        while (fread(&page, sizeof(TPagina), 1, arqOpen) != 1)
        {
            printf("\n%s\n",page.colabWiki);
            printf("Colaborador.: %s!!!\n", page.colabName);
        }
        if (page.links != 0)
        {
            printf("\nLinks.:");
            for (int i = 0; i < page.qtdLinks; i++)
            {
                printf("%s\t",page.links);
            }
        }
        fclose(arqOpen);
        return 1;
    }
}

//fun��o que vai pegar todas as altera��es feitas na memoria 
// alocada e reescrever no arquivo Pagina            
// Fun��o onde planejo conectar arquivo e meloria alocada //<-N�o finalizado
void writeFilePage(FILE *arqPage, TPagina *pageUpdate, const char* colabName){

    rewind(arqPage);

    fwrite(&pageUpdate, sizeof(TPageArq), 1, arqPage);
}

//Copia as informa��es do arquivo para a memoria alocada para Edi��o <=CONTINUAR AQUI!!!!
TConteudo *copyFilePage(FILE* arqPage, TConteudo* conteudo) {
    TPageArq pageFile;
    TNodoCont* ptrColab;
    

    rewind(arqPage);

    printf("Pagina de %s!!!\n", pageFile.nomePage);
    printf("Criada por %s!!!\n", pageFile.colabName);

    while (fread(&pageFile, sizeof(TPageArq), 1, arqPage))
    {
        ptrColab = endColabAlloc();
    }

}

//Fun��o para manipular o arquivo de log
int* openLogFile(FILE* listPageFale) {
    TNodePageFile nodePage;

    listPageFile = fopen_s(&nodePage, listPageFile, "a+");
    if (listPageFile == NULL)
    {
        printf("\nErro ao ABRIR o LOG!!!\n");
        return 0;
    }
    else
    {
        rewind(listPageFile);

        fread(&listPageFile, sizeof(TNodePageFile), 1, listPageFile);
        return 1;
    }
}

int EditListPage(FILE* listaPage) {
    openLogFile();

}

//Fun��o para abrir o arquivo de log
int openLogFile(FILE* logFile) {
     Tlog log;

    logFile = fopen_s(&log, logFile, "a+");

    if (logFile == NULL)
    {
        printf("\nErro ao ABRIR o LOG!!!\n");
        return 0;
    }
    else
    {
        rewind(logFile);

        fread(&log, sizeof(Tlog), 1, logFile);
        return 1;
    }
}

//Fun��o que modifica no arquivo logColab, entra

//Fun��o para abrir o arquivo de colaboradores
int OpenColabList(FILE* colabFile){
    TColabList colabList;

    fopen_s(&colabList, colabFile, "a+");

    if (colabFile == NULL)
    {
        printf("\nErro ao ABRIR a lista de colaboradores!!!\n");
        return 0;
    }
    else
    {
        rewind(colabFile);

        fread(&colabList, sizeof(TColabList), 1, colabFile);
        return 1;
    }
}

//Remove uma pagina, essa fun��o vai ser compelxa pq n�o � s� apagar, mas tem que conectar 
//a sequencias das outras paginas.
void DestroyerFilePage(const char* nomePage, const char* colabName) {

}

//FUN��ES DE ALOCA��O----------------------------------------------------------------

//Fun��o para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
TConteudo* bornColabAlloc() {

    TConteudo*colabAlloc = (TConteudo*)malloc(sizeof(TConteudo));

    if (colabAlloc == NULL)
    {
        printf("\nMemoria n�o Alocada para A Pagina\n");
        return 0;
    }
    else
    {
        colabAlloc->tamanhoColab = 0;
        colabAlloc->inicioColab = NULL;
        colabAlloc->cursorColab = NULL;
        colabAlloc->fimColab = NULL;
        colabAlloc->posicaoCorrenteColab = 0;

        return colabAlloc;
    }
}

//Criar a primeira Pagina da lista;
int firstColabAlloc(TConteudo* colab, char* nomeColab, TNodoCont infoEnter) {

    //Se n�o tem espa�o apra alocar memorio
    if (fullColabAlloc(colab) == 0)
    {
        printf("\nErro na aloca��o de memoria para o Nodo da pagina\n");
        free(colab);
        return 0;
    }

    TNodoCont* ptrNodoColab = (TNodoCont*)malloc(sizeof(TNodoCont));
    if (ptrNodoColab == NULL)
    {
        printf("\nErro na aloca��o de memoria para o Nodo da pagina\n");
        free(ptrNodoColab);
        return 0;
    }

    colab->tamanhoColab++;//� AQUI QUE A MAGICA ACONTECE!!!!! transfor a "born" em "start"
    colab->inicioColab = ptrNodoColab;

    // Aloque memoria para o campo 'nome' e copie o nome
    ptrNodoColab->nomeColab = (char*)malloc(strlen(nomeColab) + 1);
    if (ptrNodoColab->nomeColab == NULL) {
        printf("\nErro na aloca��o de mem�ria para o nome da p�gina\n");
        free(ptrNodoColab);
        return 0;
    }

    strcpy_s(ptrNodoColab->nomeColab, strlen(nomeColab) + 1, nomeColab); //Nome page

    //ptrNodoPage->info = infoEnter;//� ESSE O CAMINHO, mas ainda n�o est� certo

    if (colab->tamanhoColab == 1)
    {
        colab->fimColab = ptrNodoColab;
        colab->cursorColab = ptrNodoColab;
        ptrNodoColab->nextColab= ptrNodoColab;        
    }
    else
    {
        ptrNodoColab->nextColab = colab->inicioColab;
        colab->fimColab = ptrNodoColab;
    }
    return 1;
}

//ciar a proxima pagina da lista duplamente encadeada
int endColabAlloc(TConteudo* colab, char* nomeColab, TNodoCont infoEnter) {
    TNodoCont* ptrNodoColab;

    //Se n�o tem espa�o apra alocar memorio
    if (fullColabAlloc(colab) == 0)
    {
        printf("\nErro na aloca��o de memoria para o Nodo da colabora��o\n");
        free(colab);
        return 0;
    }

    if (colab->inicioColab == NULL)
    {
        startPageAlloc(colab, nomeColab, infoEnter);
    }
    else
    {
        ptrNodoColab = (TNodoCont*)malloc(sizeof(TNodoCont));

        // Aloque memoria para o campo 'nome' e copie o nome
        ptrNodoColab->nomeColab = (char*)malloc(strlen(nomeColab) + 1);
        if (ptrNodoColab->nomeColab== NULL) {
            printf("\nErro na aloca��o de mem�ria para o nome da p�gina\n");
            free(ptrNodoColab);
            return 0;
        }

        strcpy_s(ptrNodoColab->nomeColab, strlen(nomeColab) + 1, nomeColab); //Nome page

        //ptrNodoPage->info = infoEnter;//� ESSE O CAMINHO, mas ainda n�o est� certo
        ptrNodoColab->nextColab= colab->inicioColab;
        colab->fimColab->nextColab = ptrNodoColab;
        colab->fimColab = ptrNodoColab;
        colab->tamanhoColab;
    }
    return 1;
}

//Fun��o que retorna que n�otem pagina alocada
int emptyColabAlloc(TConteudo *colab){
    return colab->tamanhoColab == 0;
}

//Fun��o com o objetivo de testar se ha espa�o para a proxima pagina
int fullColabAlloc(TConteudo* colab) {
    TNodoCont* ptrNodoColab = (TNodoCont*)malloc(sizeof(TNodoCont));
    if (ptrNodoColab == NULL)
    {
        printf("\nSem espa�o na memoria para Alocar mais uma pagina\n");
        return 0;
    }
    else
    {
        free(ptrNodoColab);
        return 1;
    }

}

//Fun��o que retorna o tamanho/quantidade de Paginas na Wiki
int sizeColabAlloc(TConteudo* colab) {
    return colab->tamanhoColab;
}

//FUN��ES "FUNCIONAIS"----------------------------------------------------------------

//Fun��o que retira o enter das strings
void retiraEnter(char* string) {
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}

//Fazer o teste se existe j� colaborador cadastrado, recebe o nome pesquisado
// retorna bool
int checkColab(char* nameColab) {
    FILE* colabFile;
    TColabList colabList;
    openLogFile(colabFile);
    int achou = 0;
    //Pesquisa no arquivo se � um colaborador cadastrado
    while (fread(&colabList, sizeof(TColabList), 1, colabFile));
    {
        if (strcmp(colabList.nameColab, nameColab) == 0)
        {
            return 1;
        }
    }
    return 0;
}

//Menu para colaboradores
void menuColab(char nameColab) {
    TConteudo *page;
    TNodoCont *nodoPage;

    int menu;
    char* nomePage;
    int sair;

    page = bornPageAlloc();

    printf("\n==================================================\n");
    printf("\n===================EDI-WikiEDI====================\n");
    printf("\n==================================================\n");
    printf("\n1-Criar pagina | 2-Editar(colaborar) pagina| 3-Imprimir Toda WikiEDI | 4-Sair.: \n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1: //Criar um Pagina da Wiki
        printf("\nColaborador-&s - Nome Pagina.: ",nameColab);//Insira o nome da pagina
        setbuf(stdin, NULL);
        fgets(nomePage, 50, stdin);
        retiraEnter(nomePage);
        setbuf(stdin, NULL);

        creatorFilePage(nomePage, nameColab);
        break;

    case 2: //Editar(colaborar) pagina
        do
        {
            printf("\nColaborador-&s - Nome Pagina.: ", nameColab);//Insira o nome da pagina
            setbuf(stdin, NULL);
            fgets(nomePage, 50, stdin);
            retiraEnter(nomePage);
            setbuf(stdin, NULL);

            //Se encontrar o arquivo vai alocar na memoria para edi��o
            if ((readFilePage(nomePage)) == 1)
            {
                openLogFile(nomePage);

                copyFilePage(nomePage);


            }

        } while (sair != 3);
        break;
    default:
        break;
    }



    /*
    int menu;

    printf_s("\nOp��o menu\n 1-Criar Pagina\n2-Abrir Arquivo\n3-Ler");
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

//Cadastro/login de colaborador ATNCION: COMO REMOVER COLABORADOR?
char loginModifyiColabName() {
    FILE* colabFile;
    TColabList colabList;
    openLogFile(colabFile);
    int achou = 0;
    char* nameColab;
    int cadColab;
    int sair;

    do
    {
        printf("\Login colaborador.: ");
        setbuf(stdin, NULL);
        fgets(nameColab, 50, stdin);
        retiraEnter(nameColab);
        setbuf(stdin, NULL);

        achou = checkColab(nameColab);
        if (achou == 1)
        {
            printf("\nLogin DONE!!!");
            //USAR A FUN��O DE ESCREVER NO ARQUIVO LOG
            //Leva para o menu Colaborador
            menuColab(nameColab);//<--------------------menuColab
        }
        else
        {
            achou = 0;

            printf("\nCadastro de colaborador n�o encotrado!!!");
            //USAR A FUN��O DE ESCREVER NO ARQUIVO LOG

            printf("\n1-SIM | 0-N�O\nDeseja cadastrar?.:");
            scanf("%d", &cadColab);
            while (cadColab != 0)
            {
                do
                {
                    printf("\Cadastro colaborador.: ");
                    setbuf(stdin, NULL);
                    fgets(nameColab, 50, stdin);
                    retiraEnter(nameColab);
                    setbuf(stdin, NULL);

                    achou = checkColab(nameColab);

                    if (achou = 1)
                    {
                        printf("\Colaborador j� Cadastrado.: ");
                        printf("\n1-SIM | 0-N�O\nDeseja cadastrar?.: ");
                        scanf("%d", &cadColab);
                        //USAR A FUN��O DE ESCREVER NO ARQUIVO LOG
                    }
                    else
                    {
                        printf("\Colaborador Cadastrado!!!!");
                        //Fun��o que modifica no arquivo logColab
                        //USAR A FUN��O DE ESCREVER NO ARQUIVO LOG  
                        menuColab(nameColab);//<--------------------menuColab
                    }
                } while (cadColab != 0);            
            }
        }
        printf("\n1-Tentar novamente | 0-SAIR\n");
        scanf("%d", &sair);
    } while (sair != 0);

    fclose(colabFile);
    return 0;
}

//Menu de abertura do app, encaminha para a pesquisa, manipula��o do arquivi colaborador
void menuEnter() {
    const int menu;
    char *conteudo;
    const int Log;
    const int checkColab;
    const int sair;

    printf("\n==================================================\n");
    printf("\n===================EDI-WikiEDI====================\n");
    printf("\n==================================================\n");
    printf("\n1-Pesquisar | 2-Login/Cadastro Colaborador | 3-Imprimir Toda WikiEDI | 4-Sair.: \n");
    scanf("%d", &menu);

    do
    {
        switch (menu)
        {
        case 1:// Pesquisa pagina
            do
            {
                printf("\nQual conteudo deseja pesquisar.:\n");//Insira o nome da pagina
                setbuf(stdin, NULL);
                fgets(conteudo, 10, stdin);
                retiraEnter(conteudo);
                setbuf(stdin, NULL);
                readFilePage(conteudo);
                printf("\n1-Tentar novamente | 0-SAIR\n");
                scanf("%d", &sair);
            } while (sair != 0);
            break;

        case 2://Login/Cadastro Colaborador
            loginModifyiColabName();            
            break;

        case 3://Print toda A Wiki
            //Fun��o que Pinta toda a WikiEDI e n�o retorna nada
            break;

        default:
            break;
        }
    } while (menu != 4);
}

//Menu teste para as fun��es bases que manipulam os dados alocados
void menuApp2() {
    const char nomePage[] = "EDI";
    const char texto[] = "Teste da Desgra�a!!!!";

    TPagina* EDI;

    TNodoPage* info = 7;

    int menu;

    printf_s("\nOp��o menu\n 1-Criar um Pagina da Wiki");
    scanf_s("%d", &menu);
    switch (menu)
    {
    case 1: //Criar um Pagina da Wiki
        //Insira o nome da pagina


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

//Testa o funcionamento das fun��es e as intera��es entre elas
void APP() {
    openLogFile();
    menuEnter();


}

int main() {
    setlocale(LC_ALL, "Portuguese");
    APP();

    return 0;
}
