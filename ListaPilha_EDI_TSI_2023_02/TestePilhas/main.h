
/*4) Considere que um estacionamento seja composto por uma �nica entrada capaz de
guardar uma quantidade infinita de carros. Como s� existe apenas uma entrada/sa�da no
estacionamento. Se chegar um cliente para retirar um carro que n�o seja o mais
pr�ximo da sa�da, todos os carros bloqueando seu caminho sair�o do estacionamento. O
carro do cliente ser� retirado do estacionamento, e os outros carros voltar�o a ocupar a
mesma sequ�ncia inicial. Escreva um programa que processe um conjunto de chegadas
e sa�das, identificadas, respectivamente, pelas letras E e S, e o n�mero da placa do
carro. O programa deve imprimir uma mensagem sempre que um carro chegar ou sair.
Quando um carro sair do estacionamento, a mensagem dever� incluir o n�mero de vezes
em que o carro foi manobrado para fora do estacionamento para permitir que os outros
carros sa�ssem.*/

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
