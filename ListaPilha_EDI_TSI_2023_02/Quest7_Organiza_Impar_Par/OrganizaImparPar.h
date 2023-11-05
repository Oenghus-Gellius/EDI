/*7) 4. Implemente um programa que leia 15 números e proceda, para cada um deles,
como segue:

• se o número for par, insira-o na pilha;

• se o número lido for ímpar, retire um número da pilha;

• Ao final, esvazie a pilha imprimindo os elementos.*/


typedef struct Info {
	char caracter;
	int num;
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
	TNodeStack* start, *end, *cursor;
}TList;


//---------------------------LIST
TList* createrList();

int pushList(TList* list, TInfo info);

int finderList(TList* list, TInfo finderInfo, TInfo* info);

int removeList(TList* list, TInfo finderInfo, TInfo *info);

int emptyList(TList* list);

int fullList(TList* list);

int sizeList(TList* list);

void destroyerList(TList *list);

void printList(TList* list);

//---------------------------STACK
TStack *createrStack();

int pushStack(TStack* stack, TInfo info);

int popStack(TStack* stack, TInfo* info);

int emptyStack(TStack* stack);

void destructyStack(TStack* stack);

void printStack(TStack* stack);

TStack* selectInfoStack(TList* list);

void endAndPrint(TStack* stack);



