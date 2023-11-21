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
	else//Se for o ultimo
	{
		list->end->next = ptrNodeList;//Conecta o "penultino ao que vai entra no final"
	}
	list->end = ptrNodeList;
	list->size++;
	return 0;
}

int removeList(TList* list, TKey key, TInfo* info)
{
	TNodeList* ptrNodeList, * ptrBackNodeList;
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
			else if (ptrNodeList == list->end)//Se for o ultimo
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
		if (ptrNodeList->info.key = key)
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
			for (int i = vetList->size; i > 0; i--)
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
			vetList->size++;
		}
		else
		{
			for (int i = vetList->size; i >= position; i--)
			{
				vetList->VetInfo[i] = vetList->VetInfo[i - 1];
			}
			vetList->size++;
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
	for (int i = 0; i < vetList->size; i++)
	{
		if (vetList->VetInfo->key == key)
		{
			*info = vetList->VetInfo[i];
			return 1;
		}
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
		printf("%d|%c\t", vetList->VetInfo[i].key, vetList->VetInfo[i].caracter);
	}
	printf("\n");
}


//================================= ORDERING - crescent
void swap(TInfo* keyX, TInfo* keyY)
{
	TInfo temp = *keyX;
	*keyX = *keyY;
	*keyY = temp;
}

//=============================selectoinSort
void selectionSortBase(TVetList* vetList, int size)//Passar size � redundante, pois j� tem essa informa��o na struct vetList->size
{
	int i, k, baseIndex;
	for (i = 0; i < size - 1; i++)
	{
		baseIndex = i;//o indexador do momentos
		for (k = i + 1; k < size; k++)
		{
			if (vetList->VetInfo[k].key < vetList->VetInfo[baseIndex].key)
			{
				baseIndex = k;
			}
		}
		swap(&vetList->VetInfo[baseIndex], &vetList->VetInfo[i]);
	}
}

void selectionSort(TVetList* vetList, int size)
{
	int i, k, baseIndex;
	for (i = 0; i < size - 1; i++)
	{
		baseIndex = i;
		for (k = i + 1; k < size; k++)
		{
			if (vetList->VetInfo[k].key < vetList->VetInfo[baseIndex].key)
			{
				baseIndex = k;
			}
		}
		if (baseIndex != i)//Faz a chamada da fun��o swap para fazer a troca de kyes
		{
			swap(&vetList->VetInfo[baseIndex], &vetList->VetInfo[i]);
		}
	}
}

//=============================bubbleSort

void bubbleSortBase(TVetList* vetList, int size)
{
	int i, k;
	for (i = 0; i < size - 1; i++)
	{
		for (k = 0; k < size - i - 1; k++)
		{
			if (vetList->VetInfo[k].key > vetList->VetInfo[k + 1].key)
			{
				swap(&vetList->VetInfo[k], &vetList->VetInfo[k + 1]);
			}
		}
	}
}

