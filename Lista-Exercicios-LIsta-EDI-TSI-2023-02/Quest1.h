/*
1) Dadas as declarações abaixo

Os campos inicio e fim do tipo TLista apontam, respectivamente, para o primeiro e último
nodo da lista. O campo next do último nodo da lista aponta para NULL.
resolva as questões abaixo:
a) Implemente uma função para inverter a ordem dos elementos de uma lista linear realizando
apenas a movimentação dos apontadores.
b) Implemente uma função para verificar se uma lista está ordenada.
c) Implemente uma função para inserir um elemento em uma lista em uma dada posição.
d) Implemente uma função para excluir um elemento de uma lista em uma dada posição.
e) Implemente uma função para verificar a existência de um elemento com uma
determinada chave em uma lista ordenada. Retornar um ponteiro para tal nodo ou
NULL.
f) Implemente a função lista* intercala(lista l1, lista l2) que retorne uma lista a partir das listas
ordenadas l1 e l2. A lista retornada deve ficar ordenada.
g) implemente uma função que remova todos os nodos que possuam o campo info igual a um
determinado valor.
h) Escreva uma função que, dada uma lista com um número qualquer de elementos,
encontre o menor elemento da lista e o mova para o começo da lista. Não é permitido
trocar apenas os campos ou usar uma lista auxiliar! Você deverá fazer a manipulação dos
apontadores para trocar os nodos de posição)
*/

typedef int TElemento;

typedef struct Nodo{
TElemento info;
struct Nodo *next;
}TNodo;

typedef struct{
TNodo *inicio, *fim;
int tamanho;
}TLista;

typedef TLista *lista;

void funcInvert(lista);