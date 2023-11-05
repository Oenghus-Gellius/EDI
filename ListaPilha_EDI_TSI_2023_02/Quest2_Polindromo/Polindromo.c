#include "Polindromo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TStack *createrStack()
{
	TStack* stack = (TStack*)malloc(sizeof(TStack));
	if (stack == NULL)
	{
		return NULL;
	}
	stack->tamanho = 0;
	stack->head = NULL;
	return stack;
}

void overStack(TStack* stack)
{
	TNodeStack* ptrNode;
	while (stack->head != NULL)
	{
		ptrNode = stack->head;
		stack->head = ptrNode->next;
		free(ptrNode);
	}
}

int push(TStack* stack, TInfo info)
{
	TNodeStack* ptrNodeStack = (TNodeStack*)malloc(sizeof(TNodeStack));
	if (ptrNodeStack == NULL)
	{
		return 0;
	}
	ptrNodeStack->info = info;
	ptrNodeStack->next = stack->head;
	stack->head = ptrNodeStack;
	stack->tamanho++;
	return 0;
}

int pop(TStack* stack, TInfo* info)
{
	TNodeStack *ptrStack;

	ptrStack = stack->head;
	stack->head = stack->head->next;
	*info = ptrStack->info;
	free(ptrStack);
	stack->tamanho--;
	return 1;
}

int emptyStack(TStack* stack)
{
	return stack->tamanho == 0;
}

int sizeStack(TStack* stack)
{
	return 0;
}

int checkPolindormo(TStack* stack, const char* word)
{
	int len = strlen(word);

	//Preenche a pilha base
	for (int i = 0; i < len; i++)
	{
		TInfo info;
		info.caracter = word[i];
		push(stack, info);
	}

	//cheque poindormo
	for (int i = 0; i < len; i++)
	{
		TInfo info;
		pop(stack, &info);
		if (info.caracter != word[i])
		{
			return 0;//N�o � polindormo
		}
	}
	return 1;
}

int main() {
	TStack* stack = createrStack();

	const char* word = "avion";//Palavra teste

	if (checkPolindormo(stack, word))
	{
		printf("A palavra \"%s\" e um palindromo.\n", word);
	}
	else
	{
		printf("A palavra \"%s\" nao e um palindromo.\n", word);
	}
	overStack(stack);
	return 0;
}
