/*
2. Faça um programa que crie um arquivo BINÁRIO em disco, com o nome “dados.bin”, e escreva neste
arquivo em disco uma contagem que vá de 1 até 100, com um número em cada linha. Abra este
arquivo em um editor de textos e observe como ficou o seu conteúdo (ilegível!). 
*/
    /*
    r: abre um arquivo no modo leitura.
    w: abre ou cria um arquivo de texto no modo escrita.
    a: abre um arquivo no modo inclusão (append).
    r+: abre um arquivo nos modos leitura e escrita.
    a+: abre um arquivo nos modos leitura e escrita.
    w+: abre um arquivo nos modos leitura e escrita.
    */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(){

    FILE *arq;
    int num;

    arq = fopen("dadosQuest2.bin", "wb");

    if(arq == NULL)
    {
        printf("\nFalha ao abrir o arquivo!\n");
        return 1;
    }
    //salvado em disco 1 a 100
    for (int i = 1; i <= TAM; i++)
    {
        num = i;
        fwrite(&num, sizeof(int), 1, arq);
    }
    fclose(arq);

    //saida de tela do arquivo

    arq = fopen("dadosQuest2.bin", "rb");

    printf("\nConteúdo do arquivo:\n");
    while (fread(&num,sizeof(int), 1, arq)==1)
    {
        printf("\n%d", num);
    }
    
    fclose(arq);
    return 0;
}