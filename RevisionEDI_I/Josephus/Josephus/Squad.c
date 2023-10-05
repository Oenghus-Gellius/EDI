
#include "Squad.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Função costrutora da alocaçõa dinamica de dados
Tsquad* criaSquad() {
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

int firstSolSquad(Tsquad* squad, char** nome) {
    TNodo* ptrSoldier = (Tsquad*)malloc(sizeof(Tsquad));
    if (ptrSoldier == NULL)
    {
        printf("\nsoldado não alocado\n");
        return 0;
    }

    // Aloque memória para o campo 'nome' e copie o nome
    ptrSoldier->nome = (char*)malloc(strlen(nome) + 1);

    squad->tamanho++;
    squad->inicio = ptrSoldier;
    strcpy(ptrSoldier->nome, nome);

    if (squad->tamanho == 1)//Se for o primeiro
    {
        squad->cursor = ptrSoldier;
        squad->posicaoCorrente = ptrSoldier;
        ptrSoldier->next = ptrSoldier;
        ptrSoldier->ant = ptrSoldier;
    }
    else
    {
        ptrSoldier->next = squad->inicio;
        ptrSoldier->ant = squad->inicio->ant;
        squad->inicio->ant->next = ptrSoldier;
        squad->inicio->ant = ptrSoldier;
    }
    return 1;
}

int putEndSquad(Tsquad *squad, char *nome) {
    TNodo *ptrSoldier = (TNodo*)malloc(sizeof(TNodo));
    if (ptrSoldier == NULL)
    {
        printf("\nsoldado não alocado\n");
        return 0;
    }

    //lista cheia


    
    if (squad->inicio == NULL)
    {
        firstSolSquad(squad, nome);
    }
    else
    {
        // Aloca memória para o campo 'nome' e copie o nome
        ptrSoldier->nome = (char*)malloc(strlen(nome) + 1);

        strcpy(ptrSoldier->nome, nome);

        ptrSoldier->ant = squad->inicio->ant;
        ptrSoldier->next = squad->inicio;
        squad->inicio->ant->next = ptrSoldier;
        squad->inicio->ant = ptrSoldier;
        squad->tamanho++;
    }
    return 1;
}

//seta o nome dos elementos do squadron, alocando dinamicamente
void setSquad(Tsquad* squad, char **nomes, int qtd) {
    TNodo* ptrSoldier = (Tsquad*)malloc(sizeof(Tsquad));
    if (ptrSoldier == NULL)
    {
        printf("\nsoldado não alocado\n");
        return 0;
    }
    for (int i = 0; i < qtd; i++)
    {
        putEndSquad(squad, nomes[i]);
    }
}

void Josephus(Tsquad* squad) {
    TNodo *ptrSol;
    int luck;

    squad->cursor = squad->inicio;

    while (squad->tamanho > 1)
    {
        luck = rand() % squad->tamanho;

        printf("\nO roll foi %d ",luck);

        for (int i = 1; i <= squad->tamanho; i++)
        {
            squad->cursor = squad->cursor->next;
        }

        printf("\nO militar %s Morreu\n", squad->cursor->nome);

        //Função que remove um soldado por vez
        ptrSol = squad->cursor;
        ptrSol->next->ant = ptrSol->ant;
        ptrSol->ant->next = ptrSol->next;

        if (ptrSol == squad->inicio)
        {
            squad->inicio = squad->inicio->next;
        }
        free(ptrSol);

        squad->tamanho--;

        printf("\nSobraram.:\n");

        saidaSquad(squad);       
    }
    // Quando apenas um soldado sobrar, imprima o vencedor
    printf("\nO militar %s sobreviveu e venceu!\n", squad->inicio->nome);
}

void saidaSquad(Tsquad* squad) {
    TNodo* nodoSold = squad->inicio;
    nodoSold = squad->inicio;
    for (int i = 0; i < squad->tamanho; i++)
    {
        printf("\n%s\t", nodoSold->nome);
        nodoSold = nodoSold->next;
    }
    printf("\n");
}

void simulation() {
    Tsquad* squadAlpa = criaSquad();
    char* nomes[] = { "Soldado 1", "Soldado 2", "Soldado 3", "Soldado 4", "Soldado 5", "Soldado 6", "Soldado 7", "Soldado 8","Soldado 9","Soldado 10" };
    setSquad(squadAlpa, nomes, 10);
    saidaSquad(squadAlpa);

    Josephus(squadAlpa);
}

void test() {
    Tsquad* squadBeta = criaSquad();
    char nome[] = { "Neves" };
    char nome2[] = { "Grunsk" };

    
    putEndSquad(squadBeta, nome2);

    //firstSolSquad(squadBeta, nome);
    
    

    saidaSquad(squadBeta);
}
/*
int main() {
    //test();
    simulation();

    return 0;
}
*/

