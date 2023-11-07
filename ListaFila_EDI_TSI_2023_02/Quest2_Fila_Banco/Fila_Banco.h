
/*2) Faça um programa para simular as filas de um banco (considere 5 filas de
atendimento). O laço do programa principal deve conter os seguintes comandos:
 Sortear (rand) uma das filas e adicionar um cliente novo que chegou ao banco;
 Sortear (rand) uma das filas para ser atendido um cliente. Retirar um cliente da
fila que foi sorteada para ser atendida;
 Mostrar na tela o estado das filas, ou seja, a quantidade de clientes que tem em
cada uma das filas;
*/

#define MAX_MANE 150
#define NUM_CUSTOMERS 7

typedef int TKey;

typedef char TName[MAX_MANE];

typedef struct Info {
	TKey key;
	TName name;
	int num;
	//demais componentes
}TInfo;

//-----------------------------FILA


typedef struct NodeLine {
	TInfo info;
	struct Node* next;
}TNodeLine;

typedef struct Line {
	TNodeLine* start, * end;
	int size;
}TLine;

TLine* createrLine();

int queueLine(TLine* line, TInfo info);
int dequeueLine(TLine* line, TInfo* info);

int emptyLine(TLine* line);
int fullLine(TLine* line);
int sizeLine(TLine* line);

void destroyerLine(TLine* line);

//=====

void printLine(TLine* line);
