#ifndef TESTADOR_H_INCLUDED
#define TESTADOR_H_INCLUDED

/*Execução do programa
O programa testador deverá ser capaz de ler as instruções do arquivo texto de entrada e realizar as devidas
operações na WikiEDI. O seu programa testador deverá ler os dados de entrada a partir de um arquivo, cujo
nome é passado como parâmetro na linha de comando.. Exemplo de execução do programa a partir da linha
de comando: ./wikiedi entrada.txt

O arquivo de entrada é basicamente uma lista de comandos (um por linha) em formato texto. O último
comando é a palavra FIM, que indica o final do arquivo. O formato a ser usado é exemplificado abaixo
(considere que todos os arquivos textos, tanto de entrada, quanto de saída, estão no mesmo diretório do
executável):*/

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