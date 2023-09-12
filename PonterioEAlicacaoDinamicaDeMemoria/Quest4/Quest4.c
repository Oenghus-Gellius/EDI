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

//funçaõ construtora do vetor dinamico de dados 
int *funcConstruct(int capacidade){
    int *vetorCosntruido;
    vetorCosntruido=(int*)malloc(capacidade * sizeof(unsigned int));
    if (vetorCosntruido == NULL)
    {
        printf("\nfalha na alocação do vetor dinamico");
    }
    else
    {
        printf("\nVetor alocado com sucesso!");
    }
    return vetorCosntruido;
}

//função que expande o vetor
int *funcExpasionVet(int *vetorDados, int *capacidade){
    int *vetNovo;
    int i;
    int tamVetBase=*capacidade;
    *capacidade=*capacidade+TAM_VETOR;
    vetNovo=funcConstruct(*capacidade);

    //prenchedo o novo vetor com o conteudo do antigo;
    for (i = 0; i < tamVetBase; i++)
    {
        vetNovo[i]=vetorDados[i];
    }
    return vetNovo;
}

//funçaõ saida de dados do vetor alocado
void funcSaidaDados(int *vetorDados, int count){
    int i;
    for (i = 0; i < count; i++)
    {
        printf("Vetor[%d]=%d\t",i,vetorDados[i]);
    }
    printf("\n");
}

//função passando dados do vetorDianmico para o arquivo
void funcCopyDadosParaAquivo(FILE *arquivo,int *vetorDados,int count){
    int i;
    rewind(arquivo);
    for (i = 0; i < count; i++)
    {
        fwrite(&vetorDados[i],sizeof(int),1,arquivo);
    }
}

//função para desalocar o vetor dinamico
void funcDestroyer(int **vetorDados){
    free(vetorDados);
    *vetorDados = NULL;
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
    int entradaDados;
    int *vetorDados;
    int capacidade = TAM_VETOR;
    int count=0;

     do
     {
        printf("\nEntre com o dado.:");
        scanf("%d",&entradaDados);

        if (entradaDados != 0)
        {
            if (count == 0)
            {
                vetorDados=funcConstruct(capacidade);
            }
            if (count==capacidade)
            {
                vetorDados=funcExpasionVet(vetorDados, &capacidade);
            }
            vetorDados[count]=entradaDados;
            count++;
        }
        //entrada de dados
     } while (entradaDados != 0);

    //funçaõ saida de dados do vetor alocado
     funcSaidaDados(vetorDados, count);

     //abrindo ou criando um arquivo para armazenamento 
    FILE *arquivo;
    arquivo = fopen("dados.txt","rb+");
        if (arquivo==NULL)
    {
        printf("\nArquivo inexistent, abrinco um novo.\n");
        arquivo=fopen("dados.txt","wb+");
    }

    //função passando dados do vetorDianmico para o arquivo
    funcCopyDadosParaAquivo(arquivo, vetorDados, count);
     
    //função para desalocar o vetor dinamico
    funcDestroyer(&vetorDados);

    //Função imprimindo o arquivo
    funcSaidaArq(arquivo);

    //fechando o arquivo
    fclose(arquivo);

    return EXIT_SUCCESS;
}