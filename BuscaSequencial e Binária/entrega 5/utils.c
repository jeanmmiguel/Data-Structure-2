#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"

void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void troca(int *v,int menor,int i){
    int aux;

    aux = v[menor];
    v[menor] = v[i];
    v[i] = aux;


}

int esquerda(int i){

 return 2 * i + 1;
}
int direita(int i){

 return 2 * i + 2;
 }
int max(int *v, int inicio, int final){

int i = 0, aux = 0, maior = inicio;

for(i = inicio; i <= final;i++){
    if(v[i] > v[maior]){
        aux = i;
        i = maior;
        maior = aux;

    }
}

return maior;
}


int SelectionMinK(int *v, int n, int k){

int i,maior, aux, temp;


if(n >= k){
    for(i = n - 1 ; i > 0 ; i--){
        maior = max(v,0,i);
        troca(v,maior,i);
        temp = v[k - 1];
     }
return temp;

}if(n < k){
 aux = max(v,0,n);
 return aux;

}

return  0 ;

}


int HeapMinK(int *v, int n, int k){

 
    int i, temp, aux;
    buildMinHeap(v,n);
    for(i = n -1; i > 0; i --){
        troca(v,0,i);
        minHeapify(v,0,i);
        temp = v[n - k];

    }
    imprime_vetor(v,n);
    
    if(n >= k)
    return temp;

    if(n < k){
        aux = max(v,0,n);
       return v[aux];
    }



}
void minHeapify(int *v,int i, int th){

 int e, d;
 int menor = i;

 e = esquerda(i);
 d = direita(i);

 if((e < th) && (v[e] < v[i]))
 menor = e;

 if((d < th) && (v[d] < v[menor]))
 menor =  d;

    if(menor != i){
        troca(v,i,menor);
       minHeapify(v,menor,th);
    }

}

void buildMinHeap(int *v, int n){

 int i ; 

    for(i = n /2 ; i >= 0;i --){
        minHeapify(v,i,n);
    }

}
int partition(int *v,int p, int r){

int x;
int i, j ;
x = v[r];
i = p - 1;

for( j = p ; j < r;j++){
    if(v[j] <= x){
        i++;
        troca(v,i,j);
    }
}
troca(v,i + 1,r);
return i + 1;


}

 int QuickMinK(int *v, int e, int d, int k){
 int q, aux = 0, temp, i;
 int total = d + 1;

 
   
        if(e < d){
            
             q = partition(v,e,d);
            QuickMinK(v,e,q-1,k);
            QuickMinK(v,q+1,d,k);
            temp = v[k-1];
        }
    if(total >= k)
    return temp;

   if(total < k){
       aux = max(v,0,d);
       return v[aux];
   }
  
 }


void embaralhar(int *v, int ini, int fim){
int i, j;
    for(i = fim-1; i > ini; i--){
        j = (rand() % (i + 1));
        j = j <= ini? ini+1 : j;
        troca(v, i, j);
    }

}


 int* random_vector_unique_elems(int n, int seed){

int *v = (int*) malloc(n * sizeof(int));
int i;
srand(seed);
    for(i = 0; i < n;i++){
        v[i] = rand() % n;
    }
embaralhar(v,0,n);


return v;
}