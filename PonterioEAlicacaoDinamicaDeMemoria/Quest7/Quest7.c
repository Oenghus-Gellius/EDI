/*
7) Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma uma função que receba este ponteiro e
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
            return i;
        }
    }
    return -1;
}

// Função para cadastrar novas pessoas
void funcCadastro(TCadastro **vetCadastro, TDatNasc **vetDatNasc, int *count, int *capacidade, int *ultimoID) {
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
                check = funcCheckCad(cpf, *vetCadastro, *count);

                if (check != -1) {
                    printf("\nCPF já cadastrado!!!");
                    printf("\nDigite novamente");
                }
            } while (check != -1);

            // Realocação de dados
            if (*count == *capacidade) {
                *capacidade = *capacidade + TAM_VET;
                *vetCadastro = funcReallocCad(*vetCadastro, capacidade);
                *vetDatNasc = funcReallocDat(*vetDatNasc, capacidade);
            }

            strcpy((*vetCadastro)[*count].strCPF, cpf);

            printf("\nNome.:");
            fgets(nome, 100, stdin);
            setbuf(stdin, NULL);
            strcpy((*vetCadastro)[*count].strNome, nome);

            printf("\nData de nascimento.:");
            printf("\nDia.:");
            scanf("%d", &dia);
            (*vetDatNasc)[*count].strDia = dia;

            printf("\nMes.:");
            scanf("%d", &mes);
            (*vetDatNasc)[*count].strMes = mes;

            printf("\nAno.:");
            scanf("%d", &ano);
            (*vetDatNasc)[*count].strAno = ano;

            (*vetCadastro)[*count].strID = *ultimoID + 1;
            (*vetDatNasc)[*count].strID = *ultimoID + 1;

            (*count)++;
            (*ultimoID)++;
        }
    } while (cadastro != 2);

    printf("\nCadastro Efetuado com sucesso!!!\n\n");
}

// Função para abrir o arquivo e posicionar para o próximo registro
void funcAbrirArquivoParaEscrita(FILE **arquivo) {
    *arquivo = fopen("dados.txt", "ab");
    if (*arquivo == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }
}

// Função para copiar os dados do vetor para o arquivo
void funcCopiarDadosParaArquivo(FILE *arquivo, TCadastro *vetCadastro, TDatNasc *vetDatNasc, int count, int ultimoID) {

    // Calcular a próxima ID com base nos registros existentes no arquivo
    int proximaID = ultimoID + 1;  // Inicialize 'proximaID' com a próxima ID disponível

    fseek(arquivo, 0, SEEK_END); // Posiciona o ponteiro no final do arquivo

    for (int i = 0; i < count; i++) {
        vetCadastro[i].strID = proximaID;
        vetDatNasc[i].strID = proximaID;
        proximaID++;

        fwrite(&vetCadastro[i], sizeof(TCadastro), 1, arquivo);
        fwrite(&vetDatNasc[i], sizeof(TDatNasc), 1, arquivo);
    }

    fclose(arquivo);
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

// Função para imprimir o conteúdo do arquivo
void funcSaidaArq(FILE *arquivo) {
    TCadastro cadastro;
    TDatNasc datNasc;

    rewind(arquivo);

    printf("\nDados do ARQUIVO\n");

    while (fread(&cadastro, sizeof(TCadastro), 1, arquivo) == 1 &&
           fread(&datNasc, sizeof(TDatNasc), 1, arquivo) == 1) {
        printf("\nID.:%d\tNome.: %s", cadastro.strID, cadastro.strNome);
        printf("\nCPF.: %s", cadastro.strCPF);
        printf("\nData nascimento.: %d/%d/%d\n", datNasc.strDia, datNasc.strMes, datNasc.strAno);
    }
    printf("\n");
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

    // Abrindo ou criando um arquivo para armazenamento
    FILE *arquivo;

    // Função para abrir o arquivo e posicionar para o próximo registro
    funcAbrirArquivoParaEscrita(&arquivo);

    // Lê os dados existentes no arquivo e calcula a última ID
    while (fread(&vetCadastro[count], sizeof(TCadastro), 1, arquivo) == 1 &&
           fread(&vetDatNasc[count], sizeof(TDatNasc), 1, arquivo) == 1) {
        if (vetCadastro[count].strID > ultimoID) {
            ultimoID = vetCadastro[count].strID;
        }
        count++;
    }
    printf("\nDados carregados do arquivo.\n");

    // Função para cadastrar novas pessoas
    funcCadastro(&vetCadastro, &vetDatNasc, &count, &capacidade, &ultimoID);

    // Função para copiar os dados para o arquivo (após o cadastro)
    funcCopiarDadosParaArquivo(arquivo, vetCadastro, vetDatNasc, count, ultimoID);

    // Função de saída de dados dos cadastrados
    funcSaidaDados(vetCadastro, vetDatNasc, count);

    // Função para desalocar o vetor de TCadastro
    funcDestroyCad(vetCadastro);

    // Função para desalocar o vetor de TDatNasc
    funcDestroyDat(vetDatNasc);

    // Função imprimindo o arquivo | NÃO ESTA SAINDO!!!!
    funcSaidaArq(arquivo);

    fclose(arquivo);

    return EXIT_SUCCESS;
}
