/*
Implemente um TAD em C TConjunto de interios. O TAD deve armazenar os elementos em um 
arranjo alocado dinamicamente chamado "elementos", o "tamanho" e o numero "n" de
elementos do conjunto.
Oprações para:
    - Criar Conjunto;
    - inserir um elemento no conjunto;
    - verificar se um elemento pertence ao conjunto
    - fazer a intersecçao de dois conjuntos;
Nota.: um conjunto não possui valores repetidos
*/


typedef struct conjuntos
{
    int* elementos;
    int tamanho;
    int capacidade;
}TConjunto;

//Função para alocar dinamicamente uma lista (vetor) entra o tamanho do vetor

//inserir elementos no conjunto


void destroyerConjunto();
