#include <stdio.h>
#include <stdlib.h>




int sucessor (int x){

return x+ 1;



}
int soma(int a,int b){
    if(a == 0)
    return sucessor(b);
    if(b == 0)
    return sucessor(a);

    else{
      return soma(a, 0) + soma(0,b);
    }


}




void main(){

int resul ;
resul = soma(9,5);
printf("%d",resul);


}