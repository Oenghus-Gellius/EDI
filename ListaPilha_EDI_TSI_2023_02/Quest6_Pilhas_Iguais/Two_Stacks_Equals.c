#include "Two_Stacks_Equals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TStack* createrStack() {
	TStack* stack = (TStack*)malloc(sizeof(TStack));
	if (stack == NULL)
	{
		return NULL;
	}
	stack->head = NULL;
	stack->size = 0;
	return stack;
}

int push(TStack* stack, TInfo info) {
	TNodeStack* ptrNodeStack = (TNodeStack*)malloc(sizeof(TNodeStack));
	if (ptrNodeStack == NULL)
	{
		return 0;
	}
	ptrNodeStack->info = info;
	ptrNodeStack->next = stack->head;
	stack->head = ptrNodeStack;
	stack->size++;
	return 1;
}

int pop(TStack* stack, TInfo* info) {
	TNodeStack* ptrNodeStack;
	if (emptyStack(stack))
	{
		return 0;
	}
	ptrNodeStack = stack->head;
	*info = ptrNodeStack->info;
	stack->head = stack->head->next;
	free(ptrNodeStack);
	stack->size--;
	return 1;
}

int emptyStack(TStack *stack) {
	if (stack->head == NULL)//stack->size == 0
	{
		return 0;
	}
	return 1;
}

void destructStack(TStack* stack){
	TNodeStack *ptrNodeStack;
	while (stack->head != NULL)
	{
		ptrNodeStack = stack->head;
		stack->head = ptrNodeStack->next;
		free(ptrNodeStack);
	}
}

TStack* cloneStack(TStack* stack)
{
	TStack* cloneStack = createrStack();
	TStack* auxStack = createrStack();
	TNodeStack* ptrNodeStack;
	TInfo infoEnter;

	ptrNodeStack = stack->head;

	while (ptrNodeStack != NULL)
	{
		infoEnter = ptrNodeStack->info;
		push(auxStack, infoEnter);
		ptrNodeStack = ptrNodeStack->next;
	}

	TNodeStack* ptrNodeAuxStack;
	ptrNodeAuxStack = auxStack->head;
	while (ptrNodeAuxStack != NULL)
	{
		infoEnter = ptrNodeAuxStack->info;
		push(cloneStack,infoEnter);
		ptrNodeAuxStack = ptrNodeAuxStack->next;
	}
	free(auxStack);
	return cloneStack;
}

void printStack(TStack* stack)
{
	TNodeStack* ptrNodeStack = stack->head;
	while (ptrNodeStack != NULL)
	{
		printf("%c\t",ptrNodeStack->info.caracters);
		ptrNodeStack = ptrNodeStack->next;
	}
	printf("\n");
}

int main() {
	TStack* stackBase = createrStack();
	TStack* stackClone;
	

	char* word = "avion";

	int len = strlen(word);

	for (int i = 0; i < len; i++)
	{
		TInfo enterInfo;
		enterInfo.caracters = word[i];
		push(stackBase, enterInfo);
	}

	printStack(stackBase);

	stackClone = cloneStack(stackBase);

	printStack(stackClone);


	destructStack(stackBase);
	destructStack(stackBase);

	return 0;
}

