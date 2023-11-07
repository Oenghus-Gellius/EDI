#include "Fila_Banco.h"



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


TLine* createrLine() {
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

int queueLine(TLine* line, TInfo info) {
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

int dequeueLine(TLine* line, TInfo* info)
{
	TNodeLine* ptrNodeLine;

	if (emptyLine(line) == 1)
	{
		return 0;
	}
	ptrNodeLine = line->start;
	line->start = line->start->next;
	*info = ptrNodeLine->info;
	line->size--;
	free(ptrNodeLine);

	return 1;
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
	TNodeLine* ptrNodeLine = (TNodeLine*)malloc(sizeof(TNodeLine));
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

void destroyerLine(TLine* line) {
	TNodeLine* ptrNodeLine;
	while (line->start != NULL)
	{
		ptrNodeLine = line->start;
		line->start = line->start->next;
		free(ptrNodeLine);
	}
	free(line);
}


void printLine(TLine* line)
{
	TNodeLine* ptrNodeLine = line->start;
	while (ptrNodeLine != NULL)
	{
		printf("%s\t", ptrNodeLine->info.name);
		ptrNodeLine = ptrNodeLine->next;
	}
	printf("\n");
}

int main() {
	TLine* line1 = createrLine();
	TLine* line2 = createrLine();
	TLine* line3 = createrLine();
	TLine* line4 = createrLine();
	TLine* line5 = createrLine();

	int numLines = 5;

	char customer[NUM_CUSTOMERS][MAX_MANE] = { "Maria", "Joao", "Ana", "Pedro", "Laura", "Felipe", "END"};
	int index = 0;
	int dice = 0;

	srand(time(NULL));

	TInfo info;

	for (int i = 0; i < NUM_CUSTOMERS; i++)//Entrada fila
	{
		dice = (rand() % numLines) + 1;
		switch (dice)
		{
		case 1:
			strcpy(info.name, customer[index]);
			queueLine(line1, info);
				break;
		case 2:
			strcpy(info.name, customer[index]);
			queueLine(line2, info);
			break;
		case 3:
			strcpy(info.name, customer[index]);
			queueLine(line3, info);
			break;
		case 4:
			strcpy(info.name, customer[index]);
			queueLine(line4, info);
			break;
		case 5:
			strcpy(info.name, customer[index]);
			queueLine(line5, info);
			break;
		default:
			break;
		}
		index++;

	}

	printf("\nFila 1.:");
	printLine(line1);
	printf("\nFila 2.:");
	printLine(line2);
	printf("\nFila 3.:");
	printLine(line3);
	printf("\nFila 4.:");
	printLine(line4);
	printf("\nFila 5.:");
	printLine(line5);


	//atendimento caixa
	int bankTeller = 0;

	TLine* helpLine = createrLine();

	printf("\nOrdem de atendimento caixa\n");
	while (index != 0)
	{
		TInfo info;
		int peopleInLine = 0;
		bankTeller = (rand() % numLines) + 1;
		switch (bankTeller)
		{
		case 1:
			if (emptyLine(line1))
			{
				break;
			}
			else
			{
				dequeueLine(line1,&info);
				peopleInLine = 1;
				index--;
			}
			break;
		case 2:
			if (emptyLine(line2))
			{
				break;
			}
			else
			{
				dequeueLine(line2, &info);
				peopleInLine = 1;
				index--;
			}
			break;
		case 3:
			if (emptyLine(line3))
			{
				break;
			}
			else
			{
				dequeueLine(line3, &info);
				peopleInLine = 1;
				index--;
			}
			break;
		case 4:
			if (emptyLine(line4))
			{
				break;
			}
			else
			{
				dequeueLine(line4, &info);
				peopleInLine = 1;
				index--;
			}
			break;
		case 5:
			if (emptyLine(line5))
			{
				break;
			}
			else
			{
				dequeueLine(line5, &info);
				peopleInLine = 1;
				index--;
			}
			break;
		default:
			break;
		}

		if (peopleInLine == 1)
		{
			printf("%s foi atendida pelo caixa.\n", info.name);
			queueLine(helpLine, info);
		}
	}

	printLine(helpLine);

	destroyerLine(helpLine);
	destroyerLine(line1);
	destroyerLine(line2);
	destroyerLine(line3);
	destroyerLine(line4);
	destroyerLine(line5);

	return 0;
}