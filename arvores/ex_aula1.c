#include <stdio.h>

int fumcp(int);
int funcp(int, int);
int main(void){

}
int fumcp(int n){
    funcp(n, 1);
}

int funcp(int n, int x){
    if(n==-1){
        return x;
    }
    funcp(n-1, x*n);
}