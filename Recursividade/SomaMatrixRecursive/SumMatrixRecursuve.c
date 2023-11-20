#include "SumMatrixRecursuve.h"


#include <stdio.h>


int main() {
	int matrix[4][5] = {
		{1, 2, 0, 0, 0},
		{-1, 2, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};

	int lin = 4;
	int col = 5;

	int soma = 0;

	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	soma = sumMatrix(matrix, lin, col, 0, 0, soma);

	printf("Soma da matriz: %d\n", soma);

	return 0;
}

int sumMatrix(int matrix[][5], int lin, int col,int linIndex, int colIndex, int* soma) {
	if (lin == linIndex)
	{
		return 0;
	}
	else
	{
		if (col == colIndex)
		{
			return soma;
		}
		else
		{
			soma = soma + sumMatrix(matrix, lin, col, linIndex + 1, 0, soma);
			return soma;
		}
	}
}
