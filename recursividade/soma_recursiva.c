#include <stdio.h>
#include <stdlib.h>

int soma (int n){

    if (n == 0)
        return 0;
    else    
        return n + soma(n-1);

}

int main (){

int x = soma(4);
printf("%d",x);

}