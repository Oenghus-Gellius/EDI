/*
3) Uma palavra � um pal�ndromo se tem a mesma sequ�ncia de letras, quer seja lida da
esquerda para a direita ou da direita para a esquerda (exemplo: arara). Implemente uma
fun��o para verificar se uma palavra � um pal�ndromo usando o TAD pilha*/


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

