#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERS 1000
#define MAX_LINHA 50

// Definição da estrutura Linha
typedef struct Linha {
    char* texto; // Alterado de "vetLinhas" para "texto"
    int tamanho;
} TLinha;

// Definição da estrutura Nodo
typedef struct Nodo {
    TLinha* linhas[MAX_LINHA];
    struct Nodo* proximaPagina; // Alterado de "nextPag" para "proximaPagina"
} TNodo;

// Definição da estrutura Pagina
typedef struct Pagina {
    int numLinhas;
    int numPaginas;
    TNodo* inicio, *fim, *cursor;
} TPage;

// Protótipos das funções
TPage* criarPagina();
TPage* novaPagina(TPage* pagina);
TLinha* criarLinhas();
int definirCursor(TPage* pagina, int indice);
void editorDeTexto();
void exibirPaginas(TPage* paginaAtual);

int main() {
    TPage* paginaAtual;

    paginaAtual = criarPagina();

    editorDeTexto();

    exibirPaginas(paginaAtual);

    return 0;
}

TPage* criarPagina() {
    TPage* primeiraPagina = (TPage*)malloc(sizeof(TPage));
    if (primeiraPagina != NULL) {
        primeiraPagina->numLinhas = 0;
        primeiraPagina->numPaginas = 1;
        primeiraPagina->inicio = NULL;
        primeiraPagina->fim = NULL;
        primeiraPagina->cursor = NULL;
    } else {
        printf("\nFalha na alocação da página\n");
        return NULL;
    }
    printf("\nPágina %d\n", primeiraPagina->numPaginas);
    return primeiraPagina;
}

TPage* novaPagina(TPage* pagina) {
    TNodo* novaPaginaNodo = (TNodo*)malloc(sizeof(TNodo));
    if (novaPaginaNodo == NULL) {
        return NULL;
    } else {
        novaPaginaNodo->proximaPagina = NULL;
        pagina->fim = novaPaginaNodo;
        pagina->numPaginas++;

        if (pagina->inicio == NULL) {
            pagina->inicio = novaPaginaNodo;
        }
        return pagina;
    }
}

TLinha* criarLinhas() {
    TLinha* linhas = (TLinha*)malloc(MAX_LINHA * sizeof(TLinha));
    if (linhas == NULL) {
        printf("\nErro ao criar linhas!!!\n");
        return NULL;
    } else {
        return linhas;
    }
}

int definirCursor(TPage* pagina, int indice) {
    int i;
    if (indice < 1 || indice > pagina->numPaginas) {
        return 0;
    }
    if (pagina->numPaginas == 1) {
        pagina->cursor = pagina->inicio;
    } else {
        pagina->cursor = pagina->inicio;

        for (i = 1; i < indice; i++) {
            if (pagina->cursor == NULL) {
                return 0;
            }
            pagina->cursor = pagina->cursor->proximaPagina;
        }
    }
    return 1;
}

void editorDeTexto() {
    unsigned char texto[MAX_CARACTERS];
    int oFim = 0;

    TPage* ptrPagina;
    TLinha* ptrLinhas;

    ptrPagina = criarPagina();
    if (ptrPagina == NULL) {
        printf("\nErro ao criar página no editor de texto\n");
        return;
    } else {
        ptrLinhas = criarLinhas();
        if (ptrLinhas == NULL) {
            printf("\nErro ao criar linhas no editor de texto\n");
            return;
        } else {
            printf("\nDigite uma linha de texto (ou 'FIM' para encerrar): \n");

            while (oFim != 1) {
                for (int i = 0; i < MAX_LINHA; i++) {
                    fgets(texto, sizeof(texto), stdin);
                    setbuf(stdin, NULL);

                    if (strcmp(texto, "FIM\n") == 0) {
                        oFim = 1;
                        break;
                    }
                    ptrPagina->numLinhas++;
                }
                if (oFim == 0) {
                    ptrPagina = novaPagina(ptrPagina);
                    ptrLinhas = criarLinhas();
                }
            }
        }
    }
}

void exibirPaginas(TPage* paginaAtual) {
    int numPagina = 1;
    int numLinhas = 0;

    TNodo* paginaCorrente;
    TLinha* ptrLinhaCorrente[MAX_LINHA];

    paginaCorrente = paginaAtual->inicio;

    while (paginaCorrente != NULL) {
        printf("\nPágina %d.\n", numPagina);

        // Criar um novo array de linhas para a página corrente
        for (int i = 0; i < MAX_LINHA; i++) {
            ptrLinhaCorrente[i] = criarLinhas();
        }

        if (ptrLinhaCorrente != NULL) {
            numLinhas = ptrLinhaCorrente[0]->tamanho;

            for (int i = 0; i < numLinhas; i++) {
                if (ptrLinhaCorrente[i]->texto != NULL) {
                    printf("%s\n", ptrLinhaCorrente[i]->texto);
                }
            }
        }

        // Liberar memória do array de linhas corrente
        for (int i = 0; i < MAX_LINHA; i++) {
            free(ptrLinhaCorrente[i]);
        }

        paginaCorrente = paginaCorrente->proximaPagina;
        numPagina++;
    }
}
