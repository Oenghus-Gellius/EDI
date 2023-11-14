#include "teste.h"

#define  _CRT_SECURE_NO_WARNINGS

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
		return 1;
	}
	ptrNodeStack->info = info;
	ptrNodeStack->next = stack->head;
	stack->head = ptrNodeStack;
	stack->size++;
	return 0;
}

int popStack(TStack* stack, TInfo* info)
{
	if (emptyStack(stack) == 1)
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
		return 1;
	}
	return 0;
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
	if (emptyStack(stack)) {
		printf("Stack is empty.\n");
		return;
	}

	TNodeStack* ptrNodeStack = stack->head;
	while (ptrNodeStack != NULL)
	{
		printf("Key %d Status.: %c - %s | Movement: %d\t", ptrNodeStack->info.key,
			ptrNodeStack->info.status,ptrNodeStack->info.carPlate, ptrNodeStack->info.movement);
		ptrNodeStack = ptrNodeStack->next;
	}
	printf("\n");
}





//-----------------
int main() {
	return dayTest();
}
/*
void ValetParking4You(TStack* carStack, TInfo infoCar)
{
	TStack* tempStack = createrStack();
	int In, out;

	int finder = 0;
	printf("\nValet Parking 4 You!!!\n");

	while (carStack != NULL && finder == 0)
	{
		pushStack(tempStack, carStack->head->info);
		popStack(carStack, &carStack->head->info);

		if (infoCar.key == carStack->head->info.key)
		{
			popStack(carStack, &carStack->head->info);//<-REMOVENDO EFETIVAMENTE DA PILHA
			printf("\nCar remove  %d\t", infoCar.key);
			finder = 1;
		}
	}

	while (tempStack->head != NULL)
	{
		pushStack(carStack, tempStack->head->info);
		popStack(tempStack, &tempStack->head->info);
	}
	free(tempStack);

	printf("\nCar in park.:\n");
	printStack(carStack);
}
*/

int dayTest()
{
	TStack* garageStack = createrStack();
	TInfo carInfoGarage;

	TKey keyday = 1;
	int garageQtdNow = 0;

	TCarPlate carEnterPlate[] = { "ABC-123", "XYZ-789", "QWE-456", "HJK-321", "LMN-654", "PQR-987", "STU-654", "VWX-321", "YZA-789", "HQK-341" };

	//Se entrar não chama função movimentação pq entra no topo da pilha
	/*
	for (int i = 0; i < 10; i++)
	{
		carInfoGarage.key = i;
		strcpy(carInfoGarage.carPlate, carEnterPlate[i]);
		carInfoGarage.movement = 0;
		pushStack(garageStack, carInfoGarage);
		keyday++;
	}*/
	//Entra carro;
	carInfoGarage.key = keyday;
	strcpy(carInfoGarage.carPlate, carEnterPlate[0]);
	carInfoGarage.movement = 0;
	carInfoGarage.status = 'E';
	pushStack(garageStack, carInfoGarage);
	keyday++;

	printStack(garageStack);

	//ValetParking4You(garageStack, carInfoRemove);

	//destructyStack(garageStack);

	return EXIT_SUCCESS;
}

