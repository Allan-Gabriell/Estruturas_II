#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Info {
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node {
    struct Info info;
    struct Node* esq;
    struct Node* dir;
};

struct Node* criarNode(struct Info info);
int comparar(struct Info a, struct Info b);
struct Node* inserir(struct Node* raiz, struct Info info);

int main(void) {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    
    struct Info allan;
    strcpy(allan.nome, "Allan");
    allan.mat = 3;
    allan.turma = 1;
    allan.nota = rand() % 10;

    struct Node* raiz = NULL;
    raiz = inserir(raiz, allan);

    struct Info leticia;
    strcpy(leticia.nome, "Leticia");
    leticia.mat = 4;
    leticia.turma = 1;
    leticia.nota = rand() % 10;

    raiz = inserir(raiz, leticia);

    struct Info naama;
    strcpy(naama.nome, "Naama");
    naama.mat = 5;
    naama.turma = 2;
    naama.nota = rand()%10;

    raiz = inserir(raiz, naama);

    return 0;
}

struct Node* criarNode(struct Info info) {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }
    strcpy(novo->info.nome, info.nome);
    novo->info.mat = info.mat;
    novo->info.turma = info.turma;
    novo->info.nota = info.nota;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int comparar(struct Info a, struct Info b) {
    return strcmp(a.nome, b.nome);
}

struct Node* inserir(struct Node* raiz, struct Info info) {
    if (raiz == NULL) {
        return criarNode(info);
    }
    if (comparar(raiz->info, info) > 0) {
        raiz->esq = inserir(raiz->esq, info);
    } else if (comparar(raiz->info, info) < 0) {
        raiz->dir = inserir(raiz->dir, info);
    }
    return raiz;
}
