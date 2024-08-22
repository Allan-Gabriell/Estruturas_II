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

int buscar(No* raiz, int chave){
    if(raiz == NULL){
        return -1;
    } else if(raiz->dado == chave) {
        return raiz->dado;
    } else if(chave < raiz->dado){
        return buscar(raiz->esquerda, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

void imprimir(No *raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->dado);
        imprimir(raiz->direita);
    }
}

No* remover(No* raiz, int chave){
    if(raiz == NULL){
        printf("Valor não encontrado... \n");
        return NULL;
    } else if(raiz->dado == chave){
        if(raiz->esquerda == NULL && raiz->direita == NULL){
            free(raiz);
            return NULL;
        } else{
            if(raiz->esquerda != NULL || raiz->direita != NULL){
                No *aux;
                if(raiz->esquerda != NULL){
                    aux = raiz->esquerda;
                } else {
                    aux = raiz->direita;
                }
                free(raiz);
                return aux;
            }
        }
    } else if(chave < raiz->dado){
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else{
        raiz->direita = remover(raiz->direita, chave);
    }
    return raiz; // Retorna o nó atualizado
}

int main(void) {
    int opcao, valor;
    ArvB arv;
    arv.raiz = NULL;

    do {
        printf("\n0 - Sair \n1 - Inserir \n2 - Imprimir\n3 - Buscas\n4 - Remover\n");
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
            case 3:
                printf("Qual valor deseja buscar? ");
                scanf("%d", &valor);
                printf("Resultado da busca: %d\n", buscar(arv.raiz, valor));
            break;
            case 4:
                printf("Informe o valor que deseja remover: ");
                scanf("%d", &valor);
                arv.raiz = remover(arv.raiz, valor);
            break;
            default:
                printf("\nOpção Inválida...\n");
        }
    } while (opcao != 0);

    return 0;
}