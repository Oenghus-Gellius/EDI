/*
10) Considere um estacionamento com capacidade infinita . Os carros chegam pelo sul
do estacionamento e saem pelo norte. Se um cliente quer retirar um carro que n�o est�
pr�ximo do extremo norte, todos os carros impedindo sua passagem s�o retirados, o
cliente retira seu carro e os outros carros s�o recolocados na mesma ordem que estavam
originalmente. 
Sempre que um carro sai, todos os carros do sul s�o movidos para frente,
de modo que as vagas fiquem dispon�veis sempre no extremo sul do estacionamento.

Escreva um algoritmo que processa o fluxo de chegada/sa�da deste estacionamento.
Cada entrada para o algoritmo cont�m uma letra �E� para entrada ou �S� para sa�da, e o
n�mero da placa do carro. 
O programa deve imprimir uma mensagem sempre que um
carro chegar ou sair. Quando um carro sair do estacionamento, a mensagem dever�
incluir o n�mero de vezes em que o carro foi manobrado para fora do estacionamento
para permitir que os outros carros sa�ssem.
*/

typedef int TKey;

typedef struct Info {
	TKey key;
	int carPlate;
	int movement;
	char status;
}TInfo;

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

void printLine(TLine* line);

void ValetParking4You(TLine* garageLine, TInfo carInfo);