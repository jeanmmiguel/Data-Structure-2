#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int dado;
    int chave;
}info;


void counting_sort(int *v, int n, div, int base, int *temp){

 int i, t, c[base], acum = 0;

 memset(c ,0, base *  sizeof(int)); // funcao p/ atribuir mesmo valor para varios bytes na memoria
 
 #define DIGIT(x) (x / div ) % base

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



void radix_sort(int* v, int n){

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