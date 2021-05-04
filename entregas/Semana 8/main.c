#include <stdio.h>
#include <stdlib.h>
#include "prime_list.h"
#include "hashtable_ea.h"
#include <time.h>


void main(){
 int m = 5, seed = 42,chave;
 int n = 1000000;  
 
  THEA* TH;

  TH = THEA_Random(m, n, 10*n, seed, P_LINEAR);
  printf("linear: %d\n", TH->colisoes);
  
  TH = THEA_Random(m, n, 10*n, seed, P_QUADRATICA);
  printf("quadrática: %d\n", TH->colisoes);
  TH = THEA_Random(m, n, 10*n, seed, P_DUPLA);
  printf("dupla: %d\n", TH->colisoes);
  

  
  


 }