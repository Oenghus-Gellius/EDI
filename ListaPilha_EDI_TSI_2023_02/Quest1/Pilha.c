#define _CRT_SECURE_NO_WARNINGS

#include "Pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



TPilha* criaPilha() {
	TPilha* pilha = (TPilha*)malloc(sizeof(TPilha));
	if (pilha == NULL)
	{
		printf("\nPilha no criada!!!\n");
		return 0;
	}
	pilha->topo = NULL;
	pilha->tamanho = 0;
	return pilha;
}

void terminaPilha(TPilha* pilha) 
{
	TNodoPilha* ptrPilha;
	while (pilha->topo != NULL)
	{
		ptrPilha = pilha->topo;
		pilha->topo = pilha->topo->next;
		free(ptrPilha);
	}
	free(pilha);
}

int push(TPilha* pilha, TElemento info) //Acrrscentar
{
	TNodoPilha* ptrPilha = (TNodoPilha*)malloc(sizeof(TNodoPilha));
	if (ptrPilha == NULL)
	{
		return 0;
	}
	ptrPilha->info = info;
	ptrPilha->next = pilha->topo;
	pilha->topo = ptrPilha;
	pilha->tamanho++;
	return 1;
}

int pop(TPilha* pilha, TElemento* info) //Tirar
{
	TNodoPilha* ptrLista;
	if (pilhaVazia(pilha) == 1)
	{
		return 0;
	}
	ptrLista = pilha->topo;
	pilha->topo = pilha->topo->next;
	*info = ptrLista->info;//Pra que?
	free(ptrLista);
	pilha->tamanho--;
	return 1;
}

int pilhaCheia(TPilha* pilha) {
	if (pilha == NULL)
	{
		return 1;
	}
	return 0;
}

int pilhaVazia(TPilha* pilha) {
	return pilha->tamanho == 0;
}

int finderPositionElemento(TPilha* pilha, TChave chave)
{
	TNodoPilha* ptrFinderKey = pilha->topo;
	int index = 1;
	int finder = 0;

	while (ptrFinderKey != NULL && finder == 0)//procuraando
	{
		if (strcmp(ptrFinderKey->info.chave, chave) == 0)
		{
			index;
			return index;
		}
		else
		{
			ptrFinderKey = ptrFinderKey->next;
			index++;
		}
	}
	return 0;
}

int tamanhoPilha(TPilha* pilha) {
	return pilha->tamanho;
}

char** vetAllocString(int tamanhoVet) {
	char** vetAlloc = (char**)malloc(tamanhoVet * sizeof(char*)); // Aloque memória para o vetor de ponteiros

	if (vetAlloc != NULL) {
		for (int i = 0; i < tamanhoVet; i++) {
			vetAlloc[i] = (char*)malloc(MAX_CHAR * sizeof(char));
			if (vetAlloc[i] == NULL) {
				// Lidar com a falha na alocação de memória, se necessário
				for (int j = 0; j < i; j++) {
					free(vetAlloc[j]);
				}
				free(vetAlloc);
				return NULL;
			}
		}
	}

	return vetAlloc;
}

/*
int main() {
	TPilha* PilhaValkir = criaPilha();
	TElemento infoEnter;
	TElemento info;

	char conteudo[MAX_WORDS][MAX_WORDS] = { "Brunhild", "Sigrun", "Hilde", "Gudrun", "Brynhildr", "Svava", "Herja", "Geiravör", "Ráðgríðr", "Reginleif", "Hervör alvitr", "Hjörþrimul", "Skuld", "Hildr", "Geirskögul", "Randgríðr", "Þögn", "Hlaðgunnr", "Sanngríðr", "Skögul" };


	int tamanhoConteudo = sizeof(conteudo) / sizeof(conteudo[0]);

	TChave finderChave = "Gudrun";

	int index = -1;

	strcpy(infoEnter.chave, finderChave);

	//Construir a pilha NE?!
	printf("\nNome Valkirias\n\n");
	for (int i = 0; i < tamanhoConteudo; i++)
	{
		info;
		strcpy(info.chave, conteudo[i]);
		push(PilhaValkir, info);
		printf("%s\t", PilhaValkir->topo->info.chave);
	}

	index = finderPositionElemento(PilhaValkir, finderChave);

	if (index == 0)
	{
		printf("\nElemento %s no localizado\n", finderChave);
	}
	else
	{
		printf("\nElemento %s no esta na posicao %d.\n", finderChave, index);
	}

	terminaPilha(PilhaValkir);



	return 0;
}
*/