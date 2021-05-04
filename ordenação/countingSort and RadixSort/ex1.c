#include <stdio.h>
#include <stdlib.h>
#include<time.h>


typedef struct {
    int dado;
    int chave;
}info;
info* random_vector(int n, int max, int seed);


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

void main(){
int n = 1000;
int m;
info *v = random_vector(n,n * 100,0);
imprime_vetor(v,10);

 clock_t t;
 t = clock();
 

 t = clock() - t; //tempo final - tempo inicial
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double



}