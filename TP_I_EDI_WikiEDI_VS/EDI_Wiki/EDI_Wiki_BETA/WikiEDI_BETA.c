#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <string.h>



//----------------------------------------FunÇões Auxiliares-----------------

//Funçao que retira o enter das strings
void retiraEnter(char* string) {
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}

void separarComandoEArquivo(const char* entrada, char* comando, char* nomeArquivo) {
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

void printTESTE()
{
	printf("\nTESTE DESGRAÇA\n");
}
