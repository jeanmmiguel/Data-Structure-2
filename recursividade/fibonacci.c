#include <stdio.h>
 
// Implementação da Série de Fibonacci
 
int main(void) { 
    
    int a = 0, b = 1, i , aux, n ;

   printf("Informe o valor:");
   scanf("%d",&n);

    if(n>=1){
        printf("%d\n",a);
    }
    if(n>=0){
       printf("%d\n",b);

    }

   for(i = 2;i <= n;i++){
       aux = a + b;
       a = b;
       b = aux;

       printf("%d\n",aux);
   }
}