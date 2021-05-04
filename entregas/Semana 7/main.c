#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_ea.h"
#define N 10000
#define SEED 42
#define MAX N*10

int main(int argc, char** argv){
  
 THEA* t;
  int* valores_aleatorios;
  int i, M;
  M = 30000;

 valores_aleatorios = random_vector(N, MAX, SEED);  


  printf(" M = %d \n", M);
  t = THEA_Criar(M);

  for (i = 0; i < N; i++) {
    THEA_Inserir(t, valores_aleatorios[i], valores_aleatorios[i]);
  }

  printf("N: %d\n", t->n);
  printf("Custo médio de uma busca mal sucedida: %f\n", THEA_TamMedioClusters(t));
  printf("Custo médio de uma busca bem sucedida: %f\n", THEA_CustoBemSucedida(t));
  printf("Maior cluster : %d\n", THEA_ClusterMaximo(t));
  printf("Fator de carga: %f\n", (float) t->n/t->m);

  free(t);
 
  return 0;

}