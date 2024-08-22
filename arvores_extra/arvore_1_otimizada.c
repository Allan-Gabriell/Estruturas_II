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

No* inserirNovaVersao(No* raiz, int valor){
    if(raiz == NULL){
        No *novoNo = (No*) malloc(sizeof(No));
        novoNo->dado = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL; 
        return novoNo; //retorno o endereço do nó
    } else if(valor < raiz->dado) { //raiz não é nula
        raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor); //tenho que retornar para não perder a raíz da árvore
    } else if(valor > raiz->dado){
        raiz->direita = inserirNovaVersao(raiz->direita, valor);
    }
    return raiz;
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
                arv.raiz = inserirNovaVersao(arv.raiz, valor);
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