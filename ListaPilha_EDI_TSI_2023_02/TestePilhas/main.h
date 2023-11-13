
/*4) Considere que um estacionamento seja composto por uma única entrada capaz de
guardar uma quantidade infinita de carros. Como só existe apenas uma entrada/saída no
estacionamento. Se chegar um cliente para retirar um carro que não seja o mais
próximo da saída, todos os carros bloqueando seu caminho sairão do estacionamento. O
carro do cliente será retirado do estacionamento, e os outros carros voltarão a ocupar a
mesma sequência inicial. Escreva um programa que processe um conjunto de chegadas
e saídas, identificadas, respectivamente, pelas letras E e S, e o número da placa do
carro. O programa deve imprimir uma mensagem sempre que um carro chegar ou sair.
Quando um carro sair do estacionamento, a mensagem deverá incluir o número de vezes
em que o carro foi manobrado para fora do estacionamento para permitir que os outros
carros saíssem.*/

typedef int TKey;
typedef struct Info {
	TKey key;
	char caracter;
	int carPlate;
}TInfo;

typedef struct NodeStack {
	TInfo info;
	struct NodeStack* next;
}TNodeStack;

typedef struct Stack {
	int size;
	TNodeStack* head;
}TStack;

//------------

typedef struct NodeList {
	TInfo info;
	struct NodeStack* next;
}TNodeList;

typedef struct List {
	int size;
	TNodeStack* start, * end, * cursor;
}TList;


//---------------------------LIST
TList* createrList();

int pushList(TList* list, TInfo info);

int finderList(TList* list, TInfo finderInfo, TInfo* info);

int removeList(TList* list, TInfo finderInfo, TInfo* info);

int emptyList(TList* list);

int fullList(TList* list);

int sizeList(TList* list);

void destroyerList(TList* list);

void printList(TList* list);

//---------------------------STACK
TStack* createrStack();

int pushStack(TStack* stack, TInfo info);

int popStack(TStack* stack, TInfo* info);

int emptyStack(TStack* stack);

void destructyStack(TStack* stack);

void printStack(TStack* stack);

TStack* selectInfoStack(TList* list);

void endAndPrint(TStack* stack);

//

void ValetParking4You(TStack* carStack, TInfo infoCar);
