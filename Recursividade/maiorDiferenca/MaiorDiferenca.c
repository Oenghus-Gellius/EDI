#include "MaiorDiferenca.h"


#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 9;
	int maiorDiferenca = 0;
	int repeatDifference = 0;
	int index = 0;
	int vetNum[] = { 35, 14, 74, 14, 22, 68, 41, 96, 89, 53 };
	
	maiorDiferenca = achaMaiorSalto(vetNum, size, maiorDiferenca, &repeatDifference, index);

	printf("\nMaior Diferença %d repete %d\n", maiorDiferenca, repeatDifference);

	return 0;
}

int achaMaiorSalto(int* vetNum, int size, int maiorDiferenca, int *repeatDifference, int index)
{
	if (index == size)
	{
		return maiorDiferenca;
	}
	if(maiorDiferenca <= abs(vetNum[index] - vetNum[index + 1]))
	{
		if (maiorDiferenca == abs(vetNum[index] - vetNum[index + 1]))
		{
			(*repeatDifference)++;
		}
		else
		{
			*repeatDifference = 0;
		}
		maiorDiferenca = abs(vetNum[index] - vetNum[index + 1]);
	}
	printf("%d|%d = %d\n", vetNum[index], vetNum[index + 1], abs(vetNum[index] - vetNum[index + 1]));

	return achaMaiorSalto(vetNum, size, maiorDiferenca, repeatDifference, index + 1);
}
