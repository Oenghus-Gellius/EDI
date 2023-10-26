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


/*Como saídas do trabalho, além dos arquivos com as páginas da WikiEDI, será pedido um arquivo de “log”
caminho para possíveis mensagens de erro e para informar se há caminho entre duas páginas (por meio de
links). No caso de mensagens de erro, por exemplo, se um editor tentar excluir uma contribuição que não
tenha sido inserida por ele/ela, uma mensagem de erro deve ser gerada (e.g.: erro: editor não tem direito de
excluir esta contribuição). Verificações similares devem ser feitas caso seja pedido para excluir uma página
inexistente, ou um editor inexistente, etc. No caso de saber se há caminho entre duas páginas, basta navegar
nas listas de links para determinar se há caminho, ou não entre as páginas. No exemplo da figura 1, há
caminhos das páginas da SO para as páginas de EDI e BD, mas não há caminho inverso.*/

//Essa função tem o objetivo de abrir o log ao inicio do programa e resgistrar "todas as 
//manipulações do programa, fecha ao se fechar o programa salvado as alterações.
int logEdit(FILE* arqLog, char* logMensagem);



#endif 