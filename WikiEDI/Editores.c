#include "Editores.h"


#include "Links.h"

TEditores* bornListEditores()
{
    TEditores* listColab = (TEditores*)malloc(sizeof(TEditores));
    if (listColab != NULL)
    {
        listColab->inicio = NULL;
        listColab->fim = NULL;
        listColab->tamanho = 0;
    }
    return listColab;
}

int firstEditores(TEditores* listColab, TConteudoEdit infosEdit)
{
    // fazer que a fun��o fullLinks retorne -1 se estiver cheia
    if (fullEditores(listColab) == -1)
    {
        printf("\nErro na alocacao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(listColab);
        return 0;
    }

    TNodoEditor* ptrTNodoEditor = (TNodoEditor*)malloc(sizeof(TNodoEditor));
    if (ptrTNodoEditor == NULL)
    {
        printf("\nErro na alocao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return 0;
    }
    else
    {
        ptrTNodoEditor->infoEdit = infosEdit;
        //strncpy_s(ptrTNodoEditor, MAX_CHAR, infosEdit, _TRUNCATE);


        ptrTNodoEditor->nextEditor = NULL;
        listColab->inicio = ptrTNodoEditor;
        listColab->tamanho++;
        listColab->fim = ptrTNodoEditor;
        return 1;
    }
}

int lastEditores(TEditores* listColab, TConteudoEdit infosEdit)
{
    // fazer que a fun��o fullLinks retorne -1 se estiver cheia
    if (fullEditores(listColab) == -1)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(listColab);
        return 0;
    }

    TNodoEditor* ptrTNodoEditor = (TNodoEditor*)malloc(sizeof(TNodoEditor));
    if (ptrTNodoEditor == NULL)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        free(listColab);
        return 0;
    }
    else
    {
        ptrTNodoEditor->nextEditor = NULL;

        //verificando se a TListaEditores está vazia
        if (listColab->inicio == NULL)
        {
            firstEditores(listColab, infosEdit);
            free(ptrTNodoEditor);
        }
        else
        {
            ptrTNodoEditor->infoEdit = infosEdit;
            //strncpy_s(ptrTNodoEditor, MAX_CHAR, infosEdit, _TRUNCATE);

            listColab->fim->nextEditor = ptrTNodoEditor;
            listColab->fim = ptrTNodoEditor;
            listColab->tamanho++;
        }
        return 1;
    }
}

int removeEditores(TEditores* listColab, char* nomeEditor, TConteudoEdit* infosEdit)
{
    TNodoEditor* ptrTNodoEditor, * ptrBackLinks;
    ptrTNodoEditor = listColab->inicio;
    ptrBackLinks = NULL;

    while (listColab != NULL)
    {
        if (strcmp(ptrTNodoEditor->infoEdit.nomeEditor, nomeEditor) == 0)
        {
            //Verifica se � o primeiro
            if (ptrTNodoEditor == listColab->inicio)
            {
                listColab->inicio = listColab->inicio->nextEditor;
            }
            else
                if (ptrTNodoEditor == listColab->fim)//remove o ultimo
                {
                    listColab->fim = ptrBackLinks;
                    listColab->fim->nextEditor = NULL;
                }
                else
                {
                    ptrBackLinks->nextEditor = ptrTNodoEditor->nextEditor;
                }
            free(ptrTNodoEditor);
            listColab->tamanho--;

            return 1;
        }
        else
        {
            ptrBackLinks = ptrTNodoEditor;
            ptrTNodoEditor = ptrTNodoEditor->nextEditor;
        }
    }
    return 0;
}

int finderEditores(TEditores* listColab, char* nomeEditor, TConteudoEdit* infosEdit)
{
    TNodoEditor* ptrTNodoEditor;
    ptrTNodoEditor = listColab->inicio;

    while (ptrTNodoEditor != NULL)
    {
        if (strcmp(ptrTNodoEditor->infoEdit.nomeEditor, nomeEditor) == 0)
        {
            //links = ptrTLinks->infoP.nomeEditor;
            //listColab->cursor = ptrTLinks;//QUERO USARO CURSOR PARA TER O ENDEREÇO PESQUISARO PARA EDITAR A PAGINA
            return 1;
        }
        ptrTNodoEditor = ptrTNodoEditor->nextEditor;
    }
    return 0;
}

int emptyEditores(TEditores* listColab)
{
    return !listColab->inicio;
}

int fullEditores(TEditores* listColab)
{
    TNodoEditor* ptrTNodoEditor = (TNodoEditor*)malloc(sizeof(TNodoEditor));
    if (ptrTNodoEditor == NULL)
    {
        printf("\nErro na alocaao de memoria para a pagina - I'm at line %d\n", __LINE__);
        return -1;
    }
    free(ptrTNodoEditor);
    return 0;
}


int quantityEditores(TEditores* listColab)
{
    return listColab->tamanho;

}

void freeEditors(TEditores* listaEditores) {
    TNodoEditor* currentNode = listaEditores->inicio;
    while (currentNode != NULL) {
        TNodoEditor* temp = currentNode;
        currentNode = currentNode->nextEditor;
        free(temp);
    }
    free(listaEditores);
}


void freeContributions(TEditores* listColab) {
    TNodoEditor* currentNode = listColab->inicio;
    while (currentNode != NULL) {
        TNodoEditor* temp = currentNode;
        currentNode = currentNode->nextEditor;
        free(temp);
    }
    free(listColab);
}

