/*
Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal.

Idem a questão acima, mas construa as funções usando referências (&).
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_NOME 50
#define TAM_VETCAD 10

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
void funcCadastro(TCadastro *vetCadastro, int *capacidade, int ultimaID){
    int cpf;
    char nome;
    int dataNasc;
    
    if (capacidade == ultimaID)
    {
        //realocar memoria 
    }
    printf("\nCADASTRO\n");
    setbuf(stdin, NULL);
    printf("\nNome.:");
    fgets(nome,TAM_NOME,stdin);
    setbuf(stdin, NULL);
    printf("\nCPF.:");
    scanf("%d",&cpf);
    printf("\nData nascimento.:");
    scanf("%d",&dataNasc);

    //passardo para a memoria alocada
    
   }



int main(){
    TCadastro *vetCalloc;
    int tamanhoVetCad = TAM_VETCAD;
    int ultimaID = 0;

    *vetCalloc = funcAllocCad (tamanhoVetCad);

    funcCadastro(*vetCadastro ,*capacidade);

    return EXIT_SUCCESS;
}