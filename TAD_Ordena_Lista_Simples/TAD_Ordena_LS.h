/* Fazer um programa que ordene lista elcadeadas simples*/

typedef struct NodoList{
    unsigned int codList;
    struct NodoList *nextList;
}TNodoList;


typedef struct List{
    int tamanho;
    TNodoList *inicio, *fim, *cursor;
}TList;


TList *bornList();

int firstList(TList *firstList, int codListEnter);

int endList(TList *endlist, int codEnter);

int sizeList(TList *list);

void ascendingSortList(TList *listEnter);

void saidaList(TList *listPrint);

/*



*/