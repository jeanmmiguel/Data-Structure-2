
//Altere os algoritmos de ordenação por seleção, bolha, e inserção apresentados nos vídeos 1, 2 e 3 de forma
//que os vetores resultantes estejam ordenados em ordem decrescente.

#include <stdio.h>
#include <stdlib.h>
void imprime_vetor();
int max();
void troca();
void selection();
void insertion();
void insertionSort();

int max(int *v, int inicio, int final){

int i = 0, aux = 0, maior = inicio;

for(i = inicio; i <= final;i++){
    if(v[i] < v[maior]){
        aux = i;
        i = maior;
        maior = aux;

    }
}

return maior;
}

void troca(int *v,int maior,int i){
    int aux;

    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;


}

void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void selection(int *v, int n){
    int i;
    int maior;

    for(i = n - 1; i > 0; i --){
        maior = max(v,0,i);
        troca(v,maior,i);
    }

    imprime_vetor(v,n);
}

void bubbleSort(int *v,int n){

    int i, j ;

    for(j = n - 1; j > 0;j --){
        for(i = 0; i < j;i ++){
            if(v[i] < v[i+1]){
                troca(v,i+1,i);
            }
        }
    }

     imprime_vetor(v,n);


    
}
void insertion(int *v, int n){

int i = n- 1;
int x = v[n];

    while((i >= 0 ) && v[i] < x){
        v[i + 1] = v[i];
        i--;
    }
    v[i +1] = x;
    
}
void insertionSort(int *v, int n){

    int j;

    for(j= 1; j < n; j++){
        insertion(v,j);
    }
    imprime_vetor(v,n);

}


void main(){

int x;
int v[] = {100,50,2,66,300,200};
//x = min(v,0,6);
//printf("maior posicao do vetor é %d\n ",x);

//selection(v,6); // ok
//insertionSort(v,6);
bubbleSort(v,6);





}