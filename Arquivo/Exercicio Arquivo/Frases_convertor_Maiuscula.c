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
#define MAX_FRASE 2

//destroi vetor simples
void DestroyChar(char *vetChar) {
    free(vetChar);
}

//destroi vetor de caracteres
void destroyVetChar(char **vetChar){
    int i = 0;
    while (i < MAX_FRASE)
    {
        free(vetChar[i]);
        i++;
    }
    free(vetChar);    
}

//Função para alocar um vetor de caracteres
char *criarFrase(){
    char *newFrase =(char*)malloc(MAX_TAM * sizeof(char));
    if (newFrase != NULL)
    {
        return newFrase;
    }
    else
    {
        printf("\nErro ao armazenar frase!!!\n");
        return NULL;
    }
}

char **criarVetFrases(){
    char **vetFrases = (char**)malloc(MAX_FRASE * sizeof(char*));
     if (vetFrases != NULL)
    {
        for (int i = 0; i < MAX_FRASE; i++)
        {
            vetFrases[i] = (char*)malloc(MAX_TAM * sizeof(char));
            if (vetFrases[i] == NULL)
            {
                printf("\nErro ao alocar memória para a frase %d!!!\n", i + 1);
                return NULL;
            }
        }
        return vetFrases;
    }
    else
    {
        printf("\nErro ao alocar memória para o vetor de frase!!!\n");
        return NULL;      
    }
}

//Funçaõ recebe um vetor de caracteres e converte o conteudo desse vertor em maiuscula
void convertMaiuscula(const char *frase, char *fraseMaiusc) {
    int i;
    for (i = 0; frase[i]; i++) {
        fraseMaiusc[i] = (char)toupper((unsigned char)frase[i]);
    }
    fraseMaiusc[i] = '\0';
}

//imprime na tela um vetor de caracteres
void display(char **frases){

    for (int i = 0; i < MAX_FRASE; i++)
    {
        printf("%s",frases[i]);
    }
}

FILE *criarArq(const char *nomeArquivo){
    FILE *arq;
    arq = fopen(nomeArquivo,"w");
    printf("\ncriado arquivo!!!\n");
    if (arq == NULL)
    {
        printf("\nErro ao criar o arquivo!!!\n");
    }   
    return arq;
}

void escreveArqVetChar(FILE *arq, char **frases, int tamanho) {
    unsigned int i = 0;
    while (i < tamanho)
    {
        //fseek(arq, (i) * sizeof(char), SEEK_SET);
        fwrite(&frases[i], sizeof(char), MAX_TAM, arq);
        i++;
    }
}

char **lerArq(const char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo,"r");
    char **ptrFrasesVet = criarVetFrases();

    int i = 0;

    if (arq == NULL)
    {
        printf("\nErro ao abrir o arquivo!!!\n");
    }   
    else
    {
        printf("\n\tFrases no arquivo\t\n");

        rewind(arq);
        
        while (fgets(ptrFrasesVet[i], MAX_TAM, arq) != NULL) {
            
            printf("\n%s", ptrFrasesVet[i]);
        }
    }
    return ptrFrasesVet;
}


//recebe frase por frase e armazena no vetor criado na funçaõ criarFrases.
void app(){
    int i;

    char nArqEnter[MAX_TAM];
    char nArqSalvo[MAX_TAM];

    char *ptrFrase;
    char *ptrMaisc;

    char **ptrVetFrase = criarVetFrases();
    char **ptrVetMaisc = criarVetFrases();

    char **ptrVetlidoArq;

    FILE *arq;

    printf("\nDigite o nome do arquivo\n");
    fgets(nArqEnter,MAX_TAM,stdin);
    nArqEnter[strcspn(nArqEnter, "\n")] = '\0'; // Remover a quebra de linha

    convertMaiuscula(nArqEnter, nArqSalvo);

    arq = criarArq(nArqSalvo);//ciar o arquivo

    //Recebe as frases do teclado e 
    for (i = 0; i < MAX_FRASE; i++)
    {
        ptrFrase = criarFrase();
        
        if (ptrVetFrase == NULL) 
        {
            return; // Verificação de erro ao alocar memória
        }
        printf("\nInsira A Frase n%d\n",i+1);
        fgets(ptrFrase, MAX_TAM, stdin);
        setbuf(stdin,NULL);

        ptrMaisc = criarFrase();

        if (ptrVetMaisc == NULL) 
        {
        return; // Verificação de erro ao alocar memória
        }

        convertMaiuscula(ptrFrase, ptrMaisc);//converte para maiuscula

        strcpy(ptrVetFrase[i],ptrFrase);//passa a frase para o vetor

        strcpy(ptrVetMaisc[i],ptrMaisc);//passa a frase para o vetor

    }
        
    printf("\nConvertido\n");

    DestroyChar(ptrMaisc);
    DestroyChar(ptrFrase);

    display(ptrVetMaisc);

    escreveArqVetChar(arq, ptrVetMaisc, MAX_FRASE) ;//escreve no arquivo

    fclose(arq);

    ptrVetlidoArq = lerArq(nArqEnter);

    destroyVetChar(ptrVetFrase);//destroi os espaços alocados
    destroyVetChar(ptrVetMaisc);//destroi os espaços alocados
    destroyVetChar(ptrVetlidoArq);

    fclose(arq);
}


int main(){

    app();

    printf("\nFIM\n");

    system("pause");

    return 0;
}


