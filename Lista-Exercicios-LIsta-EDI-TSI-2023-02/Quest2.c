#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Quest2.h"

//Função costrutora da alocaçõa dinamica de dados
Tsquad* criaSquad(){
    Tsquad* squadCriado = (Tsquad*)malloc(sizeof(Tsquad));
    if (squadCriado != NULL)
    {
        squadCriado->tamanho = 0;
        squadCriado->cursor = NULL;
        squadCriado->inicio = NULL;
        squadCriado->posicaoCorrente = 1;
    }
    return squadCriado;
}

//seta o nome dos elementos do squadron, alocando dinamicamente
void setSquad(Tsquad* squad, char nome){
    TNodo *ptrMilitar=(TNodo*)malloc(sizeof(TNodo));
    if (ptrMilitar == NULL)
    {
        return 0;
    }
    else
    {
        strcpy(ptrMilitar->nome,nome);
        squad->tamanho++;

        //verificando se é o primeiro nodo da lista
        if (squad->tamanho == 1)
        {
            ptrMilitar->ant = ptrMilitar;
            ptrMilitar->next = ptrMilitar;
        }
        else
        {
            strcpy(ptrMilitar->nome,nome);
            ptrMilitar->ant = squad->inicio->ant;
            ptrMilitar->next = squad->inicio;
            squad->inicio->ant->next = ptrMilitar;
            squad->inicio->ant = ptrMilitar;
            squad->tamanho++;
            return 1;
        } 
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

int main(){
    int tamanhoSquad = 10;
    char* nomes[]={"Soldado 1", "Soldado 2", "Soldado 3", "Soldado 4", "Soldado 5", "Soldado 6", "Soldado 7", "Soldado 8"};

    Tsquad* squadAlpa = criaSquad();


    return 0;
}