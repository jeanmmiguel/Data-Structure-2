#include <stdio.h>
#include "utils.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define PRINT_DEBUG 1

void main(){
int n =  1000000;
int m = n * 100;
int *v = random_vector(n,m ,0);

#ifdef PRINT_DEBUG
  print_vetor(v,n);
#endif

 clock_t t;
 t = clock();
 radix_sort_base10(v,n);
 t = clock() - t; //tempo final - tempo inicial
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 

 free(v);

}