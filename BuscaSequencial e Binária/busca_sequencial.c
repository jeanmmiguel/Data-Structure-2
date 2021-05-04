#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int *v, int n, int x){

 int i;

 for( i = 0; i < n; i ++){
     if(v[i] == x){
         return i;
     }
 }

 return -1;

}

void main(){

int v[] = {1,2,3,4,5,6};
int teste = busca_sequencial(v,5,10);
if(teste == -1){
    printf("elemento não encontrado no vetor");
}else{
    printf("O elemento está na posição %d",teste);
}



}