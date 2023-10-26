#ifndef WIKIEDI_LOG_H_INCLUDED
#define WIKIEDI_LOG_H_INCLUDED

#include "testador.h"
#include "Links.h"
#include "WikiEDI_BETA.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Log {
	char* logMensagem;
	char* nomePage;
}TLog;


/*Como sa�das do trabalho, al�m dos arquivos com as p�ginas da WikiEDI, ser� pedido um arquivo de �log�
caminho para poss�veis mensagens de erro e para informar se h� caminho entre duas p�ginas (por meio de
links). No caso de mensagens de erro, por exemplo, se um editor tentar excluir uma contribui��o que n�o
tenha sido inserida por ele/ela, uma mensagem de erro deve ser gerada (e.g.: erro: editor n�o tem direito de
excluir esta contribui��o). Verifica��es similares devem ser feitas caso seja pedido para excluir uma p�gina
inexistente, ou um editor inexistente, etc. No caso de saber se h� caminho entre duas p�ginas, basta navegar
nas listas de links para determinar se h� caminho, ou n�o entre as p�ginas. No exemplo da figura 1, h�
caminhos das p�ginas da SO para as p�ginas de EDI e BD, mas n�o h� caminho inverso.*/

//Essa fun��o tem o objetivo de abrir o log ao inicio do programa e resgistrar "todas as 
//manipula��es do programa, fecha ao se fechar o programa salvado as altera��es.
int logEdit(FILE* arqLog, char* logMensagem);



#endif 