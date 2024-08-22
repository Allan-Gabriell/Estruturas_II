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
void imprimirArvore(struct Node* raiz);

int main(void) {
    struct Info dado;
    FILE *dados = fopen("dados_da_arvore.txt", "r");
    if (dados == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    struct Node* raiz = NULL;
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    
    while (fgets(dado.nome, sizeof(dado.nome), dados) != NULL) {
        // Remover o newline do final do nome, se existir
        dado.nome[strcspn(dado.nome, "\n")] = '\0';
        fscanf(dados, "%d", &dado.mat);
        fscanf(dados, "%d", &dado.turma);
        dado.nota = rand() % 10;
        fgetc(dados); // Consome a nova linha restante após ler a turma

        raiz = inserir(raiz, dado);
    }

    fclose(dados);

    // Imprime a árvore
    imprimirArvore(raiz);

    // srand(time(NULL));  // Inicializa o gerador de números aleatórios
    
    // struct Info allan;
    // strcpy(allan.nome, "Allan");
    // allan.mat = 3;
    // allan.turma = 1;
    // allan.nota = rand() % 10;

    // struct Node* raiz = NULL;
    // raiz = inserir(raiz, allan);

    // struct Info leticia;
    // strcpy(leticia.nome, "Leticia");
    // leticia.mat = 4;
    // leticia.turma = 1;
    // leticia.nota = rand() % 10;

    // raiz = inserir(raiz, leticia);

    // struct Info naama;
    // strcpy(naama.nome, "Naama");
    // naama.mat = 5;
    // naama.turma = 2;
    // naama.nota = rand()%10;

    // raiz = inserir(raiz, naama);

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
    if (comparar(info, raiz->info) < 0) {
        raiz->esq = inserir(raiz->esq, info);
    } else if (comparar(info, raiz->info) > 0) {
        raiz->dir = inserir(raiz->dir, info);
    }
    return raiz;
}

void imprimirArvore(struct Node* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esq);
        printf("Nome: %s, Matricula: %d, Turma: %d, Nota: %.2f\n", raiz->info.nome, raiz->info.mat, raiz->info.turma, raiz->info.nota);
        imprimirArvore(raiz->dir);
    }
}


