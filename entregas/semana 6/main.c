#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_encadeamentoDireto.h"
#include "ilist.h"
#include <time.h>

void main (int argc, char** argv){

int m = 10 , n = 100;
int seed = 42;

THED* th;

th = inserir_n_aleatorios(n,m,seed);
imprimir_THED(th);

int maior, menor;
float media;
maior = THED_maisLonga(th);
printf("maior %d\n",maior);
menor = THED_maisCurta(th);
printf("menor %d\n",menor);
media = THED_TamMedio(th);
printf("media %.3f\n",media);




//maior = max(th);
//menor = min(th);
//printf("maior chave é %d\n", maior);
//printf("menor chave é %d\n", menor);




}