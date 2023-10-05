/*
2) Implementar o problema de Josephus utilizando o TAD lista com duplamnete encadeada
circular. Defina a estrutura de dados para resolver esse problema.
Problema: um grupo de soldados está cercado pelo inimigo e existe apenas um cavalo para a
fuga. Decidiu-se que o soldado que será capturado, ou seja, conseguirá fugir, será definido na
sorte, independente da patente. O processo de escolha será por eliminação, sendo que o último
soldado a ser selecionado usuaria o cavalo para fugir. O processo de eliminação consiste em:
organizar os soldados em volta da fogueira; escolher um soldado para iniciar a contagem e
sortear um único número. Ao final da contagem, o soldado escolhido é eliminado e o processo é
reiniciado a partir do próximo soldado, até só restar o soldado ganhador. A cada rodada, deve
ser impressoos nomes dos soldados elimininados, na ordema de eliminação e os nomes dos
soldados ainda particicipantes do jogo.
*/


typedef struct Nodo {
    char *nome;
    struct Nodo* next, * ant;
}TNodo;

typedef struct squad {
    TNodo* inicio, * cursor;
    int tamanho, posicaoCorrente;
}Tsquad;


Tsquad* criaSquad();

int firstSolSquad(Tsquad* squad, char** nome);

int putEndSquad(Tsquad* squad, char* nome);

void setSquad(Tsquad* squad, char** nomes, int qtd);

void Josephus(Tsquad* squad);

void saidaSquad(Tsquad* squad);
