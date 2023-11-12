#define MAX_VET 10

typedef int TKey;

typedef struct Info {
	TKey key;
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

int insertVetList(TVetList* vetList, TInfo info);

int insertPositionVetList(TVetList* vetList, int position, TInfo info);

int removeInfoVetList(TVetList* vetList, TKey key, TInfo* info);

int finderInfoVetList(TVetList* vetList, TKey key, TInfo* info);

int emptyVetList(TVetList* vetList);

int fullVetList(TVetList* vetList);

int sizeVetList(TVetList* vetList);

void DestroyerVet(TVetList* vetList);

void printVetList(TVetList* vetList);

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

void bubbleSort(TVetList* vetList, int size);

void bubbleSortStop(TVetList* vetList, int size);

//============================InsertSort

void insertSort(TVetList* vetList, int size);

//==============================Shellsort

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