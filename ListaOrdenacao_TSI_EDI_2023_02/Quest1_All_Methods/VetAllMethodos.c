#include "VetAllMethodos.h"

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
	list->size = 0;

	return list;
}

int insertList(TList* list, TInfo info)
{
	TNodeList* ptrNodeList = (TNodeList*)malloc(sizeof(TNodeList));
	if (ptrNodeList == NULL)
	{
		return 0;
	}
	if (fullList(list) == 1)
	{
		return 0;
	}

	ptrNodeList->info = info;
	ptrNodeList->next = NULL;
	if (list->size == 0)//Primeiro a ser colocado
	{
		list->start = ptrNodeList;
	}
	else
	{
		list->end->next = ptrNodeList;
	}
	list->end = ptrNodeList;
	list->size++;
	return 0;
}

int removeList(TList* list, TKey key, TInfo* info)
{
	TNodeList* ptrNodeList, *ptrBackNodeList;
	ptrNodeList = list->start;
	ptrBackNodeList = ptrNodeList;

	while (ptrNodeList != NULL)
	{
		if (ptrNodeList->info.key == key)
		{
			if (ptrNodeList == list->start)//Se for o primeiro
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
		else
		{
			ptrBackNodeList = ptrNodeList;
			ptrNodeList = ptrNodeList->next;
		}
	}
	return 0;
}

int finderList(TList* list, TKey key, TInfo* info)
{
	TNodeList* ptrNodeList = list->start;

	while (ptrNodeList != NULL)
	{
		if(ptrNodeList->info.key = key)
		{
			*info = ptrNodeList->info;
			return 1;
		}
		ptrNodeList = ptrNodeList->next;
	}
	return 0;
}

int emptyList(TList* list)
{
	if (list->start == NULL)
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
		return 1;
	}
	free(ptrNodeList);
	return 0;
}

int sizeList(TList* list)
{
	return list->size;
}

void destroyerList(TList* list)
{
	TNodeList* ptrNodeList;
	while (list->start != NULL)
	{
		ptrNodeList = list->start;
		list = list->start->next;
		free(ptrNodeList);
	}
	free(list);
}


//--------------------------------------

TVetList* createrVetList()
{
	TVetList* vetList = (TVetList*)malloc(sizeof(TVetList));
	if (vetList != NULL)
	{
		vetList->size = 0;
	}
	return vetList;
}

int insertVetList(TVetList* vetList, TInfo info)
{
	if (fullVetList(vetList) == 0)
	{
		vetList->VetInfo[vetList->size] = info;
		vetList->size++;
	}
	return 1;
}

int insertPositionVetList(TVetList* vetList, int position, TInfo info)
{
	if (fullVetList(vetList))
	{
		return 0;
	}
	if (position > 0 && position < vetList->size + 1)
	{
		if (position == 1)
		{
			for(int i = vetList->size; i > 0; i--)
			{
				vetList->VetInfo[i] = vetList->VetInfo[i - 1];
			}
			vetList->VetInfo[0] = info;
			vetList->size++;
			return 1;
		}
		else if (position == vetList->size)
			{
				vetList->VetInfo[vetList->size] = info;
			}
			else
			{
				for (int i = vetList->size; i >= position; i--)
				{
					vetList->VetInfo[i] = vetList->VetInfo[i - 1];
				}
				vetList->size--;
				return 1;
			}
	}
	return 0;
}

int removeInfoVetList(TVetList* vetList, TKey key, TInfo* info)
{
	if (emptyList(vetList) == 1)
	{
		return 0;
	}
	for (int i = 0; i < vetList->size; i++)
	{
		if (vetList->VetInfo[i].key == key)
		{
			*info = vetList->VetInfo[i];
			for (int k = i + 1; i < vetList->size; i++)
			{
				vetList->VetInfo[k - 1] = vetList->VetInfo[k];
			}
			vetList->size--;
			return 1;
		}
	}
	return 0;
}

int finderInfoVetList(TVetList* vetList, TKey key, TInfo* info)
{
	if (emptyList(vetList) == 1)
	{
		return 0;
	}

	return 0;
}

int emptyVetList(TVetList* vetList)
{
	return vetList->size == 0;
}

int fullVetList(TVetList* vetList)
{
	if (sizeList(vetList) == MAX_VET)
	{
		return 1;
	}
	return 0;
}

int sizeVetList(TVetList* vetList)
{
	return vetList->size;
}

void DestroyerVet(TVetList* vetList)
{
	free(vetList);
}

void printVetList(TVetList* vetList)
{
	for (int i = 0; i < vetList->size; i++)
	{
		printf("%d\t", vetList->VetInfo[i].key);
	}
}


int main() {
	TVetList* vetList = createrVetList();
	TInfo info;


	int vetNum[] = { 18, 7, 35, 9, 10, 25, 30, 15, 40, 5 };

	for (int i = 0; i < MAX_VET; i++)
	{
		info.key = vetNum[i];
		insertVetList(vetList,info);
	}
	printVetList(vetList);

	return 0;
}