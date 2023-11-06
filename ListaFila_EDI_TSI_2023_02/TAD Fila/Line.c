#include "Line.h"

#include <stdio.h>

//-------------------------Alocar INFO

TInfo* createrInfo()
{
	TInfo* info = (TInfo*)malloc(sizeof(TInfo));
	if (info == NULL)
	{
		return NULL;
	}
	return info;
}

void destroyerInfo(TInfo* info)
{
	free(info);
}

TKey getKey(TInfo* info)
{
	return info->key;
}

void setKey(TInfo* info, TKey key)
{
	info->key = key;
}

//-----------------------------LINE

TLine* createrLine(){
	TLine* line = (TLine*)malloc(sizeof(TLine));
	if (line == NULL)
	{
		return NULL;
	}
	line->start = NULL;
	line->end = NULL;
	line->size = 0;

	return line;
}

int queueLine(TLine* line, TInfo info){
	if (fullLine(line) == 1)
	{
		return 0;
	}
	TNodeLine* ptrNodeLine = (TNodeLine*)malloc(sizeof(TNodeLine));
	if (ptrNodeLine == NULL)
	{
		return 0;
	}
	ptrNodeLine->info = info;
	ptrNodeLine->next = NULL;
	if (line->size == 0)//O Primeiro da fila
	{
		line->start = ptrNodeLine;
	}
	else
	{
		line->end->next = ptrNodeLine;
	}
	line->end = ptrNodeLine;
	line->size++;
	return 1;
}

TInfo *dequeueLine(TLine* line)
{
	TNodeLine* ptrNodeLine;
	TInfo* info = createrInfo();

	if (emptyLine(line) == 1)
	{
		return;
	}
	ptrNodeLine = line->start;
	line->start = line->start->next;
	*info = ptrNodeLine->info;
	line->size--;
	free(ptrNodeLine);

	return info;
}

int emptyLine(TLine* line)
{
	if (line->size == 0)
	{
		return 1;
	}
	return 0;
}

int fullLine(TLine* line)
{
	TNodeLine* ptrNodeLine = (TLine*)malloc(sizeof(TLine));
	if (line == NULL)
	{
		return 1;
	}
	free(ptrNodeLine);
	return 0;
}

int sizeLine(TLine* line)
{
	return line->size;
}

void destroyerLine(TLine* line){
	TNodeLine* ptrNodeLine;
	while (line->start != NULL)
	{
		ptrNodeLine = line->start;
		line->start = line->start->next;
		free(ptrNodeLine);
	}
	free(line);
}


