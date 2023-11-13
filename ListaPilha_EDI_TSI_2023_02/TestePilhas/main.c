#include "main.h"

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
		if (ptrNodeList->info.key == finderInfo.key)
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
		if (ptrNodeList->info.key == finderInfo.key)
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
		printf("%d\t", ptrNodeList->info.key);
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
		printf("%d\t", ptrNodeStack->info.key);
		ptrNodeStack = ptrNodeStack->next;
	}
	printf("\n");
}

//-----------------
int main() {
	TStack* garageStack = createrStack();
	TKey carRemove = 7;
	TInfo carInfo;
	int garageQtd = 10;

	for (int i = 0; i < garageQtd; i++)
	{
		carInfo.key = i;
		pushStack(garageStack, carInfo);
	}

	printStack(garageStack);

	carInfo.key = carRemove;

	ValetParking4You(garageStack, carInfo);
	return 0;
}

void ValetParking4You(TStack* carStack, TInfo infoCar)
{
	TStack* tempStack = createrStack();
	TNodeStack* ptrTemp;

	TNodeStack* ptrNodeStack = carStack->head;
	int finder = 0;

	printf("\nValet Parking 4 You\n");

	while (carStack != NULL && finder == 0)
	{
		if (infoCar.key = ptrNodeStack->info.key)
		{
			popStack(carStack, &infoCar);
			pushStack(tempStack, infoCar);
			finder = 1;
		}
		else
		{
			ptrNodeStack = ptrNodeStack->next;
		}
	}
	printf("\nCar out.: %d \n",ptrNodeStack->info.key);
	printf("\tParking order.:  ");

	TNodeStack* ptrTempStack = tempStack->head;
	TInfo inforCarInGarage;
	while (tempStack != NULL)
	{
		inforCarInGarage = ptrNodeStack->info;
		pushStack(carStack, inforCarInGarage);
		pop(tempStack, inforCarInGarage);//Sera?
	}

	TNodeStack* ptrPrintGarage = carStack->head;
	for (int i = 0; i < carStack->size; i++)//printa a lista atu de carro
	{
		printf("%d\t",ptrPrintGarage->info.key);
		ptrPrintGarage = ptrPrintGarage->next;
	}

	free(tempStack);
}
