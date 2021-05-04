#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
/*O algoritmo Merge estudado é eficiente no sentido que faz a intercalação de dois vetores em tempo linear.
Entretanto, o custo dele para intercalar dois vetores unitários é maior que simplesmente trocar os elementos
caso não estejam em ordem. Modifique o algoritmo de Merge Sort (do vídeo) para que intercale dois vetores
unitários usando uma troca simples caso necessário. Compare o tempo para ordenar 100000 elementos
aleatórios usando o algoritmo original (do vídeo) e o algoritmo modificado.*/


void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i <= n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int merge(int *v, int p, int q, int r){


 int *e,*d;
 int i,j,k;
 int n1 =  q - p +1;
 int n2 = r - q;
 int count = 0;

 e = malloc(sizeof(int) * (n1 + 1));
 d = malloc(sizeof(int)*(n2 + 1));

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
     
free(e);
free(d);
return count;

}

int mergeSort(int *v,int e, int d){

    int aux = 0;
    int meio;
    int total;

    if((d - e) > 2){
        meio =  (e + d) / 2;
        mergeSort(v,e,meio);
        mergeSort(v,meio+1,d);
        merge(v,e,meio,d);
    } else if( (d -e ) ==2 ){
        
        if(v[e] > )
        
    }


    }

    return total;
}



void main(){

int v[] = {3,2,7,9,0,1,0,2,55,78};
int a =  mergeSort(v,0,9);
printf(" contador vale %d\n",a);
imprime_vetor(v,9);


}


