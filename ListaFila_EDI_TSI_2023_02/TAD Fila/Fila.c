#include "Fila.h"


TLista* criaLista() {
	TLista* fila = (TLista*)malloc(sizeof(TLista));
	if (fila != NULL)
	{
		fila->inicio = NULL;
		fila->fim = NULL;
		fila->tamanho = 0;
	}
	return 1;

}
