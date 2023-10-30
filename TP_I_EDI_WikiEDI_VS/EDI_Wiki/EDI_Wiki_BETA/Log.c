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

    fprintf(arqLog, "%s\n", logMensagem);

    return 1;
}