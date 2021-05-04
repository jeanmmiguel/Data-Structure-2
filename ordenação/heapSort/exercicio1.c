/*Exercícios Complementares
1. A função int MaxK(int *V, int n, int k) recebe um vetor V (considere-o desornenado) de tamanho n, e um
inteiro k. Esta função deve retornar o k-ésimo maior valor distindo do vetor V. O vetor pode ter repetições.
Por exemplo, para k=2 e V = [0,0,4,5], MaxK retorna 4. Caso o vetor não possua k elementos distintos,
retorne o maior valor de todos. Utilize uma heap máxima para implementar MaxK.
*/
int esqerda(int i );
int direita(int i);
void troca(int* v,int maior, int i);
void maxHeapify(int *v,int i, int th);
int maxK( int *v, int n , int k);


int maxK(int *v, int n, int k){





    
}

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