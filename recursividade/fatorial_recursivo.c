#include <stdio.h>
#include <stdlib.h>

int fat (int n){

if (n == 0)
    return 1;
else
    return n*fat(n-1);


}

int main (){
    int x = fat(4);
    printf("%d",x);


}