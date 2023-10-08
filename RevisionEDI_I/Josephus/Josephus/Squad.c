#define _CRT_SECURE_NO_WARNINGS

#include "Squad.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//Fun��o costrutora da aloca��a dinamica de dados
Tsquad* criaSquad() {
    Tsquad* squad = (Tsquad*)malloc(sizeof(Tsquad));
    if (squad == NULL)
    {
        printf("\nSquad n�o alocado\n");
        return NULL;
    }
    squad->tamanho = 0;
    squad->cursor = NULL;
    squad->inicio = NULL;
    squad->fim = NULL;
    squad->posicaoCorrente = 1;

    return squad;
}

//ATEN��O
int firstSolSquad(Tsquad* squad, char* nome) {
    TNodo* ptrSoldier = (Tsquad*)malloc(sizeof(Tsquad));
    if (ptrSoldier == NULL)
    {
        printf("\nPrimeiro soldado n�o alocado\n");
        return 0;
    }
    printf("TAMANHO SQUAD %d\n", squad->tamanho);//TESTES
    
    // Aloque mem�ria para o campo 'nome' e copie o nome
    ptrSoldier->nome = (char*)malloc(strlen(nome) + 1);

    strcpy(ptrSoldier->nome, nome);
    //strcpy_s(ptrSoldier->nome, strlen(nome), nome);

    squad->tamanho++;

    if (squad->tamanho == 1)//Se for o primeiro
    {
        squad->fim = ptrSoldier;        
        squad->cursor = ptrSoldier;

        ptrSoldier->next = ptrSoldier;

        printf("TAMANHO SQUAD %d\n", squad->tamanho);//TESTES
    }
    else
    {
        ptrSoldier->next = squad->inicio;
        squad->fim = ptrSoldier;

    }
    squad->inicio = ptrSoldier;
    return 1;
}

int fullSquad(Tsquad* squad) {
    Tsquad* ptrSoldier = (Tsquad*)malloc(sizeof(Tsquad));
    if (squad == NULL)
    {
        printf("\nSquad n�o alocado\n");
        return 0;
    }
    free(squad);
    return 1;
}

int emptySquad(Tsquad* squad) {
    if (squad->tamanho == 0)
    {
        // print("\nSquad vazio!!!\n");
        return 0;
    }
    return 1;
}

int putEndSquad(Tsquad *squad, char *nome) {
   
    TNodo* ptrSoldier = (TNodo*)malloc(sizeof(TNodo));
    if (ptrSoldier == NULL)
    {
        printf("\nTNodo n�o alocado\n");
        return 0;
    }

    if (ptrSoldier->nome == NULL)
    {
        printf("\nMem�ria para nome n�o alocada\n");
        free(ptrSoldier);// Libera a mem�ria alocada para TNodo se a aloca��o para nome falhar
        return 0;
    }
    
    if (squad->tamanho == 0 )//Se for o primeiro
    {
        firstSolSquad(squad, nome); 
    }
    else
    {
        // Aloca mem�ria para o campo 'nome' e copie o nome
        ptrSoldier->nome = (char*)malloc(strlen(nome) + 1);
        
        TNodo* ptrfinder = squad->inicio;
        TNodo* ptrBackFinder = squad->inicio;       

        strcpy(ptrSoldier->nome, nome);
        //strcpy_s(ptrSoldier->nome, strlen(nome), nome);

        for (int i = 1; i < squad->tamanho; i++)
        {
            ptrBackFinder = ptrfinder;
            ptrfinder = ptrfinder->next;
        }
        ptrSoldier->next = ptrfinder->next;//conecta na frente e o bumbum?
        ptrBackFinder->next = ptrSoldier;//Bumbm ligado
        
        squad->fim->next = ptrSoldier;
        squad->fim = ptrSoldier;
        squad->tamanho++;
    }
    return 1;
}

//seta o nome dos elementos do squadron, alocando dinamicamente
void setSquad(Tsquad* squad, char **nomes, int qtd) {

    for (int i = 0; i < qtd; i++)
    {
        putEndSquad(squad, nomes[i]);
    }
}

void removeSoldier(Tsquad *squad, int index) {
    TNodo* ptrSoldier = squad->cursor;//Troquei inicio por cursor para n�o voltar no inicio
    TNodo* ptrBackSoldier = ptrSoldier;

    //Posicionao cursor onde deve ser removido
    for (int i = 1; i <= index; i++)//Aqui mudei para index(numero rolado)e n�o tamanho do squad
    {
        ptrBackSoldier = ptrSoldier;
        ptrSoldier = ptrSoldier->next;
    }
    //Reconectando a lista
    if (ptrSoldier == squad->inicio)//Se for o primeiro
    {
        squad->inicio = ptrSoldier->next;//squad->inicio = squad->next ?????
    }
    else//se for o ultimo
    {
        if (ptrSoldier == squad->fim)
        {
            ptrBackSoldier->next = squad->inicio;  // O �ltimo aponta para o in�cio
            squad->fim = ptrBackSoldier;  // Atualize squad->fim para o novo �ltimo
        }
        else
        {
            ptrBackSoldier->next = ptrSoldier->next;//conecta;
        }
    }
    squad->tamanho--;
    free(ptrSoldier);//Removendo
}

//recursiva
Tsquad *Josephus(Tsquad* squad) {
    TNodo *ptrSol;
    int roll;

    if (emptySquad(squad) == 0)
    {
        printf("\nSem soldados\n");
    }

    if (squad->tamanho == 1)//FINALIZA A RECURS�O, caso base
    {
        // Quando apenas um soldado sobrar, imprima o vencedor
        printf("\nO militar %s sobreviveu e VENCEU!\n", squad->inicio->nome);
        return squad;
    }

    roll = rand() % squad->tamanho;

    printf("\nO roll foi %d .:", roll);

    TNodo* ptrSoldier = squad->cursor;

    for (int i = 1; i <= roll; i++)
    {
        ptrSoldier = ptrSoldier->next;

    }

    printf("\nO militar %s Morreu\n", ptrSoldier->nome);

    //Fun��o que remove um soldado por vez
    removeSoldier(squad, roll);
    
    printf("\nTAMANH0.: %d\n", squad->tamanho);

    printf("\nSobraram.:\n");
    saidaSquad(squad);      

    return Josephus(squad);
}

int sizeSquad(Tsquad* squad) {
    return squad->tamanho;
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
    Tsquad* squad = criaSquad();
    char* nomes[] = { "Boizo", "Grunsk", "Neves", "Oenghus"};
    int tamanho = 0;
    
    setSquad(squad, nomes, 4);

    saidaSquad(squad);

    tamanho = sizeSquad(squad);

    //Josephus(squad, tamanho);
}

void test() {

    Tsquad* squad = criaSquad();
    char* nomeA[] = {"Grunsk"};
    char* nomeB[] = {"Neves"};
    char* nomeC[] = { "Oenghus" };
    char* nomeD[] = { "Mouto" };
    int tamanho = 0;

    putEndSquad(squad, *nomeA);
    putEndSquad(squad, *nomeB);
    firstSolSquad(squad, *nomeC);
    firstSolSquad(squad, *nomeD);

    saidaSquad(squad);

    tamanho = sizeSquad(squad);

    Josephus(squad);
}

int main() {
    test();
    //simulation();

    return 0;
}


