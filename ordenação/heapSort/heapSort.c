#include<stdio.h>
#include<stdlib.h>


int esquerda(int i){

 return 2 * i + 1;



}
int direita(int i){

 return 2 * i + 2;
 


}


void troca(int *v,int maior,int i){
    int aux;
    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;

}
void maxHeapify(int *v,int i, int th){

 int e, d;
 int maior = i;

 e = esquerda(i);
 d = direita(i);

 if((e < th) && (v[e] > v[i]))
 maior = e;

 if((d < th) && (v[d] > v[maior]))
 maior =  d;

 if(maior!= i){
     troca(v,i,maior);
     maxHeapify(v,maior,th);
 }

}

void buildMaxHeap(int *v, int n){

 int i ; 

 for(i = n /2; i > 0;i --){
     maxHeapify(v,i,n);
 }


}
void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void HeapSort(int* v, int n){

    int i;
    buildMaxHeap(v,n);
    for(i = n -1; i > 0; i --){
        troca(v,0,i);
        maxHeapify(v,0,i);
    }

    imprime_vetor(v,n);

}




void main(){

int v[] = {7,5,9,6,1,0};
HeapSort(v,6);



}