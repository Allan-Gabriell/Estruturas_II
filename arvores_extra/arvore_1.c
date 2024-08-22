#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado; // informação de cada nó
    struct no* esquerda; // ponteiros para navegação da árvore
    struct no* direita;
} No;

typedef struct arvB {
    No* raiz; // primeiro nó da árvore
} ArvB;

void inserirEsquerda(No* no, int valor);
void inserirDireita(No* no, int valor);

void inserir(ArvB* arv, int valor) {
    if (arv->raiz == NULL) { // primeiro elemento da árvore
        No *novoNo = (No*) malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL; 
        arv->raiz = novoNo;
    } else {
        if (valor < arv->raiz->dado) {
            inserirEsquerda(arv->raiz, valor);
        } else {
            inserirDireita(arv->raiz, valor);
        }
    }
}

void inserirEsquerda(No* no, int valor) {
    if (no->esquerda == NULL) {
        No *novoNo = (No*) malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL; 
        no->esquerda = novoNo;
    } else {
        if (valor < no->esquerda->dado) {
            inserirEsquerda(no->esquerda, valor);
        } else {
            inserirDireita(no->esquerda, valor);
        }
    }
}

void inserirDireita(No* no, int valor) {
    if (no->direita == NULL) {
        No *novoNo = (No*) malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL; 
    } else {
        if (valor < no->direita->dado) {
            inserirEsquerda(no->direita, valor);
        } else {
            inserirDireita(no->direita, valor);
        }
    }
}

void imprimir(No *raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->dado);
        imprimir(raiz->direita);
    }
}

int main(void) {
    int opcao, valor;
    ArvB arv;
    arv.raiz = NULL;

    do {
        printf("\n0 - Sair \n1 - Inserir \n2 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Informe um valor: ");
                scanf("%d", &valor);
                inserir(&arv, valor);
                break;
            case 2:
                printf("Impressão da árvore binária: \n");
                imprimir(arv.raiz);
                break;
            default:
                printf("\nOpção Inválida...\n");
        }
    } while (opcao != 0);

    return 0;
}