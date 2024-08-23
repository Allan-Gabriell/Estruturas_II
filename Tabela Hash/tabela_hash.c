#include <stdlib.h>
#include <stdio.h>
#define TAM 31

//Para saber o tamanho da nossa tabela multiplicamos por dois e buscamos o primo mais próximo
//2 * 15 = 30, tamanho igual a 31

void inicializarTabela(int t[]){
    for(int i = 0; i < TAM; i++){
        t[i] = 0;
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != 0){ //verificando se a posição na tabela está vazia
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    while(t[id] != 0){
        if(t[id] == chave){
            return t[id];
        } else {
            id = funcaoHash(id + 1);
        }
    }
    return 0;
}

void imprimir(int t[]){
    for(int i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(void){
    int tabela[TAM], opcao, valor, retorno;
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