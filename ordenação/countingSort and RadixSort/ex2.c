#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

typedef struct {
    int dado;
    int chave;
}info;
info* random_vector(int n, int max, int seed);

int max(info *v,  int n){

int i = 0, aux = 0, maior = v[0].chave;

for(i = 1; i < n;i++){
    if(maior < v[i].chave){
        maior = v[i].chave;

    }
}

return maior;
}


void imprime_vetor(info*v, int n){
 int i, k;
 printf("dado  -> ");
 for(i = 0; i < n;i++){
     printf("%d  ",v[i].dado);
    }
    printf("\n");
printf("chave -> ");
 for(k = 0; k < n;k++){
     printf("%d  ",v[k].chave);

 }
    printf("\n");
 


}

info* random_vector(int n, int max, int seed){

info *v = (info*) malloc(n * sizeof(info));
int i, k ;
srand(seed);

    for(i = 0; i < n;i++){
        v[i].dado = rand() % max;
        v[i].chave = rand() % max;
    }

return v;

}

void counting_sort(info *v, int n, int  div, int base, info *temp){

 int i, t, c[base], acum = 0;

 memset(c ,0, base *  sizeof(int)); // funcao p/ atribuir mesmo valor para varios bytes na memoria -> zerar o vetor C 
 #define DIGIT(X)  (X / div ) % base


 for( i = 0; i < n; i ++){
     c[DIGIT(v[i].chave)]++;
 }
 //soma de prefixo

 for(i = 0; i< base; i ++){
     t = c[i];
     c[i] = acum;
     acum += t;
 }

    for(i = 0; i < n; i ++){
        temp[c[DIGIT(v[i].chave)]] = v[i];
        c[DIGIT(v[i].chave)]++;

     }

 memcpy(v , temp, sizeof(info) * n );


}



void radix_sort(info* v, int n){

 int k, div = 1;
 k = max(v,n);
 info *temp = malloc(sizeof(info) * n);

 while(k > 0){
     counting_sort(v, n, div, 10, temp);
     div *= 10;
     k /=10;

 }


 free(temp);



}

void main(){
int n = 10;
int m;
info *v = random_vector(n,10,0);

 clock_t t;
 t = clock();
 radix_sort(v,n);
 imprime_vetor(v,n);


 t = clock() - t; //tempo final - tempo inicial
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double



}