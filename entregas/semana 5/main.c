#include <stdio.h>
#include "utils.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define PRINT_DEBUG 0

void main(){
int n=500000;


int *v = random_vector_unique_elems(n,42);

#ifdef PRINT_DEBUG
  //imprime_vetor(v,8);
#endif


//buildMinHeap(v,4);
//minHeapSort(v,4);

 clock_t t;
t = clock();
//int x = QuickMinK(v,0,n,n);
//int x = SelectionMinK(v,n,n);
int x = HeapMinK(v,n,n);
printf("O k-ésimo menor valor é %d\n",x);

 t = clock() - t; //tempo final - tempo inicial
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 

 //free(v);

}


