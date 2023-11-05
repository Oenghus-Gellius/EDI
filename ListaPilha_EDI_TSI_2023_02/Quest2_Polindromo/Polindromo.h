/*
3) Uma palavra é um palíndromo se tem a mesma sequência de letras, quer seja lida da
esquerda para a direita ou da direita para a esquerda (exemplo: arara). Implemente uma
função para verificar se uma palavra é um palíndromo usando o TAD pilha*/


typedef struct Info {
	char caracter;
}TInfo;

typedef struct NodeStack {
	TInfo info;
	struct NodeStack* next;
}TNodeStack;

typedef struct bornStack {
	int tamanho;
	TNodeStack *head;
}TStack;


TStack *createrStack();

void overStack(TStack* stack);

int push(TStack *stack, TInfo info);

int pop(TStack *stack, TInfo *info);

int emptyStack(TStack *stack);

int sizeStack(TStack *stack);

int checkPolindormo(TStack *stack, const char * word);

