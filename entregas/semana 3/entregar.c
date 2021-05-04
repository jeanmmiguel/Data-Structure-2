#include<stdio.h>
#include<stdlib.h>
#include "entrega3.h"


int main(){

 FilaPrioridade* fi = filaP_criar();
 /*
  filaP_inserir(fi,7);
  filaP_inserir(fi,4);
  filaP_inserir(fi,10);
  filaP_inserir(fi,9);
  filaP_inserir(fi,8);

filaP_imprimir(fi);

*/
int v[] = {2,8,20,9,30};
int x = FP_inicio(v,5);
printf("%d",x);




}
