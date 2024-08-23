#include <stdlib.h>
#include <stdio.h>
#define TAM 31

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int num, cep;
} Endereco;

typedef struct {
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
} Contrato;

typedef struct {
    char nome[50];
    int cpf; // esse campo não vai se repetir para nenhuma pessoa e vai ser usado na hash
    Data dtaNasc;
    Endereco ender;
    Contrato contract;
} Pessoa;

typedef struct no {
    Pessoa pessoa;
    struct no *proximo;
} No;

Data lerdata() {
    Data data;
    printf("\nDigite a data no formato dd mm aaaa: ");
    scanf("%d%d%d", &data.dia, &data.mes, &data.ano);
    getchar();
    return data;
}

Endereco lerEndereco() {
    Endereco ender;
    printf("\nRua: ");
    fgets(ender.rua, 49, stdin);
    printf("\nBairro: ");
    fgets(ender.bairro, 49, stdin);
    printf("\nCidade: ");
    fgets(ender.cidade, 49, stdin);
    printf("\nPais: ");
    fgets(ender.pais, 49, stdin);
    printf("\nNumero: ");
    scanf("%d", &ender.num);
    printf("\nCEP: ");
    scanf("%d", &ender.cep);
    getchar();
    return ender;
}

Contrato lerContrato() {
    Contrato contrato;
    printf("\nCodigo do contrato: ");
    scanf("%d", &contrato.codigo);
    printf("\nData da Assinatura: ");
    contrato.dataAss = lerdata();
    getchar(); // Corrigido para capturar o \n
    printf("\nCargo: ");
    fgets(contrato.cargo, 49, stdin);
    printf("\nSalario: R$ ");
    scanf("%f", &contrato.salario);
    getchar();
    return contrato;
}

Pessoa lerPessoa() {
    Pessoa pessoa;
    printf("\nNome: ");
    fgets(pessoa.nome, 49, stdin);
    printf("\nCPF: ");
    scanf("%d", &pessoa.cpf);
    printf("\nData de Nascimento: ");
    pessoa.dtaNasc = lerdata();
    pessoa.contract = lerContrato();
    pessoa.ender = lerEndereco();
    return pessoa;
}

void imprimirData(Data data) {
    printf("%02d/%02d/%04d\n", data.dia, data.mes, data.ano);
}

void imprimirEndereco(Endereco endereco) {
    printf("\tEndereco:\n");
    printf("\tRua: %s", endereco.rua);
    printf("\tBairro: %s", endereco.bairro);
    printf("\tCidade: %s", endereco.cidade);
    printf("\tPais: %s", endereco.pais);
    printf("\tNumero: %d\n", endereco.num);
    printf("\tCEP: %d\n", endereco.cep);
}

void imprimirContrato(Contrato contrato) {
    printf("\tContrato %d:\n", contrato.codigo);
    printf("\t\tCargo: %s", contrato.cargo);
    printf("\t\tSalario: %.2f\n", contrato.salario);
    printf("\t\tData de Assinatura: ");
    imprimirData(contrato.dataAss);
}

void imprimirPessoa(Pessoa pessoa) {
    printf("\n\tNome: %s", pessoa.nome);
    printf("\tCPF: %d\n", pessoa.cpf);
    printf("\tData de Nascimento: ");
    imprimirData(pessoa.dtaNasc);
    imprimirEndereco(pessoa.ender);
    imprimirContrato(pessoa.contract);
}

void inicializarTabela(Pessoa t[]) {
    for (int i = 0; i < TAM; i++) {
        t[i].cpf = 0;
    }
}

int funcaoHash(int chave) {
    return chave % TAM;
}

void inserir(Pessoa t[]) {
    Pessoa pessoa = lerPessoa();
    int id = funcaoHash(pessoa.cpf);
    while (t[id].cpf != 0) { // Verificando se a posição na tabela está vazia
        id = funcaoHash(id + 1);
    }
    t[id] = pessoa;
}

Pessoa *busca(Pessoa t[], int chave) {
    int id = funcaoHash(chave);
    while (t[id].cpf != 0) {
        if (t[id].cpf == chave) {
            return &t[id];
        } else {
            id = funcaoHash(id + 1);
        }
    }
    return NULL;
}

void imprimir(Pessoa t[]) {
    for (int i = 0; i < TAM; i++) {
        printf("%d\n", i);
        if (t[i].cpf != 0) {
            imprimirPessoa(t[i]);
        }
        printf("\n------------------------------------\n");
    }
}

int main(void) {
    int opcao, valor;
    Pessoa *buscar, tabela[TAM];

    inicializarTabela(tabela);
    do {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 0:
                printf("\tSaindo...\n");
                break;
            case 1:
                inserir(tabela);
                break;
            case 2:
                printf("\tQual CPF deseja buscar: ");
                scanf("%d", &valor);
                buscar = busca(tabela, valor);
                if (buscar) {
                    printf("\tValor encontrado: %d\n", buscar->cpf);
                    imprimirPessoa(*buscar);
                } else {
                    printf("\tCPF não encontrado...\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            default:
                printf("\tOpcao Invalida...\n");
        }
    } while (opcao != 0);

    return 0;
}