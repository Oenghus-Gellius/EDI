#include "Revision.h"


void testSE() {

    TList* listBaseA;
    TNodoList nodeA;

    listBaseA = bornList();

    int tamanho = 10;


    int numb[] = { 9, 12, 7, 13, 21, 55, 14, 90, 1, 88 };

    int remove = 90;

    int putIndex = 5;
    int putNumb = 511;

    int finder = 13;

    int cursor = 7;

    int corrent = 1;

    setList(listBaseA, numb, tamanho);
    printf("\nLista base\t\t.:");
    saidaList(listBaseA);

    firstInList(listBaseA, putNumb);
    printf("\nPut inicio %d \t.:", putNumb);
    saidaList(listBaseA);

    putEndList(listBaseA, putNumb);
    printf("\nPut End %d \t.:", putNumb);
    saidaList(listBaseA);

    listBaseA = removeList(listBaseA, remove);
    printf("\nLista removendo o %d \t.:", remove);
    saidaList(listBaseA);

    listBaseA = putInPositionList(listBaseA, putIndex, putNumb);
    printf("\nPut %d na in %d\t\t.:", putNumb, putIndex);
    saidaList(listBaseA);

    printf("\n\n\n");

    if (finderElement(listBaseA, finder) == 1)
    {
        printf("\nO numero %d FOI ENCONTRADO!!!", finder);
    }
    else
    {
        printf("\nO numero %d NÃO FOI ENCONTRADO!!!\t.:", finder);
    }

    setCursor(listBaseA, cursor);

    corrent = getCorrent(listBaseA, corrent);

    printf("\nO numero CORRENTE é.:%d !!!", corrent);


    void destroyerlist(listBaseA);

    printf("\n\n\n");
    //saidaList(listBaseA);
}

int main() {
    testSE();

    return 0;
}