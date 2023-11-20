#include "RecursionIncrement.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int numA = 10;
	int numB = 13;

	int soma = 0;

	int index = numB;

	soma = recursiveSum(numA, numB, &soma, index);
	
	printf("\nSoma = %d\n", soma);

	return 0;

}

int recursiveSum(int numA, int numB, int *soma, int index)
{
	if (index == 0)
	{
		*soma = *soma + numA;
		return *soma;
	}
	(*soma)++;
	index--;

	return recursiveSum(numA, numB, soma, index);
}
