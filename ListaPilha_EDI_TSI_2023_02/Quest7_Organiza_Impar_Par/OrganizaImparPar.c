#include "OrganizaImparPar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



TList* createrList()
{
	TList* list = (TList*)malloc(sizeof(TList));
	if (list == NULL)
	{
		return NULL;
	}
	list->start = NULL;
	list->end = NULL;
	list->cursor = NULL;
	list->size = 0;

	return list;
}

int pushList(TList* list, TInfo info)
{
	if (fullList(list) == 0)
	{
		return 0;
	}
	TNodeList* ptrNodeList = (TNodeList*)malloc(sizeof(TNodeList));
	if (ptrNodeList == NULL)
	{
		return 0;
	}

	ptrNodeList->info = info;
	ptrNodeList->next = NULL;
	if (list->size == 0)//Se estiver vazio
	{
		list->cursor = ptrNodeList;
		list->start = ptrNodeList;
	}
	else
	{
		list->end->next = ptrNodeList;
	}
	list->end = ptrNodeList;
	list->size++;

	return 1;
}

int finderList(TList* list, TInfo finderInfo, TInfo* info)
{
	if (emptyList(list))
	{
		return 0;
	}
	TNodeList* ptrNodeList = list->start;
	while (ptrNodeList != NULL)
	{
		if (ptrNodeList->info.num == finderInfo.num)
		{
			*info = finderInfo;
			return 1;
		}
		ptrNodeList = ptrNodeList->next;
	}
	return 0;
}

int removeList(TList* list, TInfo finderInfo, TInfo* info)
{
	if (emptyList(list))
	{
		return 0;
	}
	TNodeList* ptrNodeList, * ptrBackNodeList;
	ptrNodeList = list->start;
	ptrBackNodeList = list->start;
	while (ptrNodeList != NULL)
	{
		if (ptrNodeList->info.num == finderInfo.num)
		{
			if (ptrNodeList == list->start)//se for o primeiro
			{
				list->start = list->start->next;
			}
			else if (ptrNodeList == list->end)
			{
				list->end = ptrBackNodeList;
				list->end->next = NULL;
			}
			else
			{
				ptrBackNodeList->next = ptrNodeList->next;
			}
			*info = ptrNodeList->info;
			free(ptrNodeList);
			list->size--;
			return 1;
		}
		ptrBackNodeList = ptrNodeList;
		ptrNodeList = ptrNodeList->next;		
	}
	return 0;
}

int emptyList(TList* list)
{
	if (list->size == 0)
	{
		return 1;
	}
	return 0;
}

int fullList(TList* list)
{
	TNodeList* ptrNodeList = (TNodeList*)malloc(sizeof(TNodeList));
	if (ptrNodeList == NULL)
	{
		return 0;
	}
	free(ptrNodeList);
	return 1;
}

int sizeList(TList* list)
{
	return list->size;
}

void destroyerList(TList* list)
{
	while (list->start != NULL)
	{
		TNodeList* ptrNodeList = list->start;
		list->start = list->start->next;
		free(ptrNodeList);
	}
	free(list);
}

void printList(TList* list)
{
	TNodeList* ptrNodeList;
	ptrNodeList = list->start;
	while (ptrNodeList != NULL)
	{
		printf("%d\t", ptrNodeList->info.num);
		ptrNodeList = ptrNodeList->next;
	}
	printf("\n");
}

//-------------------------------------------

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

void printStack(TStack* stack)
{
	TNodeStack* ptrNodeStack = stack->head;
	while (ptrNodeStack != NULL)
	{
		printf("%d\t", ptrNodeStack->info.num);
		ptrNodeStack = ptrNodeStack->next;
	}
	printf("\n");
}

TStack* selectInfoStack(TList* list)
{
	TStack* stack = createrStack();
	
	TNodeList* ptrList = list->start;

	while (ptrList != NULL)
	{
		if (ptrList->info.num%2 == 0)
		{
			pushStack(stack,ptrList->info);
		}
		ptrList = ptrList->next;
	}
	return stack;
}

void endAndPrint(TStack* stack)
{
	while (stack->head != NULL)
	{
		TNodeStack* ptrNodeStack = stack->head;
		printf("\nRemovendo %d", stack->head->info.num);
		stack->head = stack->head->next;
		printf("\nRestando.: ");
		TNodeStack* ptrNodeRemains = stack->head;
		while (ptrNodeRemains != NULL)
		{
			
			printf("%d\t",ptrNodeRemains->info.num);
			ptrNodeRemains = ptrNodeRemains->next;
		}

		free(ptrNodeStack);
	}
	free(stack);
}



int main() {
	int num[] = { 4,6,9,5,61,43,70,63,87,93,19,47,48,56,14 };
	int sizeVet = 15;

	TList* listBase = createrList();

	TStack* stackPair;

	TInfo enterInfo;

	for (int i = 0; i < sizeVet; i++)
	{
		enterInfo.num = num[i];
		pushList(listBase, enterInfo);
	}
	
	printList(listBase);

	stackPair = selectInfoStack(listBase);

	printStack(stackPair);

	endAndPrint(stackPair);



	return 0;
}

