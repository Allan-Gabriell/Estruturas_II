#include <stdio.h>

int bissexto(int);

int main(void){
    int ano = 1900;
    if(bissexto(ano) == 1){
        printf("Bissexto\n");
    }

    return 0;
}

int bissexto(int ano){
    if(ano%4 == 0 && ano%100 == 0){
        if(ano%400 == 0){
            return 1;
        }
        return 0;
    }
    if(ano%4 == 0){
        return 1;
    }
}

// int bissexto(int ano){
//     if(ano == 1984){
//         return 1;
//     } else if(ano < 1984){
//         return 0;
//     }
//     return bissexto(ano-4);
// }