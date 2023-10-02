#include "WikiEDI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

#define MAX_TAM_STR 100

//FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS-----------------------

//cria uma pagina (se for un colaborador)
void *creatorPage(const char *nomePage){
    FILE *arqPage;
    TPagina pagina;
    TNodoPage nodoPagina;

    arqPage = fopen(nomePage, "w");
    if (arqPage == NULL)
    {
        printf("\nErro ao criar Pagina!!!\n");
        return NULL;
    }   

    // Inicialize a estrutura Tpagina como necessário
    pagina.quantidade = 1;
    pagina.posicaoCorrente = 0;
    pagina.inicio = NULL;
    pagina.cursor = NULL;

    // Escreva a estrutura no arquivo
    fwrite(&pagina, sizeof(TPagina), 1, arqPage);
    if (pagina.inicio != NULL)
    {
        strcpy(nodoPagina.nomePage[MAX_TAM_STR], nomePage); 

        fwrite(&nodoPagina, sizeof(TNodoPage), 1, arqPage);
    }
    
    // Feche o arquivo
    fclose(arqPage);
}

//abre uma pagina existente
FILE *openPage(const char *nomePage) {
    FILE *arqOpen;

    arqOpen = fopen(nomePage, "r");

     if (arqOpen == NULL)
    {
        printf("\nErro ao Abrir Pagina!!!\n");
        return NULL;
    }  
    return arqOpen;
}

//ler todo o conteudo do arquivo para a memoria temporaria para sim editar
void readPageArq(FILE *arqPage){
    TPagina pageAtual;
    TNodoPage nodoPagina;

    rewind(arqPage);

    fread(&pageAtual, sizeof(TPagina),1,arqPage);

    fread(&nodoPagina, sizeof(TNodoPage),1,arqPage);

    printf("\nPagina %s\n",nodoPagina.nomePage);

    printf("\nConteudo %s\n",pageAtual.teste);
}

//Passa para o arquivo todo o conteudo da pagina apos ou não ediçaõ
void writePageArq(FILE *arqPage, TPagina *pageAtual, TNodoPage *nodoPageAtual){//prototipo para testar arquivo
    
    rewind(arqPage);

    fwrite(&pageAtual,sizeof(TPagina),1,arqPage); 

    fwrite(&nodoPageAtual, sizeof(TNodoPage), 1, arqPage);

}

//FUNÇÕES DE ALOCAÇÃO-----------------------------------

/*
//Cria uma pagina
Tpagina CreatorPageWikiAlloc(){

}

//Função que retorna o tamanho do NodoPagina
int getSize(TPagina *pageAlloc){
    
}

//Encontra uma pagina especifica (Encotrar o nodo especifico da pagina)
int getPage(TPagina *page, TNodoPage nomePage){

}

//Nenhuma pagina criada 
int NoPages(TPagina *page){

}

//sem espaço para criar pagina
int fullPages(TPagina *page){

}

//
int setCursor(TPagina *page, int cursor){

}

//Destrou lista alocada
void DestroyPageWikiAlloc(TPagina pageWiki){

}
*/
//FUNÇÕES "FUNCIONAIS"----------------

//Retira o enter
void retiraEnter(char *string){
   if(string[strlen(string)-1]=='\n')
      string[strlen(string)-1]='\0';
}

//Função para manipular a string com seu tamanho correto, sem pasasr lixo de memoria
char *copyString(const char *source) {
    // Aloca memória para a nova string
    char *dest = (char*)malloc(strlen(source) + 1);

    // Verifica se a alocação de memória foi bem-sucedida
    if (dest != NULL) {
        strcpy(dest, source); // Copia a string source para dest
    }

    return dest; // Retorna a nova string alocada
}


//converte qualquer string para caixa alta (Tudo Maiusculo)
void convertSizeString(const char *string, char *stringBigSize) {
    int i;
    for (i = 0; string[i]; i++) {
        stringBigSize[i] = (char)toupper((unsigned char)string[i]);
    }
    stringBigSize[i] = '\0';
}

void testeFuncs() {
    const char nomePage[] = "SO";
    const char texto[] = "Teste SO Teste da Desgraça!!!!";

    FILE *arq;
    TPagina pagina;
    TNodoPage nodoPagina;

    // Abrir a página existente (ou crie-a se não existir)
    arq = openPage(nomePage);

    // Ler o conteúdo da página do arquivo
    readPageArq(arq);

    // Preencher a estrutura com o conteúdo desejado
    pagina.quantidade = 1;
    pagina.posicaoCorrente = 0;
    pagina.inicio = 1;
    pagina.cursor = 1;
    pagina.teste = strdup(texto); // Alocar e copiar o texto para a página

    // Preencher a estrutura do nó da página
    strcpy(pagina.teste, texto);
    nodoPagina.linkPages = NULL;

    // Escrever a estrutura atualizada no arquivo
    writePageArq(arq, &pagina, &nodoPagina);

    // Ler o conteúdo da página novamente após a escrita
    readPageArq(arq);

    // Fechar o arquivo
    fclose(arq);

    // Libere a memória alocada
    free(pagina.teste);
    free(nodoPagina.nomePage);

    // Aguarde uma tecla pressionada
    printf("\nPressione Enter para continuar...");
    getchar();
}

/*
//Menu de manipulação da wiki
void menu(){
 int menu;
    
    switch (menu)
    {
    case 1: //Editar pagina

        break;
    
    default:
        break;
    }
    


}
*/

int main(){
    testeFuncs();

    system("pause");

    return 0;
}

/* Lixeira

    pageAtual.cursor = 1;//ponteiros
    pageAtual.inicio = 1;//ponteiros
    pageAtual.posicaoCorrente = 1;
    pageAtual.tamanho = 0;

    pageNodoAtual.backPage = pageNodoAtual.nextPage;
    pageNodoAtual.nextPage = pageNodoAtual.backPage;

    pageNodoAtual.insidePage.cursorColab = 1;//ponteiros
    pageNodoAtual.insidePage.inicioColab = 1;//ponteiros
    pageNodoAtual.insidePage.posicaoCorrenteColab = 1;
    pageNodoAtual.insidePage.tamanhoColab = 0;
    pageNodoAtual.linkPages = NULL;
    pageNodoAtual.NomePage = "SO";

    contPegeAtual.cursorColab = 1;
    contPegeAtual.inicioColab = 1;
    contPegeAtual.posicaoCorrenteColab = 1;
    contPegeAtual.tamanhoColab =0;

*/