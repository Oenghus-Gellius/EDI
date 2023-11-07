/*1) Escreva uma fun��o para inverter a ordem dos elementos de uma fila, usando uma
pilha como estrutura auxiliar.*/

typedef int TKey;

typedef struct Info {
	TKey key;
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

//---------------------------------------STACK

typedef struct NodeStack {
	TInfo info;
	struct NodeStack* next;
}TNodeStack;

typedef struct Stack {
	int size;
	TNodeStack* head;
}TStack;


TStack* createrStack();

int pushStack(TStack* stack, TInfo info);

int popStack(TStack* stack, TInfo* info);

int emptyStack(TStack* stack);

int sizeStack(TStack* stack);

void destructyStack(TStack* stack);

//----------------------------------------INDO ALLOC






//----------------------------------------

void invertLine(TLine *line);

void printLine(TLine *line);