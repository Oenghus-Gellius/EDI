/*1) Invente um vetor-exemplo de entrada para demostrar que ordenação por seleção é um
método instável.*/

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

int insertVetList(TVetList *vetList, TInfo info);

int insertPositionVetList(TVetList *vetList, int position, TInfo info);

int removeInfoVetList(TVetList *vetList, TKey key, TInfo *info);

int finderInfoVetList(TVetList *vetList, TKey key, TInfo *info);

int emptyVetList(TVetList* vetList);

int fullVetList(TVetList* vetList);

int sizeVetList(TVetList* vetList);

void DestroyerVet(TVetList *vetList);

void printVetList(TVetList *vetList);
//=================================
