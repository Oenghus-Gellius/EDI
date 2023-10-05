/*
2) Implementar o problema de Josephus utilizando o TAD lista com duplamnete encadeada
circular. Defina a estrutura de dados para resolver esse problema.
Problema: um grupo de soldados est� cercado pelo inimigo e existe apenas um cavalo para a
fuga. Decidiu-se que o soldado que ser� capturado, ou seja, conseguir� fugir, ser� definido na
sorte, independente da patente. O processo de escolha ser� por elimina��o, sendo que o �ltimo
soldado a ser selecionado usuaria o cavalo para fugir. O processo de elimina��o consiste em:
organizar os soldados em volta da fogueira; escolher um soldado para iniciar a contagem e
sortear um �nico n�mero. Ao final da contagem, o soldado escolhido � eliminado e o processo �
reiniciado a partir do pr�ximo soldado, at� s� restar o soldado ganhador. A cada rodada, deve
ser impressoos nomes dos soldados elimininados, na ordema de elimina��o e os nomes dos
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
