/* THEORY

========================== Complexidade O(n�): =============================

Bubble Sort
Insertion Sort
Selection Sort

- Complexidade O(n log n):

Merge Sort
Heap Sort
- Complexidade O(n log n) em m�dia, O(n�) no pior caso:

Quick Sort

======================== Estabilidade =========================

- Est�veis:

Bubble Sort (pode ser implementado para ser est�vel)
Insertion Sort (� est�vel por natureza)
Merge Sort (� est�vel por natureza)
Tim Sort (� uma varia��o do Merge Sort e, portanto, � est�vel)
Counting Sort (� est�vel)
Radix Sort (� est�vel)

- Inst�veis:

Selection Sort (geralmente inst�vel)
Quick Sort (pode ser est�vel ou inst�vel, dependendo da implementa��o)


1) Invente um vetor-exemplo de entrada para demostrar que ordena��o por sele��o � um
m�todo inst�vel.*/

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

//=============================selectoinSort<---- Usa a fun��o swap

/*O selectoinSort trava em um elemento e compara ele com todos os elementos posterior a ele
at� achar seu menor, achando ele*/

//Fun��o com o objetivo de fazer a trocas dos elementos de um vetor,recebendo as chaves e trocando-as
void swap(int* keyX, int* keyY);

void selectionSortBase(TVetList* vetList, int size);

void selectionSort(TVetList* vetList, int size);

//=============================bubbleSort <---- Usa a fun��o swap

void bubbleSortBase(TVetList* vetList, int size);

void bubbleSort(TVetList * vetList, int size);

void bubbleSortStop(TVetList * vetList, int size);

//============================InsertSort

void insertSort(TVetList* vetList, int size);

//==============================Shellsort

/*O Shellsort, tamb�m conhecido como m�todo de ordena��o por incrementos decrescentes, 
� um algoritmo de ordena��o que aprimora o m�todo de inser��o, realizando compara��es e trocas 
em intervalos espec�ficos chamados de "lacunas" ou "incrementos". O algoritmo utiliza uma 
sequ�ncia de lacunas que, tipicamente, s�o escolhidas como uma s�rie de pot�ncias de dois.

A ideia principal do Shellsort � ordenar subconjuntos da lista original, come�ando com intervalos 
grandes e diminuindo gradualmente esses intervalos at� que a lista esteja praticamente ordenada. 
Ent�o, o algoritmo realiza uma etapa final de ordena��o por inser��o para garantir que a lista 
esteja completamente ordenada.*/
void shellSort(TVetList* vetList, int size);

//==============================QuickSort / Partition <-------Usando a fun��o swap

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






