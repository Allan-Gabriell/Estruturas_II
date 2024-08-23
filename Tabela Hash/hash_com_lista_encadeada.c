#include <stdlib.h>
#include <stdio.h>
#define TAM 31

//Para saber o tamanho da nossa tabela multiplicamos por dois e buscamos o primo mais próximo
//2 * 15 = 30, tamanho igual a 31

typedef struct no{
    int chave;
    struct no *proximo;
}No;

typedef struct {
    No * inicio;
    int tam;
}Lista;

void inicializarLista(Lista *lis){
    lis->inicio = NULL;
    lis->tam = 0;
}

void inserirNaLista(Lista *list, int valor){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->chave = valor;
        novo->proximo = list->inicio;
        list->inicio = novo;
        list->tam++;
    } else{
        printf("Erro ao alocar memória\n");
        free(novo);
    }
}

int buscarNaLista(Lista *list, int valor){
    No *aux = list->inicio;
    while(aux && aux->chave != valor){
        aux = aux->proximo;
    }
    if(aux){
        return aux->chave;
    }
    return -1;
}

void imprimirLista(Lista *list){
    No *aux = list->inicio;
    printf("Tam: %d ", list->tam);
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[]){
    for(int i = 0; i < TAM; i++){
        inicializarLista(&t[i]);//passo o endereço de cada posição da minha lista
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserirNaLista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    return buscarNaLista(&t[id], chave);
}

void imprimir(Lista t[]){
    for(int i = 0; i < TAM; i++){
        printf("%d = ", i);
        imprimirLista(&t[i]);
        printf("\n");
    }
}

int main(void){
    int opcao, valor, retorno;
    Lista tabela[TAM];
    inicializarTabela(tabela);
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("\tSaindo...\n");
            break;
            case 1:
                printf("\tQual valor deseja inserir: ");
                scanf("%d", &valor);
                inserir(tabela, valor);
            break;
            case 2:
                printf("\tQual valor deseja buscar: ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                if(retorno != 0){
                    printf("\tValor encontrado: %d\n", retorno);
                } else {
                    printf("\tValor não encontrado...\n");
                }
            break;
            case 3:
                imprimir(tabela);
            break;
            default:
                printf("atOpção Inválida...\n");
        }
    } while(opcao != 0);

    return 0;
}