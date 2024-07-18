//Números Primos

#include <stdio.h>

//função recursiva para verificar se um número é primo
int ehPrimoRecursivo(int n, int i){
    if(n <= 2){
        return (n == 2);
    }

    if(n % i == 0){
        return 0;
    }

    if(i * i > n){
        return 1;
    }

    return ehPrimoRecursivo(n, i + 1);
}

//função para imprimir números em um intervalo
void imprimirPrimosIntervalo(int inicio, int fim){
    if(inicio > fim){
        return;
    }

    if(ehPrimoRecursivo(inicio, 2)){
        printf("%d", inicio);
    }

    imprimirPrimosIntervalo(inicio + 1, fim);
}

int main(void){
    int inicio, fim;

    printf("Digite o inicio do intervalo: ");
    scanf("%d", &inicio);

    printf("Digite o fim do intervalo: ");
    scanf("%d", &fim);

    printf("Números primos entre %d e %d: ", inicio, fim);
    imprimirPrimosIntervalo(inicio, fim);
    printf("\n");

    return 0;
}