void bubbleSort(TVetList* vetList, int size)
{
	int i, k;
	int swapped;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (k = 0; k < size - i - 1; k++)//A cada passagem de "i" reduz o tamanho do vetor
		{
			if (vetList->VetInfo[k].key > vetList->VetInfo[k + 1].key)
			{
				swap(&vetList->VetInfo[k], &vetList->VetInfo[k + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}

void bubbleSortStop(TVetList* vetList, int size)
{
	int i;
	int lastChange;
	int	lastPosition = size - 1;

	do
	{
		lastChange = 0;
		for (i = 0; i < lastPosition - 1; i++)
		{
			if (vetList->VetInfo[i].key > vetList->VetInfo[i + 1].key)
			{
				swap(&vetList->VetInfo[i], &vetList->VetInfo[i + 1]);
				lastChange = i;
			}
		}
		lastPosition = lastChange;
	} while (lastPosition > 0);
}


//============================InsertSort

void insertSort(TVetList* vetList, int size)
{
	int i, k;
	TInfo keyCompare;

	for (i = 1; i < size; i++)
	{
		keyCompare = vetList->VetInfo[i];
		k = i - 1;
		while ((k >= 0) && (keyCompare.key < vetList->VetInfo[k].key))
		{
			vetList->VetInfo[k + 1] = vetList->VetInfo[k];
			k--;
		}
		vetList->VetInfo[k + 1] = keyCompare;
	}
}

//==============================Shellsort

void shellSort(TVetList* vetList, int size)
{
	int i, k;
	int h = 1;
	TInfo keyCompare;

	do
	{
		h = h * 3 + 1;//Formula knut
	} while (h < size); // Encontra o valor maximo de h

	do
	{
		h = h / 3;
		for (i = h; i < size; i++)
		{
			k = i;
			keyCompare = vetList->VetInfo[i];
			while (vetList->VetInfo[k - h].key > keyCompare.key)
			{
				vetList->VetInfo[k] = vetList->VetInfo[k - h];
				k = k - h;
				if (k < h)
				{
					break;
				}
			}
			vetList->VetInfo[k] = keyCompare;
		}
	} while (h != 1);
}

//==============================QuickSort / Partition

void partition(TVetList* vetList, int esq, int dir)
{
	int i, k;
	TInfo pivot, keyCompare;

	i = esq;
	k = dir;

	// Seleciona o elemento do meio como piv�
	pivot = vetList->VetInfo[(esq + dir) / 2];

	do
	{
		// Encontra um elemento � esquerda que � maior ou igual ao piv�
		while (vetList->VetInfo[i].key < pivot.key)
		{
			i++;
		}
		// Encontra um elemento � direita que � menor ou igual ao piv�
		while (vetList->VetInfo[k].key > pivot.key)
		{
			k--;
		}
		// Se i � menor ou igual a k, troca os elementos nas posi��es i e k
		if (i <= k)
		{
			swap(&vetList->VetInfo[i], &vetList->VetInfo[k]);
			i++;
			k--;
		}
	} while (i <= k);

	if (esq < k)
	{
		partition(vetList, esq, k);
	}
	if (dir > i)
	{
		partition(vetList, i, dir);
	}
}

void quickSort(TVetList* vetList, int size)
{
	partition(vetList, 0, size - 1);
}

void partitionInsert(TVetList* vetList, int esq, int dir)
{
	int size = dir - esq + 1;  // Corrigir c�lculo do tamanho
	if (size > 200)
	{
		insertSort(vetList, esq, dir);  // Chamar insertSort com os �ndices corretos
	}
	else
	{
		int i, j, temp, pivot, middle, left, right;
		middle = (esq + dir) / 2;
		left = vetList->VetInfo[esq].key;
		right = vetList->VetInfo[dir].key;

		pivot = vetList->VetInfo[middle].key;

		i = esq;
		j = dir;
		do
		{
			while (vetList->VetInfo[i].key < pivot)
			{
				i++;
			}
			while (vetList->VetInfo[j].key > pivot)
			{
				j--;
			}
			if (i <= j)
			{
				swap(&vetList->VetInfo[i], &vetList->VetInfo[j]);
				i++;
				j--;
			}
		} while (i <= j);
		if (esq < j)
		{
			partitionInsert(vetList, esq, j);
		}
		if (dir > i)
		{
			partitionInsert(vetList, i, dir);
		}
	}
}


void quickSortInsert(TVetList* vetList, int size) //< -- - FaZER AQUI
{
	partitionInsert(vetList, 0, size - 1);
}

//==============================MergeSort / Partition <--- ERRADO
void mergeSort(TInfo* vetList, int size)
{
	mergeSort_Order(vetList, 0, size - 1);
}

void mergeSort_Order(TInfo* vetList, int esq, int dir)
{
	int middle;
	if (esq >= dir)
	{
		return;
	}
	middle = (esq + dir) / 2;
	mergeSort_Order(vetList, esq, middle);
	mergeSort_Order(vetList, middle + 1, dir);
	mergeSort_Interleave(vetList, esq, middle, dir);
}

void mergeSort_Interleave(TVetList* vetList, int esq, int midlle, int dir)
{
	int i, j, k;
	int count = 0;
	int size_Esq = midlle - esq + 1;
	int size_Dir = dir - midlle;

	TInfo* leftSide = (TInfo*)malloc(size_Esq * sizeof(TInfo));
	TInfo* rightSide = (TInfo*)malloc(size_Dir * sizeof(TInfo));

	// Copia os elementos da parte esquerda para o array leftSide
	for (i = 0; i < size_Esq; i++)
	{
		leftSide[i] = vetList->VetInfo[i + esq];
	}

	// Copia os elementos da parte direita para o array rightSide
	for (i = 0; i < size_Dir; i++)
	{
		rightSide[i] = vetList->VetInfo[i + midlle + 1];
	}
	i = 0;
	j = 0;

	while (i < size_Esq && j < size_Dir)
	{
		if (leftSide[i].key < rightSide[j].key)
		{
			vetList->VetInfo[esq + count] = leftSide[i];
			i++;
		}
		else
		{
			vetList->VetInfo[esq + count] = rightSide[j];
			j++;
		}
		count++;
	}
	while (i < size_Esq)
	{
		vetList->VetInfo[esq + count] = leftSide[i];
		i++;
		count++;
	}
	while (j < size_Dir)
	{
		vetList->VetInfo[esq + count] = rightSide[j];
		j++;
		count++;
	}

	free(leftSide);
	free(rightSide);
}



//==============================heapSort

void buildHeap(TVetList* vetList, int position, int end)
{
	int h = 0, change;
	change = 1;
	do
	{
		if (2 * position + 1 > end)
		{
			change = 0;
		}
		//encontra o maior filho
		else
			if (2 * position + 2 > end)
			{
				h = 2 * position + 1;
			}
			else
				if (vetList->VetInfo[2 * position + 1].key > vetList->VetInfo[2 * position + 2].key)
				{
					h = 2 * position + 1;
				}
				else
				{
					h = 2 * position + 2;
				}
		// compara o maior filho com o pai
		if (vetList->VetInfo[position].key < vetList->VetInfo[h].key)
		{
			swap(&vetList->VetInfo[h], &vetList->VetInfo[position]);
			position = h;
		}
		else
		{
			change = 0;
		}
	} while (change);
}

void heapSort(TVetList* vetList, int size)
{
	int i;
	//Constroi a arvore heap
	for (i = (size - 1) / 2; i >= 0; i--)
	{
		buildHeap(vetList, i, size - 1);
	}

	//Ordena a partir da arvore heap
	for (i = (size - 1); i > 0; i--)
	{
		swap(&vetList->VetInfo[0].key, &vetList->VetInfo[i].key);
		buildHeap(vetList, 0, i - 1);
	}
}
//-----------------------------------------------------------MAIN

int main() {
	TVetList* vetList = createrVetList();
	TInfo info;


	int vetNum[] = { 18, 7, 13, 9, 10, 25, 30, 13, 40, 5 };
	int VetIntOrd[] = {1, 2, 3, 4, 5, 6, 3, 8, 9, 10};
	char vetChar[] = { 'A','B','C','D','E','F','G','H','I','J' };


	for (int i = 0; i < MAX_VET; i++)
	{
		info.key = vetNum[i];
		info.caracter = vetChar[i];
		insertVetList(vetList,info);
	}
	printf("\nQuest1-START\n");
	printVetList(vetList);

	//selectionSortBase(vetList, vetList->size);
	//selectionSort(vetList, vetList->size);
	//bubbleSortBase(vetList, vetList->size);
	//bubbleSort(vetList, vetList->size);
	//bubbleSortStop(vetList, vetList->size);
	//insertSort(vetList, vetList->size);
	shellSort(vetList, vetList->size);
	//quickSort(vetList, vetList->size);
	//quickSortInsert(vetList, vetList->size);
	
	//mergeSort(vetList, vetList->size); //<---ERRO

	//heapSort(vetList, vetList->size);

	printVetList(vetList);
	printf("\nQuest1-END\n");

	printf("\nQuest1-START\n");
	
	char world1[] = { "ABABABA" };
	char world2[] = { "QUICKSORT" };

	printf("\nQuest1-END\n");



	return 0;
}