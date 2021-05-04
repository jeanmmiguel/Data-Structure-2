#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int* random_vector(int n, int max, int seed){
int *v = (int*) malloc(n * sizeof(int));
int i;
srand(seed);
    for(i = 0; i < n;i++){
        v[i] = rand() % max;
    }

return v;
}
void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i <= n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void merge(int *v, int p, int q, int r){


 int *e,*d;
 int i ,j ,k;
 int n1 =  q - p +1;
 int n2 = r - q;
 int count = 0;

 
 e = malloc(sizeof(int) * (n1 + 1));
 d = malloc(sizeof(int)*(n2 + 1));

 
     memcpy(e,&v[p],sizeof(int) * n1 );
     
     e[n1] = INT_MAX;
     memcpy(d,&v[q+1], sizeof(int) * n2 );
         d[n2] = INT_MAX;
         i = 0;
         j = 0;
        for( k = p; k <= r ; k++){
             if(e[i] <= d[j]){
                 v[k] = e[i];
                 i++;
             }else{
                 v[k] = d[j];
                 count++;
                 j++;
             }
         }
     
free(e);
free(d);

}

void mergeSort(int *v,int e, int d){

    int meio;
    int total;

    if(e < d){
        meio =  (e + d) / 2;
        mergeSort(v,e,meio);
        mergeSort(v,meio+1,d);
        merge(v,e,meio,d);
    }

}



void main(){

clock_t t;
int n = 1000;
int m = 100;
int *v = random_vector(n,n*m,0);

 t = clock();
 mergeSort(v,0,n);
 t = clock() - t; //tempo final - tempo inicial
 printf (" [%f] segundos.\n\n",((float)t)/CLOCKS_PER_SEC);


}


