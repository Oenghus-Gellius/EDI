#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int TKey;

typedef struct Info{
    TKey key;
    int num;
    //demais componentes
}TInfo;

//-------------------------Alocar Elemento
TInfo* createrInfo();

void destroyerInfo(TInfo* info);

TKey getKey(TInfo* info);

void setKey(TInfo* info, TKey key);

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
TInfo *dequeueLine(TLine* line);

int emptyLine(TLine *line);
int fullLine(TLine *line);
int sizeLine(TLine *line);

void destroyerLine(TLine* line);

#endif //LINE_H_INCLUDED