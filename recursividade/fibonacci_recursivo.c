#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){

if(n == 0 || n == 1)
    return n;
else
return fibonacci(n-1) + fibonacci(n-2);

}

void main (){

    int x;
    x = fibonacci(7);
    printf("%.1d\n",x);


    
}

