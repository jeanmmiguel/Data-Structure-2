#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <string.h>
int max(int *v,  int n){

int i = 0, aux = 0, maior = v[0];

for(i = 1; i < n;i++){
    if(maior < v[i]){
        maior = v[i];

    }
}

return maior;
}

int* random_vector(int n, int max, int seed){
int *v = (int*) malloc(n * sizeof(int));
int i, k ;
srand(seed);

    for(i = 0; i < n;i++){
        v[i] = rand() % max;
        
    }

    return v;



}
void print_vetor(int *v, int n){
    int i;
 for(i = 0; i < n;i++){
     printf("%d  ",v[i]);
    }


    printf("\n");

}

void troca(int *v,int maior,int i){
    int aux;
    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;

}

void counting_sort(int *v, int n, int pos, int base, int *temp){

 int i, t, c[base], acum = 0;

 memset(c ,0, base *  sizeof(int)); // funcao p/ atribuir mesmo valor para varios bytes na memoria
 
 #define DIGIT(x) (x / pos ) % base // utilizar essa fórmula para a função da base decimal
 //#define DIGIT(x) (x >> pos ) & 1 // utilizar essa fórmula para a função da base binária
 for( i = 0; i < n; i ++){
     c[DIGIT(v[i])] ++;
 }
 //soma de prefixo

 for(i = 0; i< base; i ++){
     t = c[i];
     c[i] = acum;
     acum += t;
 }

 for(i = 0; i < n; i ++){
     temp[c[DIGIT(v[i])]] = v[i];
     c[DIGIT(v[i])]++;
 }

 memcpy(v , temp, sizeof(int) * n );


}
void radix_sort_base10(int* v, int n){

 int k, div = 1;
 k = max(v,n);
 int *temp = malloc(sizeof(int)* n);

 while(k > 0){
     counting_sort(v, n, div, 10, temp);
     div*= 10;
     k /=10;

 }

 free(temp);

}
void radix_sort_base2(int* v, int n){

 int k, count = 0;
 k = max(v,n);
 int *temp = malloc(sizeof(int)* n);

 while(k > 0){
     counting_sort(v, n, count, 2, temp);
      count++;
      k /=2;

 }
//imprime_vetor(v,n);

 free(temp);

}