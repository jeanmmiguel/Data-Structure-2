#include <stdio.h>
#include "utils.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define PRINT_DEBUG 1

void main(){
int n =  35;
int v[] = {5,0,1,4,2,9,8,10};

//int *v = random_vector_unique_elems(n,0);

#ifdef PRINT_DEBUG
  imprime_vetor(v,4);
#endif


//buildMinHeap(v,4);
//int x = SelectionMinK(v,4,4);
//minHeapSort(v,4);
//int x = QuickMinK(v,0,34,1);
int x = HeapMinK(v,8,3);
printf("O k-ésimo menor valor é %d\n",x);
 clock_t t;
 t = clock();
 t = clock() - t; //tempo final - tempo inicial
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 

 //free(v);

}


