/*
6) Construa um programa (main) que aloque em tempo de execução (dinamicamente) uma matriz de
ordem m x n (linha por coluna), usando 1+m chamadas a função malloc.
 Agora, aproveite este programa para construir uma função que recebendo os parâmetros m e n 
 aloque uma matriz de ordem m x n e retorne um ponteiro para esta matriz alocada. 
Crie ainda uma função para liberar a área de memória alocada pela matriz. 
Finalmente, crie um novo programa (main) que teste/use as duas funções criadas acima.
*/

#include <stdio.h>
#include <stdlib.h>

//função construtora de uma matriz dinamica com linhas e colonas declaradas pelo ususario
int **funcCostructMatrixDin(int linha, int coluna){
    int i;
    int **matrixBase; 
     matrixBase = (int**)malloc(linha * sizeof(int*));
     
     //criando as linhas
     for (i = 0; i < linha; i++)
     {
        matrixBase[i]=malloc(coluna* sizeof(int*));
     }
    return matrixBase;
}

//saida dos dados da matriz
void funcSaidaMatrix(int **matriz, int linha, int coluna){
    int i,j;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

//Função para desalocar matrix
void funcDestroyerMatrix(int **matrix, int linha){
    int i;
    for (i = 0; i < linha; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main(){
    int linha, coluna;
    int **matrix;
    printf("Construa uma matriz");
    printf("\nQuantidade de linhas.:");
    scanf("%d",&linha);
    printf("\nQuantidade de colunas.:");
    scanf("%d",&coluna);

    //função construtora de uma matriz dinamica com linhas e colonas declaradas pelo ususario
    matrix=funcCostructMatrixDin(linha, coluna);

    //saida dos dados da matriz
    funcSaidaMatrix(matrix,  linha,  coluna);

    //Função para desalocar matrix
    funcDestroyerMatrix(matrix, linha);

    return EXIT_SUCCESS;
}