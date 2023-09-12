/*
7) Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_VET 2

typedef struct {
    unsigned int strDia;
    unsigned int strMes;
    unsigned int strAno;
    unsigned int strID;
} TDatNasc;

typedef struct {
    char strNome[100];
    TDatNasc datNasc;
    char strCPF[12];
    unsigned int strID;
} TCadastro;

// Alocar dinamicamente os vetores para guardar as structs

TCadastro *funcConstructCad(int capacidade) {
    TCadastro *vetorCad;
    vetorCad = malloc(capacidade * sizeof(TCadastro));
    return vetorCad;
}

TDatNasc *funcConstructDat(int capacidade) {
    TDatNasc *vetorDat;
    vetorDat = malloc(capacidade * sizeof(TDatNasc));
    return vetorDat;
}

// Realocação dos vetores para guardar as structs (falta implementar)
TCadastro *funcReallocCad(TCadastro *vetCadastro, int *capacidade) {
    TCadastro *vetorReallocCad;
    vetorReallocCad = realloc(vetCadastro, *capacidade * sizeof(TCadastro));
    return vetorReallocCad;
}

TDatNasc *funcReallocDat(TDatNasc *vetDatNasc, int *capacidade) {
    TDatNasc *vetorReallocDat;
    vetorReallocDat = realloc(vetDatNasc, *capacidade * sizeof(TDatNasc));
    return vetorReallocDat;
}

// Função para verificar se o CPF está repetido no cadastro
int funcCheckCad(const char *cpf, TCadastro *vetCadastro, int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(vetCadastro[i].strCPF, cpf) == 0) {
            return -1;
        }
    }
    return i;
}

// Função para cadastrar novas pessoas
void funcCadastro(TCadastro *vetCadastro, TDatNasc *vetDatNasc, int *count, int *capacidade, int *ultimoID) {
    int cadastro, check;
    char cpf[12]; // esse não pode se repetir
    char nome[100];
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;

    do {
        printf("\nDeseja fazer um cadastro? 1-SIM | 2-NÃO");
        scanf("%d", &cadastro);
        setbuf(stdin, NULL);

        if (cadastro != 2) {
            do {
                printf("\nCPF.:");
                fgets(cpf, 12, stdin);
                setbuf(stdin, NULL);
                check = funcCheckCad(cpf, vetCadastro, *count);

                if (check == -1) {
                    printf("\nCPF já cadastrado!!!");
                    printf("\nDigite novamente");
                }
            } while (check == -1);

            // Realocação de dados
            if (*count == *capacidade) {
                *capacidade = *capacidade + TAM_VET;
                vetCadastro = funcReallocCad(vetCadastro, capacidade);
                vetDatNasc = funcReallocDat(vetDatNasc, capacidade);
            }

            strcpy((vetCadastro)[*count].strCPF, cpf);

            printf("\nNome.:");
            fgets(nome, 100, stdin);
            setbuf(stdin, NULL);
            strcpy(vetCadastro[*count].strNome, nome);

            printf("\nData de nascimento.:");
            printf("\nDia.:");
            scanf("%d", &dia);
            vetDatNasc[*count].strDia = dia;

            printf("\nMes.:");
            scanf("%d", &mes);
            vetDatNasc[*count].strMes = mes;

            printf("\nAno.:");
            scanf("%d", &ano);
            vetDatNasc[*count].strAno = ano;

            vetCadastro[*count].strID = *ultimoID + 1;
            vetDatNasc[*count].strID = *ultimoID + 1;

            (*count)++;
            (*ultimoID)++;
        }
    } while (cadastro != 2);

    printf("\nCadastro Efetuado com sucesso!!!\n\n");
}

// Função de saída de dados dos cadastrados
void funcSaidaDados(TCadastro *vetCadastro, TDatNasc *vetDatNasc, int count) {
    int i;
    printf("\nDados Cadastrados\n");
    for (i = 0; i < count; i++) {
        printf("\nNome.:%s", vetCadastro[i].strNome);
        printf("\nCPF.:%s", vetCadastro[i].strCPF);
        printf("\nData nascimento.: %d/%d/%d\n", vetDatNasc[i].strDia, vetDatNasc[i].strMes, vetDatNasc[i].strAno);
    }
    printf("\nObrigado pela consulta!!!");
}

// Função para desalocar o vetor de TCadastro
void funcDestroyCad(TCadastro *vetCadastro) {
    free(vetCadastro);
}

// Função para desalocar o vetor de TDatNasc
void funcDestroyDat(TDatNasc *vetDatNasc) {
    free(vetDatNasc);
}

int main() {
    int count = 0;
    TCadastro *vetCadastro;
    TDatNasc *vetDatNasc;

    unsigned int capacidade = TAM_VET;
    int ultimoID = 0;  // Adicione esta variável para rastrear a última ID usada

    // Alocar dinamicamente os vetores para guardar as structs
    vetCadastro = funcConstructCad(capacidade);
    vetDatNasc = funcConstructDat(capacidade);

    // Função para cadastrar novas pessoas
    funcCadastro(vetCadastro, vetDatNasc, &count, &capacidade, &ultimoID);

    // Função de saída de dados dos cadastrados
    funcSaidaDados(vetCadastro, vetDatNasc, count);

    // Função para desalocar o vetor de TCadastro
    funcDestroyCad(vetCadastro);

    // Função para desalocar o vetor de TDatNasc
    funcDestroyDat(vetDatNasc);

    return EXIT_SUCCESS;
}
