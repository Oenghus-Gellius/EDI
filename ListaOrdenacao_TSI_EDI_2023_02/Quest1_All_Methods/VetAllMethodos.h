/* THEORY

========================== Complexidade O(n²): =============================

Bubble Sort
Insertion Sort
Selection Sort

- Complexidade O(n log n):

Merge Sort
Heap Sort
- Complexidade O(n log n) em média, O(n²) no pior caso:

Quick Sort

======================== Estabilidade =========================

- Estáveis:

Bubble Sort (pode ser implementado para ser estável)
Insertion Sort (é estável por natureza)
Merge Sort (é estável por natureza)
Tim Sort (é uma variação do Merge Sort e, portanto, é estável)
Counting Sort (é estável)
Radix Sort (é estável)

- Instáveis:

Selection Sort (geralmente instável)
Quick Sort (pode ser estável ou instável, dependendo da implementação)


1) Invente um vetor-exemplo de entrada para demostrar que ordenação por seleção é um
método instável.*/

#define MAX_VET 10

typedef int TKey;

typedef struct Info {
	TKey key;
	char caracter;
}TInfo;

typedef struct NodeList {
	TInfo info;
	struct NodeList* next;
}TNodeList;

typedef struct List {
	int size;
	TNodeList* start, * end;
}TList;

typedef struct VetList {
	int size;
	TInfo VetInfo[MAX_VET];
}TVetList;

//============================

TList* createrList();

int insertList(TList* list, TInfo info);

int removeList(TList* list, TKey key, TInfo* info);

int finderList(TList* list, TKey key, TInfo* info);

int emptyList(TList* list);

int fullList(TList* list);

int sizeList(TList* list);

void destroyerList(TList* list);

//================================= VET

TVetList* createrVetList();

int insertVetList(TVetList *vetList, TInfo info);

int insertPositionVetList(TVetList *vetList, int position, TInfo info);

int removeInfoVetList(TVetList *vetList, TKey key, TInfo *info);

int finderInfoVetList(TVetList *vetList, TKey key, TInfo *info);

int emptyVetList(TVetList* vetList);

int fullVetList(TVetList* vetList);

int sizeVetList(TVetList* vetList);

void DestroyerVet(TVetList *vetList);

void printVetList(TVetList *vetList);

//================================= ORDERING - crescent

//=============================selectoinSort<---- Usa a função swap

/*O selectoinSort trava em um elemento e compara ele com todos os elementos posterior a ele
até achar seu menor, achando ele*/

//Função com o objetivo de fazer a trocas dos elementos de um vetor,recebendo as chaves e trocando-as
void swap(int* keyX, int* keyY);

void selectionSortBase(TVetList* vetList, int size);

void selectionSort(TVetList* vetList, int size);

//=============================bubbleSort <---- Usa a função swap

void bubbleSortBase(TVetList* vetList, int size);

void bubbleSort(TVetList * vetList, int size);

void bubbleSortStop(TVetList * vetList, int size);

//============================InsertSort

void insertSort(TVetList* vetList, int size);

//==============================Shellsort

/*O Shellsort, também conhecido como método de ordenação por incrementos decrescentes, 
é um algoritmo de ordenação que aprimora o método de inserção, realizando comparações e trocas 
em intervalos específicos chamados de "lacunas" ou "incrementos". O algoritmo utiliza uma 
sequência de lacunas que, tipicamente, são escolhidas como uma série de potências de dois.

A ideia principal do Shellsort é ordenar subconjuntos da lista original, começando com intervalos 
grandes e diminuindo gradualmente esses intervalos até que a lista esteja praticamente ordenada. 
Então, o algoritmo realiza uma etapa final de ordenação por inserção para garantir que a lista 
esteja completamente ordenada.*/
void shellSort(TVetList* vetList, int size);

//==============================QuickSort / Partition <-------Usando a função swap

void partition(TVetList* vetList, int esq, int dir);

void quickSort(TVetList* vetList, int size);

void partitionInsert(TVetList* vetList, int esq, int dir);

void quickSortInsert(TVetList* vetList, int size);

//==============================MergeSort / Partition

void mergeSort(TInfo* vetList, int size);

void mergeSort_Order(TInfo* vetList, int esq, int dir);

void mergeSort_Interleave(TInfo* vetList, int esq, int midlle, int dir);

//==============================heapSort
void buildHeap(TVetList* vetList, int position, int end);

void heapSort(TVetList* vetList, int size);






