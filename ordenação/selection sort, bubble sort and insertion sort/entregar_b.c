#include <stdio.h>
#include <stdlib.h>



void troca(int *v,int maior,int i){
    int aux;

    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;


}
int bubbleSort(int *v,int n){

    int i, j ;
    int cont = 0;
    for(j = n - 1; j > 0;j --){
        for(i = 0; i < j;i ++){
            if(v[i] > v[i+1]){
             troca(v,i,i + 1);
            }
        }
    cont++;

    }

return cont;
}

void main(){

int v[] = {2,5,7,9,10,11};
int x = bubbleSort(v,6);
printf("contador %d",x);



}