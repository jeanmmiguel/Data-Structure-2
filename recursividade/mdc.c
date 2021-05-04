#include <stdio.h>

int mdc(int x , int y){

if(((x <= y) && (x%y == 0))) return y;

if(x < y){
     mdc(y,x);
}
else return mdc(y,x%y);

}

void main(){

    int x ;
    x = mdc(30,42);
    printf("%d",x);
}