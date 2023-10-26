#ifndef TESTADOR_H_INCLUDED
#define TESTADOR_H_INCLUDED

/*Execu��o do programa
O programa testador dever� ser capaz de ler as instru��es do arquivo texto de entrada e realizar as devidas
opera��es na WikiEDI. O seu programa testador dever� ler os dados de entrada a partir de um arquivo, cujo
nome � passado como par�metro na linha de comando.. Exemplo de execu��o do programa a partir da linha
de comando: ./wikiedi entrada.txt

O arquivo de entrada � basicamente uma lista de comandos (um por linha) em formato texto. O �ltimo
comando � a palavra FIM, que indica o final do arquivo. O formato a ser usado � exemplificado abaixo
(considere que todos os arquivos textos, tanto de entrada, quanto de sa�da, est�o no mesmo diret�rio do
execut�vel):*/

/*

Exemplo de arquivo de entrada

INSEREPAGINA EDI edi.txt
INSEREPAGINA BD banco.txt
INSEREPAGINA SO so.txt
RETIRAPAGINA Psicologia
INSEREEDITOR PEDRAO
INSEREEDITOR MALUZINHA
INSEREEDITOR AMANDINHA
INSEREEDITOR LARINHA
INSEREEDITOR WENDER
RETIRAEDITOR WENDER
INSERECONTRIBUICAO EDI MALUZINHA c1.txt
INSERECONTRIBUICAO Fisica LARINHA c2.txt
INSERECONTRIBUICAO EDI MALUZINHA c3.txt
INSERELINK EDI BD
IMPRIMEPAGINA EDI
INSERECONTRIBUICAO BD LARINHA c4.txt
INSERECONTRIBUICAO BD AMANDINHA c5.txt
RETIRACONTRIBUICAO BD AMANDINHA c5.txt
INSERELINK BD EDI
INSERECONTRIBUICAO SO PEDRAO c6.txt
INSERECONTRIBUICAO SO PEDRAO c6.txt
INSERECONTRIBUICAO SO AMANDINHA c8.txt
INSERELINK SO EDI
INSERELINK SO BD
CAMINHO SO EDI
CAMINHO BD SO
IMPRIMEWIKED
FIM

*/

#include "WikiEDI_BETA.h"

//#include "Links.h"
#include "Log.h"

#include <stdio.h>

int executeTest();

void acrescentarAoArquivo();


#endif //TESTADOR_H_INCLUDED