#include <stdio.h>



int funcRecursiva(int n){
    if(n==0){
        return 1;
    }

    return funcRecursiva(n-1)+ 1/funcRecursiva(n-1);
}

int main(void){
    funcRecursiva(5);

}