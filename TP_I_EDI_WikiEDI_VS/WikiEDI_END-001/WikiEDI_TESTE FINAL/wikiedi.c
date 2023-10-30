#include "wikiedi.h"


#include "WikiEDI_BETA.h"
#include "Links.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>

int main() {

	setlocale(LC_ALL, "pt-BR");
	return executeTest();
}

int executeTest(){

	char nomeArquivo[] = "entrada.txt";
    executer(nomeArquivo);

    return EXIT_SUCCESS;
}