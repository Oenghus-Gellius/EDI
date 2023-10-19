#include "testador.h"

#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

int executeTest() {
	
	char entrada[MAX_CHAR];//{ "./wikiedi TestOENGHUS.txt" };// <------REMOVER QUANDO TERMINADO
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
			//acrescentarAoArquivo();  // Chamando a função para acrescentar texto ao arquivo


			printf("\nDigite o comando ""./wikiedi"" e o nome do arquivo textos de entrada.:\n");
			printf("Comando.:");

			fgets(entrada, 50, stdin); // <------TROCAR QUANDO TERMINADO
			setvbuf(stdin, NULL, _IONBF, 0);
			retiraEnter(entrada);

			//função que vai selarar comando do nome do arquivo e executar a função wikiEDI
			separarComandoEArquivo(entrada, comando, nomeArquivo);

			//printf("\nEntrada:%s - Comando:%s - NomeArquivo:%s \n",entrada,comando,nomeArquivo);
			if (!strcmp("./wikiedi",comando))
			{
				if (!openFileTester(nomeArquivo))
				{
					executer(nomeArquivo);	// <-------Chama a função que vai executar os comando do arquivo
				}
				else
				{			
					printf("\nErro ao abrir o arquivo! Verifique se o arquivo existe.\n");
				}	
			}
			else
			{
				printf("\nComando invalido!!!!\n");
			}
		}
	} while (sair != 0);

	return EXIT_SUCCESS;
}


int main() {
	return executeTest();
}

void acrescentarAoArquivo() {
	// Abra o arquivo para adicionar conteúdo
	FILE* arquivo;
	errno_t err = fopen_s(&arquivo, "TestOENGHUS.txt", "a");
	if (err != 0)
	{
		printf("Erro ao abrir o arquivo.\n");
		return;
	}

	// Texto a ser acrescentado ao arquivo
	const char* texto = "INSEREPAGINA EDI edi.txt\n"
		"INSEREPAGINA BD banco.txt\n"
		"INSEREPAGINA SO so.txt\n"
		"RETIRAPAGINA Psicologia\n"
		"INSEREEDITOR PEDRAO\n"
		"INSEREEDITOR MALUZINHA\n"
		"INSEREEDITOR AMANDINHA\n"
		"INSEREEDITOR LARINHA\n"
		"INSEREEDITOR WENDER\n"
		"RETIRAEDITOR WENDER\n"
		"INSERECONTRIBUICAO EDI MALUZINHA c1.txt\n"
		"INSERECONTRIBUICAO Fisica LARINHA c2.txt\n"
		"INSERECONTRIBUICAO EDI MALUZINHA c3.txt\n"
		"INSERELINK EDI BD\n"
		"IMPRIMEPAGINA EDI\n"
		"INSERECONTRIBUICAO BD LARINHA c4.txt\n"
		"INSERECONTRIBUICAO BD AMANDINHA c5.txt\n"
		"RETIRACONTRIBUICAO BD AMANDINHA c5.txt\n"
		"INSERELINK BD EDI\n"
		"INSERECONTRIBUICAO SO PEDRAO c6.txt\n"
		"INSERECONTRIBUICAO SO PEDRAO c6.txt\n"
		"INSERECONTRIBUICAO SO AMANDINHA c8.txt\n"
		"INSERELINK SO EDI\n"
		"INSERELINK SO BD\n"
		"CAMINHO SO EDI\n"
		"CAMINHO BD SO\n"
		"IMPRIMEWIKED\n"
		"FIM\n";

	// Escreva o texto no arquivo
	fprintf(arquivo, "%s\n", texto);

	// Feche o arquivo
	fclose(arquivo);

	printf("Texto acrescentado ao arquivo com sucesso.\n");
}