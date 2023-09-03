/*
4) Em linguagem C faça um laço de entrada de dados, onde o usuário deve digitar uma sequência de números, sem
limite de quantidade de dados a ser fornecida. O usuário irá digitar os números um a um, sendo
que caso ele deseje encerrar a entrada de dados, ele irá digitar o número Zero. 

No final, todos os dados digitados deverão ser salvos em um arquivo texto em disco. 

Atenção: os dados devem ser armazenados na memória deste modo... faça com que o programa inicie 
criando um ponteiro para um bloco (vetor) de 10 valores inteiros, 
e alocando dinamicamente espaço em memória para estebloco; 
após, caso o vetor alocado esteja cheio; aloque um novo vetor do tamanho do vetor anterior
adicionado com espaço para mais 10 valores (tamanho N+10, onde N inicia com 10), copie os
valores já digitados da área inicial para esta área maior e libere a memória da área inicial; 
repita este procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada vez que o
mesmo estiver cheio. Assim o vetor irá ser “expandido” de 10 em 10 valores. Usar a função
malloc para alocar memória de forma dinâmica.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_VETOR 10

//função de criação dinamica de um vetor, retornar ponterio do vetor;
int *funcCostruction(int capacidade,int *contador){
    int *vetorDados;
    vetorDados = (int*)malloc(capacidade*sizeof(int));

    if (vetorDados == NULL)
    {
        printf("Falhei miseravelmente em gerar um vetor Dinamico");
    }
    return vetorDados;
}

//funçaõ de realocação
int *funcReallocVetor(int *vetorDados, int *capacidade){
    int *vetRealocado;
    *capacidade=*capacidade+TAM_VETOR;
    vetRealocado=(int*)realloc(vetorDados,*capacidade*sizeof(int));

    if (vetRealocado == NULL)
    {
        printf("Falhei miseravelmente em realocar o vetor Dinamico");
    }
    return vetRealocado;
}

    void funcSaidaDados(int *vetorDados,int contDados){
        int i;
        for (i = 0; i < contDados; i++)
        {
            printf("Vetor[%d]=%d\t",i,vetorDados[i]);
        }
        printf("\n");
    }

    void funcPassandoArq(FILE *arquivo, int *vetorDados,int contDados){
        rewind(arquivo);
        int i;
        for (i = 0; i < contDados; i++)
        {
            fwrite(&vetorDados[i],sizeof(int),1,arquivo);
        }
    }

    // Chama a função para desalocar o vetor
    void funcDestroyVetor(int **vetorDados){
        free(vetorDados);
        *vetorDados=NULL;
    }

    //Função imprimindo o arquivo
    void funcSaidaArq(FILE *arquivo){
        int valor,i=0;
        rewind(arquivo);
        while (fread(&valor,sizeof(valor),1,arquivo)==1)
        {
            printf("vetor[%d]=%d\t",i,valor);
            i++;
        }
        printf("\n");
    }

int main(){
    int *vetorDados=NULL;
    int dadosEntrada;
    int contDados;
    int capacidade=TAM_VETOR;
    contDados=0;

    do
    {
        printf("\nEntre com os dados.:");
        scanf("%d",&dadosEntrada);
        if (dadosEntrada!=0)
        {
            if (contDados==0)
            {
                vetorDados=funcCostruction(capacidade, &contDados);
            }
            if (contDados == capacidade)
            {
                vetorDados=funcReallocVetor(vetorDados, &capacidade);
            }
            vetorDados[contDados]=dadosEntrada;//colocando os dados no vetor?
            contDados++;
        }
        
    //entrada de dados dinaico, saida = 0;       
    } while (dadosEntrada!=0);

    //Função saida de dados
    funcSaidaDados(vetorDados,contDados);

    FILE *arquivo;
    arquivo=fopen("dados.txt","rb+");
    if (arquivo==NULL)
    {
        printf("\nArquivo inexistent, abrinco um novo.\n");
        arquivo=fopen("dados.txt","wb+");
    }
    //Função para receber no arquivo os valores que estão no vetor dinamico
    funcPassandoArq(arquivo, vetorDados, contDados);

    funcDestroyVetor(&vetorDados);

    if (vetorDados==NULL)
    {
        printf("Memoria desalocada com sucesso!!\n");
    }
    else
    {
        printf("ERRRO na desalocação de memoria.\n");
    }

    //Função imprimindo o arquivo
    funcSaidaArq(arquivo);

    fclose (arquivo);

    return EXIT_SUCCESS;
}