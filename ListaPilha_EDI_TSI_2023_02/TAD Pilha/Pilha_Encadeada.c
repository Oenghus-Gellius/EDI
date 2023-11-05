#include "Pilha_Encadeada.h"

#include <stdio.h>
#include <stdlib.h>

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
	TNodoPilha* ptrPilha = (TNodoPilha*)malloc(sizeof(TNodoPilha));
	if (ptrPilha == NULL)
	{
		return 1;
	}
	free(ptrPilha);
	return 0;
}
int pilhaVazia(TPilha* pilha) {
	return pilha->tamanho = 0;
}
int tamanhoPilha(TPilha* pilha) {
	return pilha->tamanho;
}