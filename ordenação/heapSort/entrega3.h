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
void imprimir_vetor(int *v,int n){

	int i;

	for(i = 0;i<n;i++){
		printf("%d ",v[i]);
	}
	printf(" \n");
}


void HeapSort(int* v, int n){

    int i;
    buildMaxHeap(v,n);
    for(i = n -1; i > 0; i --){
        troca(v,0,i);
        maxHeapify(v,0,i);
    }


}


int FP_inicio(int* fp, int n){


return fp[0];

 
    
}
int FP_remover_maximo(int* fp, int n){

}

int FP_inserir(int* fp, int n, int x){

}

int main(){

int v[] = {2,8,20,9,30};
buildMaxHeap(v,5);
int x = FP_inicio(v,5);
printf("%d",x);

}