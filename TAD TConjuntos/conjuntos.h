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
    int *elementos;
    int tamanho;//capacidade
    int nElementos;
}TConjunto;

TConjunto *creatorConjunto(int tamanho);

void setConjunto(TConjunto *conjunto, int *elementos, int tamanho);

void buscaElemento(TConjunto *conjunto, int buscando);

TConjunto *conjutoIntersection(TConjunto *conjuntoA, TConjunto *conjuntoB);

void SaidaDados(TConjunto *conjunto);

