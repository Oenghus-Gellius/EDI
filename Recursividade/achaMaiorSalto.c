/*
Em C, faça a função recursiva achaMaiorSalto() que retorna a maior diferença (em modulo)
entre dois numeros consecutivos de um vetor de inteiros e quntas vezes essta diferença
aparece no vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criarVetor(int tamanho) {
    int *vetor;

    vetor = (int*)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Vetor não gerado\n");
        return NULL;
    }
    return vetor;
}

void preencherVetor(int* vetor, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
}

void saidaDados(int *vetor, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d\t", vetor[i]);
    }
    printf("\n");
}

//achando o maior não recursiva
int achaMaiorSaltoNoRecursiva(int *vetor, int tamanho){
    int i;
    int diferenca;
    int maiorDiferenca;

    for (i = 0; i < tamanho-1; i++)
    {
        if (vetor[i] > vetor[i+1])
        {
            diferenca = vetor[i] - vetor[i+1];
        }
        else
        {
            diferenca = vetor[i+1] - vetor[i];
        }
        if (maiorDiferenca < diferenca)
        {
            maiorDiferenca = diferenca;
        }
    }
    return maiorDiferenca;
}

//achando o maior recursiva
int achaMaiorSaltoRecursiva(int *vetor, int tamanho, int maiorDiferenca, int indice) {
    int diferenca;

    // Base case: quando atingir o final do vetor
    if (indice == tamanho - 1) {
        return maiorDiferenca;
    }

    // Calcula a diferença entre elementos consecutivos
    if (vetor[indice] > vetor[indice + 1]) {
        diferenca = vetor[indice] - vetor[indice + 1];
    } else {
        diferenca = vetor[indice + 1] - vetor[indice];
    }

    // Atualiza a maior diferença, se necessário
    if (diferenca > maiorDiferenca) {
        maiorDiferenca = diferenca;
    }

    // Chama a função recursivamente para o próximo índice
    return achaMaiorSaltoRecursiva(vetor, tamanho, maiorDiferenca, indice + 1);
}

int main() {
    int *vetor;
    int tamanho = 6;
    int i;
    int maiorDiferenca;

    srand(time(NULL));

    vetor = criarVetor(tamanho);

    // Preenchendo vetor
    preencherVetor(vetor, tamanho);

    // Saída de dados
    saidaDados(vetor, tamanho);

     maiorDiferenca = achaMaiorSaltoRecursiva(vetor, tamanho, 0, 0);

     printf("A maior diferença é.: %d",maiorDiferenca);

    free(vetor);

    return EXIT_SUCCESS;
}



