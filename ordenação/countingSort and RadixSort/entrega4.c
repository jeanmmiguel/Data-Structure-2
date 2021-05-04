#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int* random_vector(int n, int max, int seed){

int *v = (int*) malloc(n * sizeof(int));
int i, k ;
srand(seed);

    for(i = 0; i < n;i++){
        v[i] = rand() % max;
        
    }

return v;

}


void imprime_vetor(int *v, int n){
 int i;
 for(i = 0; i < n;i++){
     printf("%d  ",v[i]);
    }


    printf("\n");
 
}
int max(int *v,  int n){

int i = 0, aux = 0, maior = v[0];

for(i = 1; i < n;i++){
    if(maior < v[i]){
        maior = v[i];

    }
}

return maior;
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

void main(){
int n =  1000000;
int m = n * 100;
int *v = random_vector(n,m ,0);

 clock_t t;
 t = clock();
 radix_sort_base10(v,n);
 t = clock() - t; //tempo final - tempo inicial
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 

 free(v);

}