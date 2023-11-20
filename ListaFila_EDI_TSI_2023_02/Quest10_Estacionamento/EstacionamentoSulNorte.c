#include "EstacionamentoSulNorte.h"

#define  _CRT_SECURE_NO_WARNINGS

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
	ptrNodeLine->next = NULL;//SE QUER CIRCULAR É SÓ APONTAR PARA A 
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
		printf("Key %d-", ptrNodeLine->info.key);
		printf("Status.: %c -", ptrNodeLine->info.status);
		printf("Plate.:%d |", ptrNodeLine->info.carPlate);
		printf("Movement: %d\n", ptrNodeLine->info.movement);
		ptrNodeLine = ptrNodeLine->next;
	}
	printf("\n");
}


//-------------------------------------------------------

int main() {
	return dayTest();
}

void ValetParking4You(TLine* garageLine, TInfo carInfo)
{
	TLine* garageLineTemp = createrLine();
	TInfo infoCar;

	char status = carInfo.status;
	if (status == 'E')//Entrada
	{
		queueLine(garageLine, carInfo);
	}
	else//saida
	{
		while (garageLine->start != NULL)
		{
			garageLine->start->info.movement++;
			//contador de movimenta��es
			if (garageLine->start->info.carPlate != carInfo.carPlate)
			{
				queueLine(garageLineTemp, garageLine->start->info);
				dequeueLine(garageLine, &infoCar);
			}
			else
			{
				dequeueLine(garageLine, &infoCar);
				printf("\nCar remove.:\n");
				printf("Key %d-", carInfo.key);
				printf("Status.: %c -", carInfo.status);
				printf("Plate.:%d |", carInfo.carPlate);
				printf("Movement: %d\n", carInfo.movement);
				printf("\n\n");
			}
		}
		while (garageLineTemp->start != NULL)
		{
			while (garageLineTemp->start != NULL)
			{
				queueLine(garageLine, garageLineTemp->start->info);
				dequeueLine(garageLineTemp, &infoCar);
			}
		}
	}
	free(garageLineTemp);
}


int dayTest() {
	TLine* garageLine = createrLine();
	TInfo carInfoGarage;

	TKey keyday = 1;
	int garageQtdNow = 0;

	//TCarPlate carEnterPlate[] = { "ABC-123", "XYZ-789", "QWE-456", "HJK-321", "LMN-654", "PQR-987", "STU-654", "VWX-321", "YZA-789", "HQK-341" };
	int carEnterPlate[] = { 987123, 987789, 987456, 987321, 987854, 
		987987, 987654, 987721, 987789, 987341 };

	printf("\nValet Parking 4 You!!!\n\n");

	for (int i = 0; i < 10; i++)
	{
		carInfoGarage.key = keyday;
		carInfoGarage.status = 'E';
		carInfoGarage.carPlate = carEnterPlate[i];
		carInfoGarage.movement = 0;
		queueLine(garageLine, carInfoGarage);
		keyday++;
	}

	//sai um carro

	carInfoGarage.carPlate = 987987;
	carInfoGarage.status = 'S';
	ValetParking4You(garageLine, carInfoGarage);


	//Entra um carro
	carInfoGarage.key = keyday;
	carInfoGarage.carPlate = 567245;
	carInfoGarage.movement = 0;
	carInfoGarage.status = 'E';
	ValetParking4You(garageLine, carInfoGarage);
	keyday++;

	printLine(garageLine);

	return EXIT_SUCCESS;
}