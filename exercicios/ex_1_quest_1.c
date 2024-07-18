// Fibonacci

#include <stdio.h>
int fibonacci(int n){
    if(n <= 1){
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(void){
    fibonacci(15);

    return 0;
}

/*
a) Depure o código para descobrir quantas vezes o fibonacci(5) é calculado (requisitado).
    O fibonacci(5) após depurado o código é requisitado 89 vezes
b) Descubra através da depuração, qual a maior quantidade de níveis (frames) esse código alcança.
*/