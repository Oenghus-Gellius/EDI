#include "RevisionDEC.h"

void testeDEC() {
    TList *listA = bornList();

    int elementos[] = {4, 54, 75};
    int qtd = 3;

    int putNumbFirst = 511;
    int putEnd = 13;

    setList(listA, elementos, qtd); //ESSA FUNçÂO ESTÁ BUGANDO O VS kkkkkkkk

    firstInList(listA, putNumbFirst);

    putEndList(listA, putEnd);
    saidaList(listA);

    
}

int main() {

    testeDEC();

    return 0;
}