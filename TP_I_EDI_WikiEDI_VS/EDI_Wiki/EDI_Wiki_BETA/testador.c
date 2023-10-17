#include "testador.h"

#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 100

int executeTest() {
	
	char entrada[MAX_CHAR];
	char comando[MAX_CHAR];
	char nomeArquivo[MAX_CHAR];


	int sair;
	do
	{
		printf("\nDeseja inicializar o teste da WikeEDI? Qualquer numero continar | 0-SAIR\n");
		scanf_s("%d", &sair);

		// Consuma o caractere de nova linha restante no buffer
		int charr = getchar();

		if (sair != 0)
		{
			printf("\nDigite o comando ""wikiEDI"" e o nome do arquivo textos de entrada.:\n");
			fgets(entrada, 50, stdin);
			setvbuf(stdin, NULL, _IONBF, 0);
			retiraEnter(entrada);

			//função que vai selarar comando do nome do arquivo e executar a função wikiEDI
			separarComandoEArquivo(entrada, comando, nomeArquivo);
			
			printf("\nentrada:%s - comando:%s - nomeArquivo:%s \n",entrada,comando,nomeArquivo);

			//Encotrar a função do comando. entratra com um comando, checar se é valido e retorno
			//posição do comando no vetor comando.

		}




	} while (sair != 0);

	printTESTE();

	return EXIT_SUCCESS;
}


int main() {

	return executeTest();
}