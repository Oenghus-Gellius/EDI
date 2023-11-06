#include "Lista_Pilha_invert.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------Alocar INFO

TInfo* createrInfo()
{
	TInfo* info = (TInfo*)malloc(sizeof(TInfo));
	if (info == NULL)
	{
		return NULL;
	}
	return info;
}

void destroyerInfo(TInfo* info)
{
	free(info);
}

TKey getKey(TInfo* info)
{
	return info->key;
}

void setKey(TInfo* info, TKey key)
{
	info->key = key;
}

//--------------------------Line

TLine* createrLine() {
	TLine* line = (TLine*)malloc(sizeof(TLine));
	if (line == NULL)
	{
		return NULL;
	}
	line->start = NULL;
	line->end = NULL;
	line->size = 0;

	return line;
}

int queueLine(TLine* line, TInfo info) {
	if (fullLine(line) == 1)
	{
		return 0;
	}
	TNodeLine* ptrNodeLine = (TNodeLine*)malloc(sizeof(TNodeLine));
	if (ptrNodeLine == NULL)
	{
		return 0;
	}
	ptrNodeLine->info = info;
	ptrNodeLine->next = NULL;
	if (line->size == 0)//O Primeiro da fila
	{
		line->start = ptrNodeLine;
	}
	else
	{
		line->end->next = ptrNodeLine;
	}
	line->end = ptrNodeLine;
	line->size++;
	return 1;
}

TInfo* dequeueLine(TLine* line)
{
	TNodeLine* ptrNodeLine;
	TInfo* info = createrInfo();

	if (emptyLine(line) == 1)
	{
		return;
	}
	ptrNodeLine = line->start;
	line->start = line->start->next;
	*info = ptrNodeLine->info;
	line->size--;
	free(ptrNodeLine);

	return info;
}

int emptyLine(TLine* line)
{
	if (line->size == 0)
	{
		return 1;
	}
	return 0;
}

int fullLine(TLine* line)
{
	TNodeLine* ptrNodeLine = (TLine*)malloc(sizeof(TLine));
	if (line == NULL)
	{
		return 1;
	}
	free(ptrNodeLine);
	return 0;
}

int sizeLine(TLine* line)
{
	return line->size;
}

void destroyerLine(TLine* line) {
	TNodeLine* ptrNodeLine;
	while (line->start != NULL)
	{
		ptrNodeLine = line->start;
		line->start = line->start->next;
		free(ptrNodeLine);
	}
	free(line);
}

//------------------------------STACK

TStack* createrStack() {
	TStack* stack = (TStack*)malloc(sizeof(TStack));
	if (stack == NULL)
	{
		return NULL;
	}
	stack->size = 0;
	stack->head = NULL;
	return stack;
}

int pushStack(TStack* stack, TInfo info)
{
	TNodeStack* ptrNodeStack = (TNodeStack*)malloc(sizeof(TNodeStack));
	if (ptrNodeStack == NULL)
	{
		return 0;
	}
	ptrNodeStack->info = info;
	ptrNodeStack->next = stack->head;
	stack->head = ptrNodeStack;
	stack->size++;
	return 0;
}

int popStack(TStack* stack, TInfo* info)
{
	if (emptyStack(stack))
	{
		return 0;
	}
	TNodeStack* ptrNodeStack = stack->head;

	*info = ptrNodeStack->info;
	stack->head = stack->head->next;
	free(ptrNodeStack);
	stack->size--;
	return 1;
}

int emptyStack(TStack* stack) {
	if (stack->size == 0)
	{
		return 0;
	}
	return 1;
}

int sizeStack(TStack* stack)
{
	return stack->size;
}

void destructyStack(TStack* stack)
{
	TNodeStack* ptrNodeStack;
	while (stack->head != NULL)
	{
		ptrNodeStack = stack->head;
		stack->head = stack->head->next;
		free(ptrNodeStack);
	}
	free(stack);
}

//--------------------------


//----------------------------
void invertLine(TLine* line){
	TStack* stack = (TStack*)malloc(sizeof(TStack));
	if (stack == NULL)
	{
		return;
	}

	TNodeLine* ptrNodeLine = line->start;
	TInfo* infoUser = createrInfo();
	while (ptrNodeLine != NULL)//Cria pilha
	{
		infoUser = dequeueLine(line);
		pushStack(stack, *infoUser);
		ptrNodeLine = ptrNodeLine->next;
	}

	TNodeStack* ptrNodeStack = stack->head;
	while (ptrNodeStack != NULL)//refez uma lista invertida
	{
		queueLine(line, ptrNodeStack->info);
		ptrNodeStack = ptrNodeStack->next;
	}
	destructyStack(stack);
}

void printLine(TLine* line)
{
	TNodeLine* ptrNodeLine = line->start;
	while (ptrNodeLine != NULL)
	{
		printf("%d\t",ptrNodeLine->info.key);
		ptrNodeLine = ptrNodeLine->next;
	}
	printf("\n");
}

int main() {

	TLine* baseLine = createrLine();
	TInfo infoEnter;

	int num[] = {11,3,0,5,7,4,6,9};
	int sizeVet = 8;

	for (int i = 0; i < sizeVet; i++)
	{
		infoEnter.num = num[i];
		infoEnter.key = num[i];
		queueLine(baseLine,infoEnter);
	}

	printLine(baseLine);

	invertLine(baseLine);

	printLine(baseLine);

	destroyerLine(baseLine);

	return 0;
}


