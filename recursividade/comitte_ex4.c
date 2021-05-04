#include <stdio.h>
#include <stdlib.h>



int C(int n, int k){

if(k > n) return 0;
if(k == 1) return n;

else
return C(n -1,k) + C (n-1, k - 1 );
}

void main(){

int x ;
x = C(5,3);
printf("%d",x);


}



