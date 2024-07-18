// Operação Matemática

#include <stdio.h>

int operacaoMatematica(int a, int b){
    int r;

    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void){
    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    int res = operacaoMatematica(num1, num2);

    printf("A operação de %d e %d é: %d\n", num1, num2, res);

    return 0;
}

/*
b) Descubra através da depuração, qual a maior profundidade de (frames) esse código alcança.
    A maior profundidade nesse código é depentende da entrada dada pelo o usuário. Como segue a compilação abaixo:
    
    (gdb) b operacaoMatematica
    Ponto de parada 1 at 0x1197: file ex_1_quest_2.c, line 8.
    (gdb) b main
    Ponto de parada 2 at 0x11c6: file ex_1_quest_2.c, line 16.
    (gdb) run
    Starting program: /home/allan/Estruturas_II/exercicios/ex_1_quest_2 
    [Thread debugging using libthread_db enabled]
    Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

    Breakpoint 2, main () at ex_1_quest_2.c:16
    16      int main(void){
    (gdb) n
    19          printf("Digite o primeiro número: ");
    (gdb) n
    20          scanf("%d", &num1);
    (gdb) n
    Digite o primeiro número: 8
    22          printf("Digite o segundo número: ");
    (gdb) n
    23          scanf("%d", &num2);
    (gdb) n
    Digite o segundo número: 1
    25          int res = operacaoMatematica(num1, num2);
    (gdb) n

    Breakpoint 1, operacaoMatematica (a=8, b=1) at ex_1_quest_2.c:8
    8           while(b != 0){
    (gdb) n
    9               r = a % b;
    (gdb) n
    10              a = b;
    (gdb) n
    11              b = r;
    (gdb) n
    8           while(b != 0){
    (gdb) n
    13          return a;
    (gdb) n
    14      }
    (gdb) n
    main () at ex_1_quest_2.c:27
    27          printf("A operação de %d e %d é: %d\n", num1, num2, res);
    (gdb) n
    A operação de 8 e 1 é: 1
    29          return 0;
    (gdb) n
    30      }
    (gdb) n

c) Descubra o que ocorre quando um parâmetro é 0.
    O resultado da operação vai ser o valor que não está nulo (com o valor 0)
*/