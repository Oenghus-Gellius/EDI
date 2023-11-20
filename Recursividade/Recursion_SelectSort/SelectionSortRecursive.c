#include "SelectionSortRecursive.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numVet[] = { 35, 14, 74, 13, 22, 68, 41, 96, 89, 53 };
	int size = 9;
	int index = 0;

	printVet(numVet, size);

	selectionSortRecursive(numVet, size, index);

	printVet(numVet, size);

	return 0;
}

void selectionSortRecursive(int* vetNum, int size, int index) {
	if (index == size - 1)
	{
		return;
	}

	int minIndex = index;
	for (int k = index + 1; k < size; k++)
	{
		if (vetNum[minIndex] > vetNum[k])
		{
			minIndex = k;
		}
	}
	if (minIndex != index)
	{
		int temp = vetNum[minIndex];
		vetNum[minIndex] = vetNum[index];
		vetNum[index] = temp;
	}
	selectionSortRecursive(vetNum, size, index + 1);
}

void printVet(int numVet[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", numVet[i]);
	}
	printf("\n");
}