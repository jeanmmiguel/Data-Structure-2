#include <stdio.h>
#include<stdlib.h>
#include <limits.h>


void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i <= n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void troca(int *v,int maior,int i){
    int aux;
    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;

}

int partition(int *v,int p, int r){

int x;
int i, j ;
x = v[r];
i = p - 1;

for( j = p; j < r;j++){
    if(v[j] <= x){
        i++;
        troca(v,i,j);
    }
}
troca(v,i + 1,r);
return i + 1;


}

void quickSort(int *v, int e , int d){
    int q ;

    if(e < d ){
        q = partition(v,e,d);
        quickSort(v,e,q-1);
        quickSort(v,q+1,d);


    }
}



void main(){

int v[] = {1,2,0,3,4,5};
quickSort(v,0,5);
imprime_vetor(v,5);


}
