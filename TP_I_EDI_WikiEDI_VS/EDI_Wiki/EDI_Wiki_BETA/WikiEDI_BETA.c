#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define ENTRADA_DADOS 100



//----------------------------------------FunÇões Auxiliares-----------------

//Funçao que retira o enter das strings
void retiraEnter(char* string) {
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}

void separarComandoEArquivo(char* entrada, char* comando, char* nomeArquivo) {
    int i, j = 0;

    // Inicializa as strings de comando e nome do arquivo
    comando[0] = '\0';
    nomeArquivo[0] = '\0';

    // Procura o primeiro espaço em branco na entrada
    for (i = 0; entrada[i] != ' ' && entrada[i] != '\0'; i++) {
        comando[i] = entrada[i];
    }
    comando[i] = '\0';

    // Se a entrada ainda contiver caracteres, copie o restante como nome do arquivo
    if (entrada[i] != '\0') {
        i++; // Pula o espaço em branco
        while (entrada[i] != '\0') {
            nomeArquivo[j] = entrada[i];
            i++;
            j++;
        }
        nomeArquivo[j] = '\0';
    }
}

void separarComandoE4Palavras(const char* entrada, char* comando, char* palavra1, char* palavra2, char* palavra3, char* palavra4) {
    int i = 0;
    char* context = NULL;

    // Inicializa as strings
    comando[0] = '\0';
    palavra1[0] = '\0';
    palavra2[0] = '\0';
    palavra3[0] = '\0';
    palavra4[0] = '\0';

    // Tokenize a entrada usando espaços em branco como delimitadores
    char* token = strtok_s((char*)entrada, " ", &context);

    while (token != NULL && i < 4) {
        switch (i) {
        case 0:
            strncpy_s(comando, sizeof(comando), token, _TRUNCATE);
            break;
        case 1:
            strncpy_s(palavra1, sizeof(palavra1), token, _TRUNCATE);
            break;
        case 2:
            strncpy_s(palavra2, sizeof(palavra2), token, _TRUNCATE);
            break;
        case 3:
            strncpy_s(palavra3, sizeof(palavra3), token, _TRUNCATE);
            break;
        case 4:
            strncpy_s(palavra4, sizeof(palavra4), token, _TRUNCATE);
            break;
        }
        token = strtok_s(NULL, " ", &context);
        i++;
    }
}

int pesquisaFuncion(char* comando) //<------- PAREI AQUI
{
    return 0;
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

//REVER ESSA FUNÇÃO <-------------------------------
FILE* openFile(char* nomeArquivo)
{
    FILE* arqOpen;
    errno_t err = fopen_s(&arqOpen, nomeArquivo, "r+");

    if (err != 0) {
        printf("\nERRO AO ABRIR ARQUIVO!!!\n");
        return NULL;
    }
    return arqOpen;
}

void executer(char* nomeArqTeste)
{
    FILE* arqOpen;
    char lineCommand[MAX_LINE_LENGTH];

    int numFuncion = 0;

    errno_t err = fopen_s(&arqOpen, nomeArqTeste, "r");

    if (arqOpen == NULL && err != 0) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArqTeste);
        return;
    }
    
    rewind(arqOpen);

    printf("\nIniciando a execução, Boa jornada!!!!\n");

    while (fgets(lineCommand, MAX_LINE_LENGTH, arqOpen) != NULL) 
    {
        printf("%s", lineCommand);

        char entrada[ENTRADA_DADOS];
        char comando[ENTRADA_DADOS];
        char palavra1[ENTRADA_DADOS];
        char palavra2[ENTRADA_DADOS];
        char palavra3[ENTRADA_DADOS];
        char palavra4[ENTRADA_DADOS];

        separarComandoE4Palavras(entrada, comando, palavra1, palavra2, palavra3, palavra4);

        numFuncion = pesquisaFuncion(comando); // < ---- - Fazer essas função parei aqui


        switch (numFuncion)
        {
        case 1://INSEREPAGINA <nome_pagina><nome_arquivo>

            break;
        default:
            printf("\nCOMANDO INEXISTENTE!!!\n");
            break;
        }
       
    }
    printTESTE();
}

void closeArq(FILE* nomeArq)
{
    fclose(nomeArq);
}

void printTESTE()
{
	printf("\nTESTE DESGRAÇA\n");
}
