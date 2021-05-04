#include <stdio.h>
#include<stdlib.h>
#include <limits.h>



void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i <= n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
mergesort(int *v, int n){

 int *e,*d;
 int tam1 = (n/2) + 1;
 int tam2 = (n/2) - 1;

 e = malloc(sizeof(int) * (tam1 + 1));
 d = malloc(sizeof(int)*(tam2 + 1));

merge(v,e,d,tam1,tam2,n);


free(e);
free(d);


}
void merge(int *v,int* e, int* d, int p, int q, int r){


 int i,j,k;
 int n1 =  q - p +1;
 int n2 = r - q;
 int count = 0;



 for(i = 0; i< n1;i++)
     e[i] = v[p + i];
     e[n1] = INT_MAX;
     for(j = 0; j < n2;j++)  
        d[j] = v[q+1+j];
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

int v[] = {3,2,4,0,1,7};
int a =  mergeSort(v,0,5);
printf(" contador vale %d\n",a);
imprime_vetor(v,5);


}


