/*6) Implemente uma função que transfira os elementos da pilha p1 para a pilha p2 de
modo que os elementos de p2 estejam na mesma ordem que em p1.*/

typedef struct Info {
	char caracters;
}TInfo;

typedef struct NodeStack {
	TInfo info;
	struct NodeStack* next;
}TNodeStack;

typedef struct Stack{
	int size;
	TNodeStack* head;
}TStack;

TStack* createrStack();

int push(TStack* stack, TInfo info);

int pop(TStack* stack, TInfo* info);

int emptyStack(TStack* stack);

void destructStack(TStack* stack);


TStack *cloneStack(TStack *stack);

void printStack(TStack* stack);