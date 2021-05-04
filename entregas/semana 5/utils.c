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
int min(int *v, int inicio, int final){

int i = 0, aux = 0, menor = v[inicio];

for(i = inicio; i <= final;i++){
    if(v[i] < v[menor]){
        aux = i;
        i = menor;
        menor = aux;

    }
}
return menor;
}



int SelectionMinK(int *v, int n, int k){


  if(k > n) return v[max(v,0 ,n)];

  int j = k, maior;
  

  for(int i = 0; i < n; i++){
     maior = max(v,0,n);
    troca(v, maior, i);
    j--;
    if(j == 0) break;
  }

  return v[k-1];
}




int HeapMinK(int *v, int n, int k){

 
 int j = k-1;

 if(j > n) return v[max(v,0,n)];

 buildMinHeap(v, n);
 
 while(j > 0){
  troca(v, 0, n-1);
  buildMinHeap(v, --n);
  j--;
     
 }
  return v[0];
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
 
  int aux = k-1, q;
  
  if(aux > d) return v[max(v,0, d)];
  
  
  if(e < d){
    q = partition(v, e, d);
    
    if(q < aux) return QuickMinK(v, q+1, d, k);
    if(q > aux) return QuickMinK(v, e, q-1, k);
    if(q == aux) return v[k-1];

  }
  return v[aux];
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
        v[i] = rand() % (n *100);
    }
embaralhar(v,0,n);


return v;
}