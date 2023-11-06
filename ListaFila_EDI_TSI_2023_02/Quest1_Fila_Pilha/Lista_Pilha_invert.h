/*1) Escreva uma função para inverter a ordem dos elementos de uma fila, usando uma
pilha como estrutura auxiliar.*/

typedef int TKey;

typedef struct Info {
	TKey key;
	int num;
	//demais componentes
}TInfo;

//-------------------------Alocar Elemento
TInfo* createrInfo();

TKey getKey(TInfo* info);
void setKey(TInfo* info, TKey key);

void destroyerInfo(TInfo* info);

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
TInfo* dequeueLine(TLine* line);

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