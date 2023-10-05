#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Quest2.h"

//Função costrutora da alocaçõa dinamica de dados
Tsquad* criaSquad(){
    Tsquad* squadCriado = (Tsquad*)malloc(sizeof(Tsquad));
    if (squadCriado == NULL)
    {
        printf("\nSquad não alocado\n");
        return 0;
    }
    squadCriado->tamanho = 0;
    squadCriado->cursor = NULL;
    squadCriado->inicio = NULL;
    squadCriado->posicaoCorrente = NULL;
    return squadCriado;
}

int firstSolSquad(Tsquad *squad, char *nome){
TNodo *ptrSoldier = (Tsquad*)malloc(sizeof(Tsquad));
    if (ptrSoldier == NULL)
    {
        printf("\nsoldado não alocado\n");
        return 0;
    }

    squad->tamanho++;
    squad->inicio = ptrSoldier;

    if (squad->tamanho < 1)//Se for o primeiro
    {
        squad->cursor = ptrSoldier;
        squad->posicaoCorrente = ptrSoldier;
        squad->inicio->next = ptrSoldier;
        squad->inicio->ant = ptrSoldier; 
    }
    else
    {
        

        squad->inicio = ptrSoldier;
        squad->inicio->next = squad->inicio;
        squad->inicio->ant = squad->inicio->ant; 
    }
    return 1; 
}

//seta o nome dos elementos do squadron, alocando dinamicamente
void setSquad(Tsquad* squad, char nome){
TNodo *ptrSoldier = (Tsquad*)malloc(sizeof(Tsquad));
    if (ptrSoldier == NULL)
    {
        printf("\nsoldado não alocado\n");
        return 0;
    }
}

void saidaDados(Tsquad* squad, TNodo* militar){
    while (militar->next != NULL)
    {
        printf("\n%s\n",militar->nome);
    }
}


void Josephus(Tsquad* squadEmFuga){
    int n, i;
    int *ptrAntSev, *ptrSev;

    n = rand()%1 - squadEmFuga->tamanho-1;

}

void saidaSquad(Tsquad *squad){
    TNodo* nodoSold = squad->inicio;
    for (int i = 0; i < squad->tamanho; i++)
    {
        printf("%s\t", nodoSold->nome);
    }
    printf("\n");  
}

void simulation(Tsquad *squad){
    Tsquad* squadAlpa = criaSquad();
    char* nomes[]={"Soldado 1", "Soldado 2", "Soldado 3", "Soldado 4", "Soldado 5", "Soldado 6", "Soldado 7", "Soldado 8","Soldado 9","Soldado 10"};

}

int main(){
    Tsquad* squadBeta = criaSquad();
    char nome[] = {"Neves"};

    firstSolSquad(squadBeta, nome);
    saidaSquad(squadBeta);





    return 0;
}