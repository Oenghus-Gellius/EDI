/*
Faça um programa em C que lê 5 frases de, no máximo, 50 caracteres cada uma
 e armazene-as em um arquivo. Mas, antes de gravar cada frase no arquivo, 
 é necessário converter todas as suas letras para maiúsculas. Os nome do 
 arquivo será fornecido, via teclado, pelo usuário. A função que converte 
 maiuscula para minúscula é o toupper(). A seguir, feche o arquivo e reabra 
 para leitura exibindo todas as frases convertidas. Como cada texto pode ter 
 tamanho diferente, será necessário gravar antes de cada frase o tamanho do 
 texto a ser lido. logo serão necessários dois comandos de gravação e leitura
  (um para o numero inteiro que indica a quantidade de caracteres da frase 
  e outro para a frase com o tamanho lido)

  seria melhor criar linha por linha para convertes linha por linha e assim a função
  converte serviria para qualquer frase
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

 #include <ctype.h>

#define MAX_TAM 50
#define MAX_FRASE 5

/*
FILE *criarArq(const char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo,"w");
    if (arq == NULL)
    {
        printf("\nErro ao criar o arquivo!!!\n");
    }   
}

FILE *lerArq(const char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo,"r");
    if (arq == NULL)
    {
        printf("\nErro ao criar o arquivo!!!\n");
    }      
}
*/

void *escreveArq(FILE *arq, const char *frase) {
    if (arq != NULL) {
        fprintf(arq, "%s\n", frase);
    }
}

void DestroyVetChar(char *vetChar) {
    free(vetChar);
}

//Função para alocar um vetor de caracteres
char *criarFrase(){
    char *newFrase =(char*)malloc(MAX_TAM * sizeof(char*));
    if (newFrase != NULL)
    {
        for (int i = 0; i < MAX_FRASE; i++)
        {
            newFrase[i] = (char*)malloc(MAX_TAM * sizeof(char));
            if (newFrase[i] == NULL)
            {
                printf("\nErro ao alocar memória para a frase %d!!!\n", i + 1);
                return NULL;
            }
        }
        return newFrase;
    }
    else
    {
        printf("\nErro ao criar vetor!!!\n");
        return NULL;
    }
}

//Funçaõ recebe um vetor de caracteres e converte o conteudo desse vertor em maiuscula
void convertMaiuscula(char *frase, char *fraseMaiusc) {
    int i;
    while (frase[i] != '\0') 
    {
        fraseMaiusc[i] = (char)toupper((unsigned char)frase[i]);
        i++;
    }
}

//imprime na tela um vetor de caracteres
void display(char **frases){

    for (int i = 0; i < MAX_FRASE; i++)
    {
        printf("\n%s\n",frases[i]);
    }
}

//recebe frase por frase e armazena no vetor criado na funçaõ criarFrases.
void app(){
    int i;
    char nomeDoArquivo[MAX_TAM];

    char **ptrVetFrase;
    char **ptrVetMaisc;


    printf("\nDigite o nome do arquivo\n");
    fgets(nomeDoArquivo,MAX_TAM,stdin);
    nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0'; // Remover a quebra de linha

    //criarArq(nomeDoArquivo);

    for (i = 0; i < MAX_FRASE; i++)
    {
        ptrVetFrase[i] = criarFrase(MAX_FRASE);

        if (ptrVetFrase == NULL) 
        {
            return; // Verificação de erro ao alocar memória
        }
        printf("\nInsira A Frase n%d\n",i+1);
        fgets(ptrVetFrase[i], MAX_TAM, stdin);
        setbuf(stdin,NULL);
    }
    
    for (i = 0; i < MAX_FRASE; i++)
    {
        ptrVetMaisc = criarFrase(MAX_FRASE);
        if (ptrVetMaisc == NULL) 
        {
        return; // Verificação de erro ao alocar memória
        }
    }
    
    display(ptrVetFrase);

    printf("\nConvertido\n");

    convertMaiuscula(ptrVetFrase, ptrVetMaisc);

    display(ptrVetMaisc);
}

void destroyData(){

}

int main(){

    app();

    return 0;
}


