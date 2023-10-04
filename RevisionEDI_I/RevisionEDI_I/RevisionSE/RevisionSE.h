
/* REVISION*/

typedef struct NodoList {
    unsigned int codList;
    struct NodoList* nextList;
    struct NodoList* backList;
}TNodoList;

typedef struct List {
    int tamanho;
    int corrent;
    TNodoList* inicio, * fim, * cursor;
}TList;

TList* bornList();

int firstInList(TList* firstList, int codListEnter);

int putEndList(TList* endlist, int codEnter);

int sizeList(TList* list);

void setList(TList* listBase, int* numb, int quantidade);

int finderElement(TList* listaBase, int numb);

int setCursor(TList* list, int index);

int getCorrent(TList* list, int elemet);

TList* removeList(TList* listBase, int numFinder);

TList* putInPositionList(TList* listBase, int indice, int numPut);

int listFull(TList* list);

int emptList(TList* list);

void saidaList(TList* listPrint);

void destroyerlist(TList* list);