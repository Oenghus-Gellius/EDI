/*
Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal.

Idem a questão acima, mas construa as funções usando referências (&).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_VETCAD 5

//Estrutora de armazenamento dos dados do cadastro
typedef struct {
    char nome[TAM_NOME];
    int cpf;
    int datNasc;
    int ID;
}TCadastro;


//função alocadora(custrutora) memoria para a estrutura 
TCadastro funcAllocCad (int tamanho){
    TCadastro *constructVetorCad;
    constructVetorCad = (TCadastro*)calloc(tamanho, sizeof(TCadastro));
    //novoCadastro = (TCadastro *)malloc(sizeof(TCadastro));
    if (constructVetorCad == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    return *constructVetorCad;
}

//fazer a função de realocação

//função para fazer o cadastro
void funcCadastro(TCadastro *ptrVetAlloc, int *capacidade, int *ultimaID){
    int cpf;
    char nome;
    int dataNasc;
    
    do
    {
        if (*capacidade == *ultimaID)
        {
            *capacidade = *capacidade + TAM_VETCAD;
            //realocar memoria 
        }

        printf("\nCPF.:");
        scanf("%d",&cpf);
        if (cpf != 0)//sai do cadastro
        {
            printf("\nCADASTRO\n");
            setbuf(stdin, NULL);
            printf("\nNome.:");
            fgets(nome,TAM_NOME,stdin);
            setbuf(stdin, NULL);

            printf("\nData nascimento.:");
            scanf("%d",&dataNasc);

            //passar para a memoria alocada para registro dos dados
            strcpy((ptrVetAlloc[*ultimaID]).nome,nome);
            (ptrVetAlloc[*ultimaID]).cpf = cpf;
            (ptrVetAlloc[*ultimaID]).datNasc = dataNasc;

            (*ultimaID)++;
        }

    } while (cpf != 0);//sai do cadastro
}

//função de saida de dados
void funcSaida(TCadastro *ptrVetAlloc, int ultimaID){
    int i;
    printf("\nDados Cadastrados\n");
    for (i = 0; i < ultimaID; i++)
    {
        printf("\nNome.:%s", ptrVetAlloc[i].nome);
        printf("\nCPF.:%s", ptrVetAlloc[i].cpf);
        printf("\nData nascimento.: %d/%d/%d\n", ptrVetAlloc[i].datNasc);
    }
    
}

int main(){
    TCadastro *ptrVetAlloc;
    int capacidade;
    int ultimaID = 0;

    *ptrVetAlloc = funcAllocCad (capacidade);
    //ptrVetAlloc = (TCadastro*)calloc(capacidade, sizeof(TCadastro));

    //função cadastro
    funcCadastro(ptrVetAlloc, &capacidade, &ultimaID);

    funcSaida(ptrVetAlloc, ultimaID);

    return EXIT_SUCCESS;
}