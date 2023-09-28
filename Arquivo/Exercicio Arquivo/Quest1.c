/*
1. Faça um programa que crie um arquivo TEXTO em disco, com o nome “dados.txt”, e escreva neste
arquivo em disco uma contagem que vá de 1 até 100, com um número em cada linha. Abra este
arquivo em um editor de textos, como por exemplo o Notepad ou o Wordpad do Windows. 
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

    int i;
    int num;

    arq = fopen("dadosQuest1.txt", "w");
    if (arq == NULL)
    {
        printf("\nFalha ao abrir o arquivo!\n");
        return 1;
    }
    for (i = 1; i <= TAM; i++)
    {
        num = i;
        fwrite(&num,sizeof(int),1,arq);
    }
    
    fclose(arq);

    arq = fopen("dadosQuest1.txt", "r");
    
    while ((fread(&num,sizeof(int), 1, arq))==1)
    {
        printf("%d - ", num);
    }
    
    fclose(arq);
    return 0;
}