#include "Log.h"

#include "WikiEDI_BETA.h"
#include "testador.h"
#include "Log.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int logEdit(FILE* arqLog, char* logMensagem) //<----------------PAREI AQUI
{
    if (arqLog == NULL) {
        printf("Errro: o arquivo de log nao foi aberto corretamente.\n");
        return -1;  // ou algum outro valor de erro apropriado
    }

    // Certifica-se de que logMensagem caiba no buffer de lineLog
    if (strlen(logMensagem) >= MAX_CHAR - 1) {
        printf("Errro: a mensagem de log e muito longa para caber no buffer.\n");
        return -1;
    }

    char lineInArq[MAX_CHAR];
    char lineLog[MAX_CHAR];

    //strncpy_s(lineInArq, ENTRADA_DADOS, logMensagem, _TRUNCATE);

    //fseek(arqLog, 0, SEEK_END);

    //size_t elementosEscritos = fwrite(&lineInArq, strlen(lineInArq), 1, arqLog);

    // Escreva a mensagem no arquivo, seguida por uma quebra de linha
    fprintf(arqLog, "%s\n", logMensagem);

    printf("\nlogMsg - %s\n", logMensagem);

    return 1;
}