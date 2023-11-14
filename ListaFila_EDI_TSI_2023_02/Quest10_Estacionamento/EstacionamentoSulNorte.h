/*
10) Considere um estacionamento com capacidade infinita . Os carros chegam pelo sul
do estacionamento e saem pelo norte. Se um cliente quer retirar um carro que não está
próximo do extremo norte, todos os carros impedindo sua passagem são retirados, o
cliente retira seu carro e os outros carros são recolocados na mesma ordem que estavam
originalmente. 
Sempre que um carro sai, todos os carros do sul são movidos para frente,
de modo que as vagas fiquem disponíveis sempre no extremo sul do estacionamento.

Escreva um algoritmo que processa o fluxo de chegada/saída deste estacionamento.
Cada entrada para o algoritmo contém uma letra ’E’ para entrada ou ’S’ para saída, e o
número da placa do carro. 
O programa deve imprimir uma mensagem sempre que um
carro chegar ou sair. Quando um carro sair do estacionamento, a mensagem deverá
incluir o número de vezes em que o carro foi manobrado para fora do estacionamento
para permitir que os outros carros saíssem.
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