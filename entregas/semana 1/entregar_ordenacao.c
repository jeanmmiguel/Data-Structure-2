#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime_vetor();
int max();
void troca();
void selection();
int insertion();
int insertionSort();
int bubbleSort(int *v, int n);
int* random_vector(int n, int max, int seed);


int* random_vector(int n, int max, int seed){
int *v = (int*) malloc(n * sizeof(int));
int i;
srand(seed);
    for(i = 0; i < n;i++){
        v[i] = rand() % max;
    }

    return v;


}

int selectionSORT(int *v, int n){
    int j, i , menor, troca, count = 0;

    for(i = 0; i < n-1; i ++){
        menor = i;
        for(j = i+1; j <n;j++){
            count++;
            if(v[j]<v[menor])
            menor = j;
        }
        if(i !=menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }

return count;


}
int max(int *v, int inicio, int final, int *count){
int maior = inicio;
int i;
    for(i = inicio; i <= final; i++){
        (*count)++;
        if(v[i] > v[maior])
            maior = i;
    }
   return maior;
}
void troca(int *v,int maior,int i){
    int aux;
    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;

}

void selection(int *v, int n){
    int i;
    int maior, t = 0;
    int teste = 0;
    for(i = n - 1; i > 0; i --){
        maior = max(v,0,i,&t);
        troca(v,maior,i);
    }
    printf("\n");
    imprime_vetor(v,n);
   

}
void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
int bubbleSort(int *v,int n){

    int i, j ;
    int cont = 0;
    for(j = n - 1; j > 0;j --){
        for(i = 0; i < j;i ++){
            if(v[i] > v[i+1]){
             troca(v,i,i + 1);
             }
         cont++;
        }
    
    }
return cont;
imprime_vetor(v,n);

}
int insertion(int *v, int k){

int i = k- 1;
int x = v[k];
    int count = 0;
    while((i >= 0 ) && v[i] > x){
        count++;
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = x;

    return count;

}
int insertionSort(int *v, int n){

    int j,  count = 0 ;
    for(j= 1; j < n; j++){
        count+=insertion(v,j);

    }

    return count;
}


void main(){

int *v = random_vector(10000,100000,0);
//imprime_vetor(v,10);
 clock_t t;
 t = clock();
 //int x = bubbleSort(v,10000);
 //int y = insertionSort(v,10000);
//int s = max(v,0,100,&count);
//selection(v,100);
int count = selectionSORT(v,10000);
printf("count %d \n",count);

 t = clock() - t; //tempo final - tempo inicial
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double



}
