#include "WikiEDI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include <ctype.h>


//FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS--------------------------------------------------

//cria uma pagina/arquivo
void creatorFilePage(const char *nomePage, const char *colabName) {
    FILE* arqPage;
    TPageArq page;

    //Preciso descobrir uma forma de não criar um arquivo ja existente; <--ATENÇÃO
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
        printf("\nPagina já existente!!!\n");
        return;
    }

    // Alocar espaço para as strings e copiar os valores
    page.colabName = strlen(colabName) + 1;
    page.nomePage = strlen(nomePage) + 1;

    // Inicialize a estrutura TPageArq como necessário
    page.colabName = colabName;
    page.nomePage = nomePage;
    page.links = NULL;

    printf("\nCriada Pagina - %s!!!\n", page.nomePage);
    printf("\nCriado por.: %s!!!\n", page.colabName);

    
    // Escreva a estrutura no arquivo
    fwrite(&page, sizeof(TPageArq), 1, arqPage);

    // Feche o arquivo
    fclose(arqPage);

    // Liberar a memória alocada
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
        printf("\nColaboração .:!!!\n");

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

//função que vai pegar todas as alterações feitas na memoria 
// alocada e reescrever no arquivo Pagina            
// Função onde planejo conectar arquivo e meloria alocada //<-Não finalizado
void writeFilePage(FILE *arqPage, TPagina *pageUpdate, const char* colabName){

    rewind(arqPage);

    fwrite(&pageUpdate, sizeof(TPageArq), 1, arqPage);
}

//Copia as informações do arquivo para a memoria alocada para Edição <=CONTINUAR AQUI!!!!
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

//Função para manipular o arquivo de log
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

//Função para abrir o arquivo de log
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

//Função que modifica no arquivo logColab, entra

//Função para abrir o arquivo de colaboradores
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

//Remove uma pagina, essa função vai ser compelxa pq não é só apagar, mas tem que conectar 
//a sequencias das outras paginas.
void DestroyerFilePage(const char* nomePage, const char* colabName) {

}

//FUNÇÕES DE ALOCAÇÃO----------------------------------------------------------------

//Função para Alocar a primeira pagina pagina, criar uma pagina na Memoria Alocada
TConteudo* bornColabAlloc() {

    TConteudo*colabAlloc = (TConteudo*)malloc(sizeof(TConteudo));

    if (colabAlloc == NULL)
    {
        printf("\nMemoria não Alocada para A Pagina\n");
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

    //Se não tem espaço apra alocar memorio
    if (fullColabAlloc(colab) == 0)
    {
        printf("\nErro na alocação de memoria para o Nodo da pagina\n");
        free(colab);
        return 0;
    }

    TNodoCont* ptrNodoColab = (TNodoCont*)malloc(sizeof(TNodoCont));
    if (ptrNodoColab == NULL)
    {
        printf("\nErro na alocação de memoria para o Nodo da pagina\n");
        free(ptrNodoColab);
        return 0;
    }

    colab->tamanhoColab++;//É AQUI QUE A MAGICA ACONTECE!!!!! transfor a "born" em "start"
    colab->inicioColab = ptrNodoColab;

    // Aloque memoria para o campo 'nome' e copie o nome
    ptrNodoColab->nomeColab = (char*)malloc(strlen(nomeColab) + 1);
    if (ptrNodoColab->nomeColab == NULL) {
        printf("\nErro na alocação de memória para o nome da página\n");
        free(ptrNodoColab);
        return 0;
    }

    strcpy_s(ptrNodoColab->nomeColab, strlen(nomeColab) + 1, nomeColab); //Nome page

    //ptrNodoPage->info = infoEnter;//É ESSE O CAMINHO, mas ainda não está certo

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

    //Se não tem espaço apra alocar memorio
    if (fullColabAlloc(colab) == 0)
    {
        printf("\nErro na alocação de memoria para o Nodo da colaboração\n");
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
            printf("\nErro na alocação de memória para o nome da página\n");
            free(ptrNodoColab);
            return 0;
        }

        strcpy_s(ptrNodoColab->nomeColab, strlen(nomeColab) + 1, nomeColab); //Nome page

        //ptrNodoPage->info = infoEnter;//É ESSE O CAMINHO, mas ainda não está certo
        ptrNodoColab->nextColab= colab->inicioColab;
        colab->fimColab->nextColab = ptrNodoColab;
        colab->fimColab = ptrNodoColab;
        colab->tamanhoColab;
    }
    return 1;
}

//Função que retorna que nãotem pagina alocada
int emptyColabAlloc(TConteudo *colab){
    return colab->tamanhoColab == 0;
}

//Função com o objetivo de testar se ha espaço para a proxima pagina
int fullColabAlloc(TConteudo* colab) {
    TNodoCont* ptrNodoColab = (TNodoCont*)malloc(sizeof(TNodoCont));
    if (ptrNodoColab == NULL)
    {
        printf("\nSem espaço na memoria para Alocar mais uma pagina\n");
        return 0;
    }
    else
    {
        free(ptrNodoColab);
        return 1;
    }

}

//Função que retorna o tamanho/quantidade de Paginas na Wiki
int sizeColabAlloc(TConteudo* colab) {
    return colab->tamanhoColab;
}

//FUNÇÕES "FUNCIONAIS"----------------------------------------------------------------

//Função que retira o enter das strings
void retiraEnter(char* string) {
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}

//Fazer o teste se existe já colaborador cadastrado, recebe o nome pesquisado
// retorna bool
int checkColab(char* nameColab) {
    FILE* colabFile;
    TColabList colabList;
    openLogFile(colabFile);
    int achou = 0;
    //Pesquisa no arquivo se é um colaborador cadastrado
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

            //Se encontrar o arquivo vai alocar na memoria para edição
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
            //USAR A FUNÇÂO DE ESCREVER NO ARQUIVO LOG
            //Leva para o menu Colaborador
            menuColab(nameColab);//<--------------------menuColab
        }
        else
        {
            achou = 0;

            printf("\nCadastro de colaborador não encotrado!!!");
            //USAR A FUNÇÂO DE ESCREVER NO ARQUIVO LOG

            printf("\n1-SIM | 0-NÃO\nDeseja cadastrar?.:");
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
                        printf("\Colaborador já Cadastrado.: ");
                        printf("\n1-SIM | 0-NÃO\nDeseja cadastrar?.: ");
                        scanf("%d", &cadColab);
                        //USAR A FUNÇÂO DE ESCREVER NO ARQUIVO LOG
                    }
                    else
                    {
                        printf("\Colaborador Cadastrado!!!!");
                        //Função que modifica no arquivo logColab
                        //USAR A FUNÇÂO DE ESCREVER NO ARQUIVO LOG  
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

//Menu de abertura do app, encaminha para a pesquisa, manipulação do arquivi colaborador
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
            //Função que Pinta toda a WikiEDI e não retorna nada
            break;

        default:
            break;
        }
    } while (menu != 4);
}

//Menu teste para as funções bases que manipulam os dados alocados
void menuApp2() {
    const char nomePage[] = "EDI";
    const char texto[] = "Teste da Desgraça!!!!";

    TPagina* EDI;

    TNodoPage* info = 7;

    int menu;

    printf_s("\nOpção menu\n 1-Criar um Pagina da Wiki");
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

//Testa o funcionamento das funções e as interações entre elas
void APP() {
    openLogFile();
    menuEnter();


}

int main() {
    setlocale(LC_ALL, "Portuguese");
    APP();

    return 0;
}
